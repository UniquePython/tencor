#ifndef ATTRIBUTES_H_
#define ATTRIBUTES_H_

#include "tencor/attributes.h"

// clang-format off
#define TENCOR_DESIGNATED_INIT      __attribute__((designated_init))
#define TENCOR_ACCESS_WRITE_ONLY(n) __attribute__((access(write_only, n)))
#define TENCOR_NONNULL(...)         __attribute__((nonnull(__VA_ARGS__)))
#define TENCOR_PRINTF(fmt, va)      __attribute__((format(printf, fmt, va)))
// clang-format on

#endif // ATTRIBUTES_H_
