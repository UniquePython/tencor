#ifndef TENCOR_ARENA_H_
#define TENCOR_ARENA_H_

#include <stddef.h>

typedef struct TencorArena TencorArena;

void *TencorArenaAllocAligned(TencorArena *self, size_t size, size_t alignment);
void *TencorArenaAlloc(TencorArena *self, size_t size);

#endif // TENCOR_ARENA_H_
