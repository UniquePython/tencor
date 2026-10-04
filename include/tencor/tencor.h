#ifndef TENCOR_TENCOR_H_
#define TENCOR_TENCOR_H_

#include "tencor/arena.h"
#include "tencor/attributes.h"
#include <stddef.h>
#include <stdbool.h>

typedef struct Tencor Tencor;

// clang-format off
TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorCreate(TencorArena *arena, size_t ndim, const size_t *shape);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorView(TencorArena *arena, const Tencor *base, size_t ndim, const size_t *shape);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorZeros(TencorArena *arena, size_t ndim, const size_t *shape);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorOnes(TencorArena *arena, size_t ndim, const size_t *shape);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorOf(TencorArena *arena, size_t ndim, const size_t *shape, float value);

TENCOR_API TENCOR_NODISCARD
size_t TencorNelem(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD
size_t TencorNdim(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
const size_t *TencorShape(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
const size_t *TencorStrides(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
float *TencorData(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD
bool TencorIsContiguous(const Tencor *tencor);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorAdd(TencorArena *arena, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorAddInto(Tencor *out, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorAddInPlace(Tencor *first, const Tencor *second);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorSub(TencorArena *arena, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorSubInto(Tencor *out, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorSubInPlace(Tencor *first, const Tencor *second);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorMul(TencorArena *arena, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorMulInto(Tencor *out, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorMulInPlace(Tencor *first, const Tencor *second);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorDiv(TencorArena *arena, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorDivInto(Tencor *out, const Tencor *first, const Tencor *second);

TENCOR_API
void TencorDivInPlace(Tencor *first, const Tencor *second);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorAddScalar(TencorArena *arena, const Tencor *tencor, float scalar);

TENCOR_API
void TencorAddScalarInto(Tencor *out, const Tencor *tencor, float scalar);

TENCOR_API
void TencorAddScalarInPlace(Tencor *tencor, float scalar);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorSubScalar(TencorArena *arena, const Tencor *tencor, float scalar);

TENCOR_API
void TencorSubScalarInto(Tencor *out, const Tencor *tencor, float scalar);

TENCOR_API
void TencorSubScalarInPlace(Tencor *tencor, float scalar);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorMulScalar(TencorArena *arena, const Tencor *tencor, float scalar);

TENCOR_API
void TencorMulScalarInto(Tencor *out, const Tencor *tencor, float scalar);

TENCOR_API
void TencorMulScalarInPlace(Tencor *tencor, float scalar);

TENCOR_API TENCOR_NODISCARD TENCOR_RETURNS_NONNULL
Tencor *TencorDivScalar(TencorArena *arena, const Tencor *tencor, float scalar);

TENCOR_API
void TencorDivScalarInto(Tencor *out, const Tencor *tencor, float scalar);

TENCOR_API
void TencorDivScalarInPlace(Tencor *tencor, float scalar);
// clang-format on

#endif // TENCOR_TENCOR_H_
