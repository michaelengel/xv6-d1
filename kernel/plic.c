#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"

//
// the riscv Platform Level Interrupt Controller (PLIC).
//

void
plicinit(void)
{
  // set desired IRQ priorities non-zero (otherwise disabled).
  *(uint32*)(PLIC + UART0_IRQ*4) = 1;
}

void
plicinithart(void)
{
  // set uart's enable bit for this hart's S-mode. 
  *(uint32*)PLIC_SENABLE = (1 << UART0_IRQ);
  *(uint32*)(PLIC_PRIORITY + (UART0_IRQ * 4)) = 0x1f;

  // set this hart's M- and S-mode priority threshold to 0.
  *(uint32*)PLIC_MPRIORITY = 0x0;
  *(uint32*)PLIC_SPRIORITY = 0x0;
}

// ask the PLIC what interrupt we should serve.
int
plic_claim(void)
{
  int irq = *(uint32*)PLIC_SCLAIM;
  return irq;
}

// tell the PLIC we've served this IRQ.
void
plic_complete(int irq)
{
  *(uint32*)PLIC_SCLAIM = irq;
}
