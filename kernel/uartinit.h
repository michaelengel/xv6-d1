#ifndef __D1_UART_H__
#define __D1_UART_H__

#include "common.h"

//D1 debug uart use GPIOB8(TX0) and GPIOB9(RX0)
#define UART_BASE   (0X02500000)
#define UART1_BASE  (0X02500400)
#define UART2_BASE  (0X02500800)
#define UART3_BASE  (0X02500C00)
#define UART4_BASE  (0X02501000)
#define UART5_BASE  (0X02501400)


#define UART_RBR            (0x0000)
#define UART_THR            (0x0000)
#define UART_DLL            (0x0000)
#define UART_DLH            (0x0004)
#define UART_IER            (0x0004)
#define UART_IIR            (0x0008)
#define UART_FCR            (0x0008)
#define UART_LCR            (0x000C)
#define UART_MCR            (0x0010)
#define UART_LSR            (0x0014)
#define UART_MSR            (0x0018)
#define UART_SCH            (0x001C)
#define UART_USR            (0x007C)
#define UART_TFL            (0x0080)
#define UART_RFL            (0x0084)
#define UART_HSK            (0x0088)
#define UART_DMA_REQ_EN     (0x008C)
#define UART_HALT           (0x00A4)
#define UART_DBG_DLL        (0x00B0)
#define UART_DBG_DLH        (0x00B4)
#define UART_A_FCC          (0x00F0)
#define UART_A_RXDMA_CTRL   (0x0100)
#define UART_A_RXDMA_STR    (0x0104)
#define UART_A_RXDMA_STA    (0x0108)
#define UART_A_RXDMA_LMT    (0x010C)
#define UART_A_RXDMA_SADDRL           (0x0110)
#define UART_A_RXDMA_SADDRH           (0x0114)
#define UART_A_RXDMA_BL     (0x0118)
#define UART_A_RXDMA_IE     (0x0120)
#define UART_A_RXDMA_IS     (0x0124)
#define UART_A_RXDMA_WADDRL           (0x0128)
#define UART_A_RXDMA_WADDRH           (0x012C)
#define UART_A_RXDMA_RADDRL           (0x0130)
#define UART_A_RXDMA_RADDRH           (0x0134)
#define UART_A_RXDMA_DCNT   (0x0138)

#define UART_LSR_FIFOE		0x80    /* Fifo error */
#define UART_LSR_TEMT		0x40    /* Transmitter empty */
#define UART_LSR_THRE		0x20    /* Transmit-hold-register empty */
#define UART_LSR_BI		0x10    /* Break interrupt indicator */
#define UART_LSR_FE		0x08    /* Frame error indicator */
#define UART_LSR_PE		0x04    /* Parity error indicator */
#define UART_LSR_OE		0x02    /* Overrun error indicator */
#define UART_LSR_DR		0x01    /* Receiver data ready */
#define UART_LSR_BRK_ERROR_BITS	0x1E    /* BI, FE, PE, OE bits */

/* Interrupt Enable Register */
#define UART_IER_ERDAI    0x01    /* rx data recv'd       */
#define UART_IER_ETHREI   0x02    /* tx reg. empty        */
#define UART_IER_ELSI     0x04    /* rx line status       */
#define UART_IER_EMSI     0x08    /* MODEM status         */

/* Interrupt Identification Register */
#define UART_IIR_NOINT    0x01    /* no interrupt pending */
#define UART_IIR_IMA      0x06    /* interrupt identity:  */
#define UART_IIR_LSI      0x06    /*  - rx line status    */
#define UART_IIR_RDA      0x04    /*  - rx data recv'd    */
#define UART_IIR_THR      0x02    /*  - tx reg. empty     */
#define UART_IIR_MSI      0x00    /*  - MODEM status      */
#define UART_IIR_BSY      0x07    /*  - busy detect (DW) */

void sys_uart0_init(void);
void sys_uart_putc(uint8 uart_num, char c);
char sys_uart_getc(uint8 uart_num);

#endif
