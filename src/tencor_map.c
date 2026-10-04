#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"

void TencorUnaryMapInto(Tencor *out, const Tencor *tencor, TencorUnaryFn function, void *context)
{
    RequireNonNull(function, "%s", "unary function is NULL");
    TencorRequireUnary(out, tencor);

    f32 *outData = out->data;
    const f32 *inputData = tencor->data;
    usz nelem = out->nelem;

    for (usz i = 0; i < nelem; i++)
        outData[i] = function(inputData[i], context);
}

Tencor *TencorUnaryMap(TencorArena *arena, const Tencor *tencor, TencorUnaryFn function, void *context)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    Tencor *out = TencorCreate(arena, tencor->ndim, tencor->shape);
    TencorUnaryMapInto(out, tencor, function, context);
    return out;
}

void TencorUnaryMapInPlace(Tencor *tencor, TencorUnaryFn function, void *context)
{
    TencorUnaryMapInto(tencor, tencor, function, context);
}

void TencorBinaryMapInto(Tencor *out, const Tencor *first, const Tencor *second, TencorBinaryFn function, void *context)
{
    RequireNonNull(function, "%s", "binary function is NULL");
    TencorRequireElementwise(out, first, second);

    f32 *outData = out->data;
    const f32 *firstData = first->data;
    const f32 *secondData = second->data;
    usz nelem = out->nelem;

    for (usz i = 0; i < nelem; i++)
        outData[i] = function(firstData[i], secondData[i], context);
}

Tencor *TencorBinaryMap(TencorArena *arena, const Tencor *first, const Tencor *second, TencorBinaryFn function, void *context)
{
    RequireNonNull(first, "%s", "first is NULL");
    Tencor *out = TencorCreate(arena, first->ndim, first->shape);
    TencorBinaryMapInto(out, first, second, function, context);
    return out;
}

void TencorBinaryMapInPlace(Tencor *first, const Tencor *second, TencorBinaryFn function, void *context)
{
    TencorBinaryMapInto(first, first, second, function, context);
}
