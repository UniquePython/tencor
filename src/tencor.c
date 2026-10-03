#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"

void TencorRequireSameShape(const Tencor *first, const Tencor *second)
{
    Require(first->ndim == second->ndim, "ndim mismatch: %zu vs %zu", first->ndim, second->ndim);
    for (usz i = 0; i < first->ndim; i++)
        Require(first->shape[i] == second->shape[i], "shape mismatch at dimension %zu: %zu vs %zu", i, first->shape[i], second->shape[i]);
}

void TencorRequireNoPartialOverlap(const Tencor *first, const Tencor *second)
{
    uptr firstStart = (uptr)first->data;
    uptr secondStart = (uptr)second->data;
    uptr firstEnd = firstStart + first->nelem * sizeof(f32);
    uptr secondEnd = secondStart + second->nelem * sizeof(f32);

    bool overlaps = firstStart < secondEnd && secondStart < firstEnd;
    bool identical = firstStart == secondStart && first->nelem == second->nelem;

    Require(!overlaps || identical, "%s", "tensors partially overlap in memory");
}

void TencorRequireElementwise(const Tencor *out, const Tencor *first, const Tencor *second)
{
    RequireNonNull(out, "%s", "out is NULL");
    RequireNonNull(first, "%s", "first is NULL");
    RequireNonNull(second, "%s", "second is NULL");

    TencorRequireSameShape(first, second);
    TencorRequireSameShape(out, first);

    Require(TencorIsContiguous(out), "%s", "out must be contiguous");
    Require(TencorIsContiguous(first), "%s", "first must be contiguous");
    Require(TencorIsContiguous(second), "%s", "second must be contiguous");

    TencorRequireNoPartialOverlap(out, first);
    TencorRequireNoPartialOverlap(out, second);
}
