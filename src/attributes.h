#ifndef ATTRIBUTES_H_
#define ATTRIBUTES_H_

#include "tencor/attributes.h"

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

// clang-format off
#define TENCOR_NONNULL(...)    __attribute__((nonnull(__VA_ARGS__)))
#define TENCOR_PRINTF(fmt, va) __attribute__((format(printf, fmt, va)))
// clang-format on

#if __has_attribute(access)
#define TENCOR_ACCESS_WRITE_ONLY(n) __attribute__((access(write_only, n)))
#else
#define TENCOR_ACCESS_WRITE_ONLY(n)
#endif

#if __has_attribute(designated_init)
#define TENCOR_DESIGNATED_INIT __attribute__((designated_init))
#else
#define TENCOR_DESIGNATED_INIT
#endif

#endif // ATTRIBUTES_H_
