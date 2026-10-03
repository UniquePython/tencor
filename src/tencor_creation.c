#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"
#include "arithmetic.h"
#include <string.h>

Tencor *TencorCreate(TencorArena *arena, usz ndim, const usz *shape)
{
    RequireNonNull(arena, "%s", "arena is NULL");
    Require(ndim == 0 || shape != NULL, "%s", "shape is NULL");

    usz nelem = 1;
    for (usz i = 0; i < ndim; i++)
    {
        Require(shape[i] > 0, "shape[%zu] is 0 (zero-sized dimensions are not supported)", i);
        Require(UszMul(nelem, shape[i], &nelem), "%s", "tensor has too many elements");
    }

    usz dimsNbytes, headerNbytes, dataNbytes;
    Require(UszMul(ndim, 2 * sizeof(usz), &dimsNbytes), "%s", "ndim is too large");
    Require(UszAdd(sizeof(Tencor), dimsNbytes, &headerNbytes), "%s", "ndim is too large");
    Require(UszMul(nelem, sizeof(f32), &dataNbytes), "%s", "tensor is too large");

    Tencor *tencor = TencorArenaAlloc(arena, headerNbytes);
    usz *outShape = (usz *)(tencor + 1);
    usz *outStrides = outShape + ndim;

    for (usz i = 0; i < ndim; i++)
        outShape[i] = shape[i];

    usz stride = 1;
    for (usz i = ndim; i-- > 0;)
    {
        outStrides[i] = stride;
        stride *= outShape[i];
    }

    f32 *data = TencorArenaAllocAligned(arena, dataNbytes, TENCOR_DATA_ALIGNMENT);

    *tencor = (Tencor){
        .data = data,
        .ndim = ndim,
        .nelem = nelem,
        .shape = outShape,
        .strides = outStrides,
    };
    return tencor;
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
