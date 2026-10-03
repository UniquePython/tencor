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

Tencor *TencorSub(TencorArena *arena, const Tencor *first, const Tencor *second);
void TencorSubInto(Tencor *out, const Tencor *first, const Tencor *second);
void TencorSubInPlace(Tencor *first, const Tencor *second);

Tencor *TencorMul(TencorArena *arena, const Tencor *first, const Tencor *second);
void TencorMulInto(Tencor *out, const Tencor *first, const Tencor *second);
void TencorMulInPlace(Tencor *first, const Tencor *second);

Tencor *TencorDiv(TencorArena *arena, const Tencor *first, const Tencor *second);
void TencorDivInto(Tencor *out, const Tencor *first, const Tencor *second);
void TencorDivInPlace(Tencor *first, const Tencor *second);

#endif // TENCOR_TENCOR_H_
