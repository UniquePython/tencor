#include "tencor/arena.h"
#include "arena.h"
#include "require.h"
#include "arithmetic.h"

#include <stdalign.h>

usz TencorKiB(usz n)
{
    usz bytes;
    Require(UszMul(n, (usz)1024, &bytes), "memory requested is too large: %zu KiB", n);
    return bytes;
}

usz TencorMiB(usz n)
{
    usz bytes;
    Require(UszMul(n, (usz)1024 * 1024, &bytes), "memory requested is too large: %zu MiB", n);
    return bytes;
}

usz TencorGiB(usz n)
{
    usz bytes;
    Require(UszMul(n, (usz)1024 * 1024 * 1024, &bytes), "memory requested is too large: %zu GiB", n);
    return bytes;
}

void *TencorArenaAllocAligned(TencorArena *self, usz size, usz alignment)
{
    RequireNonNull(self, "%s", "self is NULL");
    Require(alignment != 0 && (alignment & (alignment - 1)) == 0, "alignment must be power of 2 (received: %zu)", alignment);

    uptr current = (uptr)self->base + self->used;
    usz padding = (usz)(((uptr)0 - current) & (alignment - 1));

    usz remaining;
    Require(UszSub(self->capacity, self->used, &remaining), "%s", "invariant violated: used exceeds capacity");

    usz available;
    Require(UszSub(remaining, padding, &available), "out of memory: need %zu (+%zu padding) bytes, have %zu bytes", size, padding, remaining);
    Require(UszSub(available, size, &available), "out of memory: need %zu (+%zu padding) bytes, have %zu bytes", size, padding, remaining);

    usz offset = self->used + padding;
    self->used = offset + size;
    return self->base + offset;
}

void *TencorArenaAlloc(TencorArena *self, usz size)
{
    return TencorArenaAllocAligned(self, size, alignof(max_align_t));
}
