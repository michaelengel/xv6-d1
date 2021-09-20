#include "common.h"

static inline uint64_t counter(void)
{
    uint64_t cnt;
    __asm__ __volatile__("csrr %0, time\n" : "=r"(cnt) :: "memory");
    return cnt;
}

void sdelay(unsigned long us)
{
    uint64_t t1 = counter();
    uint64_t t2 = t1 + us * 24;
    do {
        t1 = counter();
    } while(t2 >= t1);
}
