#ifndef __D1_GPIO_H__
#define __D1_GPIO_H__

#include "types.h"
//d1 gpio base addr
#define D1_GPIO_BASE    (0x02000000)

//PB 13 (0~12)
#define D1_GPIO_PB_CFG0  (0x0030)
#define D1_GPIO_PB_CFG1  (0x0034)
#define D1_GPIO_PB_DAT   (0x0040)
#define D1_GPIO_PB_DRV0  (0x0044)
#define D1_GPIO_PB_DRV1  (0x0048)
#define D1_GPIO_PB_PULL0 (0x0054)

//PC 8 (0~7)
#define D1_GPIO_PC_CFG0  (0x0060)
#define D1_GPIO_PC_DAT   (0x0070)
#define D1_GPIO_PC_DRV0  (0x0074)
#define D1_GPIO_PC_PULL0 (0x0084)

//PD 23 (0~22)
#define D1_GPIO_PD_CFG0  (0x0090)
#define D1_GPIO_PD_CFG1  (0x0094)
#define D1_GPIO_PD_CFG2  (0x0098)
#define D1_GPIO_PD_DAT   (0x00A0)
#define D1_GPIO_PD_DRV0  (0x00A4)
#define D1_GPIO_PD_DRV1  (0x00A8)
#define D1_GPIO_PD_DRV2  (0x00AC)
#define D1_GPIO_PD_PULL0 (0x00B4)
#define D1_GPIO_PD_PULL1 (0x00B8)

//PE 18 (0~17)
#define D1_GPIO_PE_CFG0  (0x00C0)
#define D1_GPIO_PE_CFG1  (0x00C4)
#define D1_GPIO_PE_DAT   (0x00D0)
#define D1_GPIO_PE_DRV0  (0x00D4)
#define D1_GPIO_PE_DRV1  (0x00D8)
#define D1_GPIO_PE_PULL0 (0x00E4)

//PF 7  (0~7)
#define D1_GPIO_PF_CFG0  (0x00F0)
#define D1_GPIO_PF_DAT   (0x0100)
#define D1_GPIO_PF_DRV0  (0x0104)
#define D1_GPIO_PF_PULL0 (0x0114)

//PG 19 (0~18)
#define D1_GPIO_PG_CFG0  (0x0120)
#define D1_GPIO_PG_CFG1  (0x0124)
#define D1_GPIO_PG_DAT   (0x0130)
#define D1_GPIO_PG_DRV0  (0x0134)
#define D1_GPIO_PG_DRV1  (0x0138)
#define D1_GPIO_PG_DRV3  (0x0140)
#define D1_GPIO_PG_PULL0 (0x0124)

//EINT
//PB
#define D1_GPIO_PB_EINT_CFG0    (0x0220)
#define D1_GPIO_PB_EINT_CTL     (0x0230)
#define D1_GPIO_PB_EINT_STATUS  (0x0234)
#define D1_GPIO_PB_EINT_DEB     (0x0238)

//PC
#define D1_GPIO_PC_EINT_CFG0    (0x0240)
#define D1_GPIO_PC_EINT_CTL     (0x0250)
#define D1_GPIO_PC_EINT_STATUS  (0x0254)
#define D1_GPIO_PC_EINT_DEB     (0x0258)

//PD
#define D1_GPIO_PD_EINT_CFG0    (0x0260)
#define D1_GPIO_PD_EINT_CFG1    (0x0264)
#define D1_GPIO_PD_EINT_CFG2    (0x0268)
#define D1_GPIO_PD_EINT_CTL     (0x0270)
#define D1_GPIO_PD_EINT_STATUS  (0x0274)
#define D1_GPIO_PD_EINT_DEB     (0x0278)

//PE
#define D1_GPIO_PE_EINT_CFG0    (0x0280)
#define D1_GPIO_PE_EINT_CFG1    (0x0284)
#define D1_GPIO_PE_EINT_CTL     (0x0290)
#define D1_GPIO_PE_EINT_STATUS  (0x0294)
#define D1_GPIO_PE_EINT_DEB     (0x0298)

//PF
#define D1_GPIO_PF_EINT_CFG0    (0x02A0)
#define D1_GPIO_PF_EINT_CTL     (0x02B0)
#define D1_GPIO_PF_EINT_STATUS  (0x02B4)
#define D1_GPIO_PF_EINT_DEB     (0x02B8)

//PG
#define D1_GPIO_PG_EINT_CFG0    (0x02C0)
#define D1_GPIO_PG_EINT_CFG1    (0x02C4)
#define D1_GPIO_PG_EINT_CTL     (0x02D0)
#define D1_GPIO_PG_EINT_STATUS  (0x02D4)
#define D1_GPIO_PG_EINT_DEB     (0x02D8)

#define PIO_POW_MOD_SEL         (0x0340)
#define PIO_POW_MS_CTL          (0x0344)
#define PIO_POW_VAL             (0x0348)
#define PIO_POW_VOL_SET_CTL     (0x0350)

#define     GPIO_PORT_B       (D1_GPIO_BASE + D1_GPIO_PB_CFG0)
#define     GPIO_PORT_C       (D1_GPIO_BASE + D1_GPIO_PC_CFG0)
#define     GPIO_PORT_D       (D1_GPIO_BASE + D1_GPIO_PD_CFG0)
#define     GPIO_PORT_E       (D1_GPIO_BASE + D1_GPIO_PE_CFG0)
#define     GPIO_PORT_F       (D1_GPIO_BASE + D1_GPIO_PF_CFG0)
#define     GPIO_PORT_G       (D1_GPIO_BASE + D1_GPIO_PG_CFG0)

#define     GPIO_PIN_0        (0)
#define     GPIO_PIN_1        (1)
#define     GPIO_PIN_2        (2)
#define     GPIO_PIN_3        (3)
#define     GPIO_PIN_4        (4)
#define     GPIO_PIN_5        (5)
#define     GPIO_PIN_6        (6)
#define     GPIO_PIN_7        (7)
#define     GPIO_PIN_8        (8)
#define     GPIO_PIN_9        (9)
#define     GPIO_PIN_10       (10)
#define     GPIO_PIN_11       (11)
#define     GPIO_PIN_12       (12)
#define     GPIO_PIN_13       (13)
#define     GPIO_PIN_14       (14)
#define     GPIO_PIN_15       (15)
#define     GPIO_PIN_16       (16)
#define     GPIO_PIN_17       (17)
#define     GPIO_PIN_18       (18)
#define     GPIO_PIN_19       (19)
#define     GPIO_PIN_20       (20)
#define     GPIO_PIN_21       (21)
#define     GPIO_PIN_22       (22)
#define     GPIO_PIN_23       (23)
#define     GPIO_PIN_24       (24)
#define     GPIO_PIN_25       (25)

void d1_set_gpio_mode(uint32_t gpio_port, uint32_t gpio_pin, uint16_t mode);
void d1_set_gpio_val(uint32_t gpio_port, uint32_t gpio_pin, uint32_t val);
uint8_t d1_get_gpio_val(uint32_t gpio_port, uint32_t gpio_pin);

#endif
