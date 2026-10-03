#ifndef HELPER_H_
#define HELPER_H_

#include "types.h"

void require(bool condition, const char *func, const char *fmt, ...);

#define Require(condition, fmt, ...) require((condition), __func__, (fmt), __VA_ARGS__)
#define RequireNonNull(ptr, fmt, ...) Require((ptr) != NULL, (fmt), __VA_ARGS__)

#endif // HELPER_H_
