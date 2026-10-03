#include "tencor/arena.h"
#include "arena.h"
#include "require.h"
#include "arithmetic.h"
#include <stdlib.h>
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

TencorArena *TencorArenaInit(void *buffer, usz capacity)
{
    RequireNonNull(buffer, "%s", "buffer is NULL");
    Require(capacity != 0, "%s", "capacity is 0");

    TencorArena *arena = malloc(sizeof(*arena));
    RequireNonNull(arena, "%s", "failed to allocate arena");

    *arena = (TencorArena){
        .base = buffer,
        .capacity = capacity,
        .used = 0,
        .owned = false,
    };

    return arena;
}

TencorArena *TencorArenaCreate(usz capacity)
{
    Require(capacity != 0, "%s", "capacity is 0");

    void *buffer = malloc(capacity);
    RequireNonNull(buffer, "%s", "failed to allocate backing buffer for arena");
    TencorArena *arena = TencorArenaInit(buffer, capacity);
    arena->owned = true;
    return arena;
}

void TencorArenaReset(TencorArena *self)
{
    RequireNonNull(self, "%s", "self is NULL");
    self->used = 0;
}

void TencorArenaDestroy(TencorArena **arena)
{
    RequireNonNull(arena, "%s", "pointer to arena is NULL");
    RequireNonNull(*arena, "%s", "arena is NULL");

    if ((*arena)->owned)
        free((*arena)->base);

    free(*arena);
    *arena = NULL;
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
