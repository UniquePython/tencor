#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"
#include <math.h>

#define TENCOR_DEFINE_UNARY(Name, expression)                           \
    void Tencor##Name##Into(Tencor *out, const Tencor *tencor)          \
    {                                                                   \
        TencorRequireUnary(out, tencor);                                \
                                                                        \
        f32 *outData = out->data;                                       \
        const f32 *inputData = tencor->data;                            \
        usz nelem = out->nelem;                                         \
                                                                        \
        for (usz i = 0; i < nelem; i++)                                 \
        {                                                               \
            f32 value = inputData[i];                                   \
            outData[i] = (expression);                                  \
        }                                                               \
    }                                                                   \
                                                                        \
    Tencor *Tencor##Name(TencorArena *arena, const Tencor *tencor)      \
    {                                                                   \
        RequireNonNull(tencor, "%s", "tencor is NULL");                 \
        Tencor *out = TencorCreate(arena, tencor->ndim, tencor->shape); \
        Tencor##Name##Into(out, tencor);                                \
        return out;                                                     \
    }                                                                   \
                                                                        \
    void Tencor##Name##InPlace(Tencor *tencor)                          \
    {                                                                   \
        Tencor##Name##Into(tencor, tencor);                             \
    }

TENCOR_DEFINE_UNARY(Neg, -value)
TENCOR_DEFINE_UNARY(Abs, fabsf(value))
TENCOR_DEFINE_UNARY(Sqrt, sqrtf(value))
TENCOR_DEFINE_UNARY(Exp, expf(value))
TENCOR_DEFINE_UNARY(Log, logf(value))
TENCOR_DEFINE_UNARY(Relu, value > 0.0f ? value : 0.0f)
TENCOR_DEFINE_UNARY(Tanh, tanhf(value))
TENCOR_DEFINE_UNARY(Sigmoid, 1.0f / (1.0f + expf(-value)))
