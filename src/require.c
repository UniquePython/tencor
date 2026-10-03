#include "require.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void error(const char *func, const char *fmt, va_list args)
{
    fprintf(stderr, "%s: ", func);
    vfprintf(stderr, fmt, args);
    fputc('\n', stderr);
}

void require(bool condition, const char *func, const char *fmt, ...)
{
    if (!condition)
    {
        va_list args;
        va_start(args, fmt);
        error(func, fmt, args);
        va_end(args);
        abort();
    }
}
