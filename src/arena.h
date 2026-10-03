#ifndef ARENA_H_
#define ARENA_H_

#include "types.h"
#include "tencor/arena.h"

struct TencorArena
{
    u8 *base;
    usz capacity;
    usz used;
};

#endif
