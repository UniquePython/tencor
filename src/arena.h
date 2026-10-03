#ifndef ARENA_H_
#define ARENA_H_

#include "types.h"
#include "attributes.h"
#include "tencor/arena.h"

TENCOR_DESIGNATED_INIT struct TencorArena
{
    u8 *base;
    usz capacity;
    usz used;
    bool owned;
};

#endif
