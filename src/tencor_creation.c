#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "attributes.h"
#include "require.h"
#include "arithmetic.h"
#include <string.h>

TENCOR_NODISCARD
static usz tencorCountElements(usz ndim, const usz *shape)
{
    Require(ndim == 0 || shape != NULL, "%s", "shape is NULL");
    Require(ndim <= SIZE_MAX / (2 * sizeof(usz)), "%s", "ndim is too large");

    usz nelem = 1;
    for (usz i = 0; i < ndim; i++)
    {
        Require(shape[i] > 0, "shape[%zu] is 0 (zero-sized dimensions are not supported)", i);
        Require(UszMul(nelem, shape[i], &nelem), "%s", "tensor has too many elements");
    }
    return nelem;
}

TENCOR_NODISCARD
static Tencor *tencorAllocHeader(TencorArena *arena, usz ndim, const usz *shape, usz nelem, f32 *data)
{
    usz dimsNbytes, headerNbytes;
    Require(UszMul(ndim, 2 * sizeof(usz), &dimsNbytes), "%s", "ndim is too large");
    Require(UszAdd(sizeof(Tencor), dimsNbytes, &headerNbytes), "%s", "ndim is too large");

    Tencor *tencor = TencorArenaAlloc(arena, headerNbytes);
    usz *shapeOut = (usz *)(tencor + 1);
    usz *stridesOut = shapeOut + ndim;

    for (usz i = 0; i < ndim; i++)
        shapeOut[i] = shape[i];

    usz stride = 1;
    for (usz i = ndim; i-- > 0;)
    {
        stridesOut[i] = stride;
        stride *= shapeOut[i];
    }

    *tencor = (Tencor){
        .data = data,
        .ndim = ndim,
        .nelem = nelem,
        .shape = shapeOut,
        .strides = stridesOut,
    };
    return tencor;
}

Tencor *TencorCreate(TencorArena *arena, usz ndim, const usz *shape)
{
    RequireNonNull(arena, "%s", "arena is NULL");

    usz nelem = tencorCountElements(ndim, shape);

    usz dataNbytes;
    Require(UszMul(nelem, sizeof(f32), &dataNbytes), "%s", "tensor is too large");

    f32 *data = TencorArenaAllocAligned(arena, dataNbytes, TENCOR_DATA_ALIGNMENT);
    return tencorAllocHeader(arena, ndim, shape, nelem, data);
}

Tencor *TencorZeros(TencorArena *arena, usz ndim, const usz *shape)
{
    Tencor *tencor = TencorCreate(arena, ndim, shape);
    memset(tencor->data, 0, tencor->nelem * sizeof(*tencor->data));
    return tencor;
}

Tencor *TencorOf(TencorArena *arena, usz ndim, const usz *shape, float value)
{
    Tencor *tencor = TencorCreate(arena, ndim, shape);

    for (usz i = 0; i < tencor->nelem; ++i)
        tencor->data[i] = value;

    return tencor;
}

Tencor *TencorOnes(TencorArena *arena, usz ndim, const usz *shape)
{
    return TencorOf(arena, ndim, shape, 1.0f);
}
