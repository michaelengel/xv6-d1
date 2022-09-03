#ifndef __D1_COMMON_H__
#define __D1_COMMON_H__

#include "types.h"

typedef unsigned long virtual_addr_t;

static inline void write32(virtual_addr_t addr, uint32 value)
{
    *((volatile uint32 *)(addr)) = value;
}

static inline uint32 read32(virtual_addr_t addr)
{
    return( *((volatile uint32 *)(addr)));
}

void sdelay(unsigned long us);

#endif
