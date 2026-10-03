#include "require.h"
#include "attributes.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

TENCOR_PRINTF(2, 0)
static void error(const char *func, const char *fmt, va_list args)
{
    fprintf(stderr, "%s: ", func);
    vfprintf(stderr, fmt, args);
    fputc('\n', stderr);
}

void requireFail(const char *func, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    error(func, fmt, args);
    va_end(args);
    abort();
}
