#ifndef TENCOR_H_
#define TENCOR_H_

#include "types.h"
#include "tencor/tencor.h"

struct Tencor
{
    f32 *data;
    usz ndim;
    usz nelem;
    usz *shape;
    usz *strides;
};

#endif // TENCOR_H_
