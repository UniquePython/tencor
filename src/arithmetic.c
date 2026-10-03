#include "arithmetic.h"

bool UszAdd(usz a, usz b, usz *result)
{
    if (a > SIZE_MAX - b)
        return false;

    *result = a + b;
    return true;
}

bool UszSub(usz a, usz b, usz *result)
{
    if (a < b)
        return false;

    *result = a - b;
    return true;
}
