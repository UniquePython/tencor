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
