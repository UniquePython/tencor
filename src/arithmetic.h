#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

#include "types.h"
#include "attributes.h"

// clang-format off
TENCOR_NODISCARD TENCOR_ACCESS_WRITE_ONLY(3) TENCOR_NONNULL(3)
bool UszAdd(usz a, usz b, usz *result);

TENCOR_NODISCARD TENCOR_ACCESS_WRITE_ONLY(3) TENCOR_NONNULL(3)
bool UszSub(usz a, usz b, usz *result);

TENCOR_NODISCARD TENCOR_ACCESS_WRITE_ONLY(3) TENCOR_NONNULL(3)
bool UszMul(usz a, usz b, usz *result);
// clang-format on

#endif // ARITHMETIC_H_
