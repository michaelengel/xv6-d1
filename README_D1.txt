This is a first rough port of xv6 to the Nezha RISC-V board using 
the Allwinner D1 SoC. It has not been extensively tested, so bugs
are to be expected.

Details on the board and SoC, including data sheets, can be found at:
https://linux-sunxi.org/Allwinner_Nezha
https://linux-sunxi.org/D1

Build the system using the riscv-unknown-elf GNU toolchain using:
$ make fs.img
$ make

This generates a binary kernel image in kernel/kernel.bin

Like the original xv6 version for RISC-V, this port runs on bare metal, 
starting from M-mode. Currently, you need xfel to load the kernel via
USB-C (use the OTG port, which can also power the board):

- Download and build xfel from https://github.com/xboot/xfel

- Press the "FEL" button and power up the board

- Load and run the DDR3 RAM init code, then load the kernel to 
  physical address 0x40000000 and start it:

  xfel ddr ddr3; xfel write 0x40000000 ../xv6-d1/kernel/kernel.bin; \\
  xfel exec 0x40000000

- ONLY FOR MANGOPI MQ-PRO: on a MangoPi MQ-Pro, xfel ddr ddr3 does
  not seem to work, xfel ddr d1 can be used instead:

  xfel ddr d1; xfel write 0x40000000 ../xv6-d1/kernel/kernel.bin; \\
  xfel exec 0x40000000

- Start a terminal emulator on /dev/ttyUSB0 (or whereever the UART 
  of the D1 is mapped to), parameters 115200 bps, 8N1

- You should see the DRAM init log messages and then:

  xv6 kernel is booting

  init: starting sh
  $ 

Type ls to see the (few) commands contained in the RAM disk.

Changes to MIT's xv6 RISC-V version:

- Clock and HW init (clk.c, uartinit.c) adapted from
  https://github.com/bigmagic123/d1-nezha-baremeta
  (yes, without the "l" :))

- adapted addresses of CLINT, PLIC, UART, UART IRQ
  and kernel start address from 0x80000000 to 0x40000000

- reloading the timer compare register is changed
  (kernelvec.S, start.c)
  On the D1, you have to read the "time" CSR to get the current
  time stamp instead of a CLINT register.

- initializes physical memory protection (PMP) to successfully switch
  from M- to S-mode (pmpinit in start.c, support functions in riscv.h)

- uses a ram disk instead of a virtio disk
  The RAM disk is included with the kernel image (kernel/ramdisk.h)
  and is automatically regenerated when rebuilding the file system
  using "make fs.img"

- Sets PLIC_CTRL to 1 to enable PLIC config modification from M-mode

Enjoy!

Michael Engel (engel@multicores.org)

