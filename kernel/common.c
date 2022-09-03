#include "common.h"

static inline uint64 counter(void)
{
    uint64 cnt;
    __asm__ __volatile__("csrr %0, time\n" : "=r"(cnt) :: "memory");
    return cnt;
}

void sdelay(unsigned long us)
{
    uint64 t1 = counter();
    uint64 t2 = t1 + us * 24;
    do {
        t1 = counter();
    } while(t2 >= t1);
}
