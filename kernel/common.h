#ifndef __D1_COMMON_H__
#define __D1_COMMON_H__

#include "types.h"

typedef unsigned long virtual_addr_t;
typedef unsigned int u32_t;

typedef unsigned long uint64_t;
typedef unsigned int uint32_t;

static inline void write32(virtual_addr_t addr, u32_t value)
{
    *((volatile u32_t *)(addr)) = value;
}

static inline u32_t read32(virtual_addr_t addr)
{
    return( *((volatile u32_t *)(addr)));
}

void sdelay(unsigned long us);

#endif
