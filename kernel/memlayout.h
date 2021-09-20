// Physical memory layout

// D1 is set up like this,
//
// 14000000 -- CLINT
// 10000000 -- PLIC
// 02500000 -- uart0 
// RAM starts at 40000000.

// the kernel uses physical memory thus:
// 40000000 -- entry.S, then kernel text and data
// end -- start of kernel page allocation area
// PHYSTOP -- end RAM used by the kernel

// qemu puts UART registers here in physical memory.
#define UART0 0x02500000L
#define UART0_IRQ 18

// core local interruptor (CLINT), which contains the timer.
#define CLINT 0x14000000L
#define CLINT_MTIMECMP(hartid) (CLINT + 0x4000 + 8*(hartid))
#define CLINT_MTIME (CLINT + 0xBFF8) // cycles since boot.

// qemu puts platform-level interrupt controller (PLIC) here.
#define PLIC 0x10000000L
#define PLIC_PRIORITY (PLIC + 0x0)
#define PLIC_PENDING (PLIC + 0x1000)
#define PLIC_MENABLE (PLIC + 0x2000)
#define PLIC_SENABLE (PLIC + 0x2080)
#define PLIC_CTRL      (PLIC + 0x1FFFFC)
#define PLIC_MPRIORITY (PLIC + 0x200000)
#define PLIC_SPRIORITY (PLIC + 0x201000)
#define PLIC_MCLAIM (PLIC + 0x200004)
#define PLIC_SCLAIM (PLIC + 0x201004)

// the kernel expects there to be RAM
// for use by the kernel and user pages
// from physical address 0x80000000 to PHYSTOP.
// currently uses 128 MB only
#define KERNBASE 0x40000000L
#define PHYSTOP (KERNBASE + 128*1024*1024)

// map the trampoline page to the highest address,
// in both user and kernel space.
#define TRAMPOLINE (MAXVA - PGSIZE)

// map kernel stacks beneath the trampoline,
// each surrounded by invalid guard pages.
#define KSTACK(p) (TRAMPOLINE - ((p)+1)* 2*PGSIZE)

// User memory layout.
// Address zero first:
//   text
//   original data and bss
//   fixed-size stack
//   expandable heap
//   ...
//   TRAPFRAME (p->trapframe, used by the trampoline)
//   TRAMPOLINE (the same page as in the kernel)
#define TRAPFRAME (TRAMPOLINE - PGSIZE)
