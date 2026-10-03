#ifndef ARENA_H_
#define ARENA_H_

#include "types.h"
#include "attributes.h"
#include "tencor/arena.h"

struct TENCOR_DESIGNATED_INIT TencorArena
{
    u8 *base;
    usz capacity;
    usz used;
    bool owned;
};

#endif
