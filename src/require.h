#ifndef REQUIRE_H_
#define REQUIRE_H_

#include "types.h"
#include "attributes.h"

// clang-format off
TENCOR_NORETURN TENCOR_COLD TENCOR_PRINTF(2, 3)
void requireFail(const char *func, const char *fmt, ...);
// clang-format on

#define Require(condition, fmt, ...)                   \
    do                                                 \
    {                                                  \
        if (TENCOR_UNLIKELY(!(condition)))             \
            requireFail(__func__, (fmt), __VA_ARGS__); \
    } while (0)

#define RequireNonNull(ptr, fmt, ...) Require((ptr) != NULL, (fmt), __VA_ARGS__)

#endif // REQUIRE_H_
