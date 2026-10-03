#ifndef TENCOR_ARENA_H_
#define TENCOR_ARENA_H_

#include "tencor/attributes.h"
#include <stddef.h>

typedef struct TencorArena TencorArena;

// clang-format off
TENCOR_API TENCOR_NODISCARD
size_t TencorKiB(size_t n);

TENCOR_API TENCOR_NODISCARD
size_t TencorMiB(size_t n);

TENCOR_API TENCOR_NODISCARD
size_t TencorGiB(size_t n);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL TENCOR_MALLOC
TencorArena *TencorArenaInit(void *buffer, size_t capacity);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL TENCOR_MALLOC
TencorArena *TencorArenaCreate(size_t capacity);

TENCOR_API
void TencorArenaReset(TencorArena *self);

TENCOR_API
void TencorArenaDestroy(TencorArena **arena);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL TENCOR_ALLOC_SIZE(2) TENCOR_ALLOC_ALIGN(3)
void *TencorArenaAllocAligned(TencorArena *self, size_t size, size_t alignment);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL TENCOR_ALLOC_SIZE(2)
void *TencorArenaAlloc(TencorArena *self, size_t size);
// clang-format on

#endif // TENCOR_ARENA_H_
