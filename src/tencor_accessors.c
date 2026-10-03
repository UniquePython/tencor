#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"

usz TencorNelem(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    return tencor->nelem;
}

usz TencorNdim(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    return tencor->ndim;
}

const usz *TencorShape(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    return tencor->shape;
}

const usz *TencorStrides(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    return tencor->strides;
}

f32 *TencorData(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");
    return tencor->data;
}

bool TencorIsContiguous(const Tencor *tencor)
{
    RequireNonNull(tencor, "%s", "tencor is NULL");

    usz expectedStride = 1;
    for (usz i = tencor->ndim; i-- > 0;)
    {
        if (tencor->shape[i] != 1 && tencor->strides[i] != expectedStride)
            return false;
        expectedStride *= tencor->shape[i];
    }
    return true;
}
