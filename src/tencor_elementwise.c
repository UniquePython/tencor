#include "tencor/tencor.h"
#include "tencor.h"
#include "types.h"
#include "require.h"

#define TENCOR_DEFINE_ELEMENTWISE(Name, operator)                                       \
    void Tencor##Name##Into(Tencor *out, const Tencor *first, const Tencor *second)     \
    {                                                                                   \
        TencorRequireElementwise(out, first, second);                                   \
                                                                                        \
        f32 *outData = out->data;                                                       \
        const f32 *firstData = first->data;                                             \
        const f32 *secondData = second->data;                                           \
        usz nelem = out->nelem;                                                         \
                                                                                        \
        for (usz i = 0; i < nelem; i++)                                                 \
            outData[i] = firstData[i] operator secondData[i];                           \
    }                                                                                   \
                                                                                        \
    Tencor *Tencor##Name(TencorArena *arena, const Tencor *first, const Tencor *second) \
    {                                                                                   \
        RequireNonNull(first, "%s", "first is NULL");                                   \
        Tencor *out = TencorCreate(arena, first->ndim, first->shape);                   \
        Tencor##Name##Into(out, first, second);                                         \
        return out;                                                                     \
    }                                                                                   \
                                                                                        \
    void Tencor##Name##InPlace(Tencor *first, const Tencor *second)                     \
    {                                                                                   \
        Tencor##Name##Into(first, first, second);                                       \
    }

TENCOR_DEFINE_ELEMENTWISE(Add, +)
TENCOR_DEFINE_ELEMENTWISE(Sub, -)
TENCOR_DEFINE_ELEMENTWISE(Mul, *)
TENCOR_DEFINE_ELEMENTWISE(Div, /)
