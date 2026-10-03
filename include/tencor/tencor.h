#ifndef TENCOR_TENCOR_H_
#define TENCOR_TENCOR_H_

#include "tencor/arena.h"
#include <stddef.h>
#include <stdbool.h>

typedef struct Tencor Tencor;

Tencor *TencorCreate(TencorArena *arena, size_t ndim, const size_t *shape);
Tencor *TencorZeros(TencorArena *arena, size_t ndim, const size_t *shape);
Tencor *TencorOnes(TencorArena *arena, size_t ndim, const size_t *shape);
Tencor *TencorOf(TencorArena *arena, size_t ndim, const size_t *shape, float value);

size_t TencorNelem(const Tencor *tencor);
size_t TencorNdim(const Tencor *tencor);
const size_t *TencorShape(const Tencor *tencor);
const size_t *TencorStrides(const Tencor *tencor);
float *TencorData(const Tencor *tencor);
bool TencorIsContiguous(const Tencor *tencor);

#endif // TENCOR_TENCOR_H_
