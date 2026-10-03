#ifndef TENCOR_TENCOR_H_
#define TENCOR_TENCOR_H_

#include "tencor/arena.h"
#include <stddef.h>

typedef struct Tencor Tencor;

Tencor *TencorCreate(TencorArena *arena, size_t ndim, const size_t *shape);
Tencor *TencorZeros(TencorArena *arena, size_t ndim, const size_t *shape);
Tencor *TencorOnes(TencorArena *arena, usz ndim, const usz *shape);
Tencor *TencorOf(TencorArena *arena, usz ndim, const usz *shape, float value);

#endif // TENCOR_TENCOR_H_
