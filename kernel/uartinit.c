// Adapted from https://github.com/bigmagic123/d1-nezha-baremeta
#include "uartinit.h"
#include "clk.h"
#include "gpio.h"

#define UART0_MODE_TX   (6)
#define UART0_MODE_RX   (6)

void sys_uart_putc(uint8 uart_num, char c)
{
    virtual_addr_t addr = UART_BASE + uart_num * 0x4000;

    while((read32(addr + UART_LSR) & UART_LSR_THRE) == 0);
    write32(addr + UART_THR, c);
}

char sys_uart_getc(uint8 uart_num)
{
    virtual_addr_t addr = UART_BASE + uart_num * 0x4000;
    if((read32(addr + UART_LSR) & UART_LSR_DR))
    {
        return read32(addr + UART_RBR);
    }
    else
    {
        return -1;
    }
}

void sys_uart0_init(void)
{
    virtual_addr_t addr;
    uint32 val;

	/* Config GPIOB8 and GPIOB9 to txd0 and rxd0 */
	addr = 0x02000030 + 0x04;
	val = read32(addr);
	val &= ~(0xf << ((8 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((8 & 0x7) << 2));
	write32(addr, val);

	val = read32(addr);
	val &= ~(0xf << ((9 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((9 & 0x7) << 2));
	write32(addr, val);

	/* Open the clock gate for uart0 */
	addr = 0x0200190c;
	val = read32(addr);
	val |= 1 << 0;
	write32(addr, val);

	/* Deassert uart0 reset */
	addr = 0x0200190c;
	val = read32(addr);
	val |= 1 << 16;
	write32(addr, val);


    /* Config uart0 to 115200-8-1-0 */
    addr = UART_BASE + 0 * 0x4000;
    write32(addr + UART_DLH, 0x0);      //disable all interrupt
    write32(addr + UART_FCR, 0xf7);     //reset fifo
    write32(addr + UART_MCR, 0x0);      //uart mode

    // clear busy condition
    val = read32(addr + UART_IIR);
    if (val == UART_IIR_BSY) {
      val = read32(addr + UART_USR);
    } 

    // set 115200
    val = read32(addr + UART_LCR);
    val |= (1 << 7);                    //select Divisor Latch LS Register
    write32(addr + UART_LCR, val);
    write32(addr + UART_DLL, 0xd & 0xff);   // 0x0d=13 240000000/(13*16) = 115200 Divisor Latch Lows
    write32(addr + UART_DLH, (0xd >> 8) & 0xff); //Divisor Latch High
    val = read32(addr + UART_LCR);
    val &= ~(1 << 7);
    write32(addr + UART_LCR, val);

    val = read32(addr + UART_LCR);
    val &= ~0x1f;
    val |= (0x3 << 0) | (0 << 2) | (0x0 << 3); //8 bit, 1 stop bit,parity disabled
    write32(addr + UART_LCR, val);
    write32(addr + UART_IER, UART_IER_ERDAI|UART_IER_ETHREI); 
    // only enable RX IRQ
    // BUG:, system hangs when also enabling TX IRQ
}
