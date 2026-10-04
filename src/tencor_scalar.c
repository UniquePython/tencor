#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"

#define TENCOR_DEFINE_SCALAR(Name, operator)                                           \
    void Tencor##Name##ScalarInto(Tencor *out, const Tencor *tencor, f32 scalar)       \
    {                                                                                  \
        TencorRequireUnary(out, tencor);                                               \
                                                                                       \
        f32 *outData = out->data;                                                      \
        const f32 *inputData = tencor->data;                                           \
        usz nelem = out->nelem;                                                        \
                                                                                       \
        for (usz i = 0; i < nelem; i++)                                                \
            outData[i] = inputData[i] operator scalar;                                 \
    }                                                                                  \
                                                                                       \
    Tencor *Tencor##Name##Scalar(TencorArena *arena, const Tencor *tencor, f32 scalar) \
    {                                                                                  \
        RequireNonNull(tencor, "%s", "tencor is NULL");                                \
        Tencor *out = TencorCreate(arena, tencor->ndim, tencor->shape);                \
        Tencor##Name##ScalarInto(out, tencor, scalar);                                 \
        return out;                                                                    \
    }                                                                                  \
                                                                                       \
    void Tencor##Name##ScalarInPlace(Tencor *tencor, f32 scalar)                       \
    {                                                                                  \
        Tencor##Name##ScalarInto(tencor, tencor, scalar);                              \
    }

TENCOR_DEFINE_SCALAR(Add, +)
TENCOR_DEFINE_SCALAR(Sub, -)
TENCOR_DEFINE_SCALAR(Mul, *)
TENCOR_DEFINE_SCALAR(Div, /)
