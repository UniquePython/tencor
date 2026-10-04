#ifndef TENCOR_H_
#define TENCOR_H_

#include "types.h"
#include "tencor/tencor.h"
#include "attributes.h"

#define TENCOR_DATA_ALIGNMENT 64

struct TENCOR_DESIGNATED_INIT Tencor
{
    f32 *data;
    usz ndim;
    usz nelem;
    usz *shape;
    usz *strides;
};

void TencorRequireSameShape(const Tencor *first, const Tencor *second);
void TencorRequireNoPartialOverlap(const Tencor *first, const Tencor *second);
void TencorRequireElementwise(const Tencor *out, const Tencor *first, const Tencor *second);

#endif // TENCOR_H_
