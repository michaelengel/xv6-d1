#include "gpio.h"
#include "common.h"

void d1_set_gpio_mode(uint32_t gpio_port, uint32_t gpio_pin, uint16_t mode)
{
    uint32_t pin_level = 0;
    uint32_t gpio_base_addr = 0;
    uint32_t val = 0;
    pin_level = gpio_pin / 8;
    gpio_base_addr = gpio_port + pin_level * 0x04;
    val = read32(gpio_base_addr);

    val &= ~(0xf << ((gpio_pin & 0x7) << 2));
    val |= ((mode & 0xf) << ((gpio_pin & 0x7) << 2));

    write32(gpio_base_addr, val);
}

void d1_set_gpio_val(uint32_t gpio_port, uint32_t gpio_pin, uint32_t val)
{
    
}

uint8_t d1_get_gpio_val(uint32_t gpio_port, uint32_t gpio_pin)
{
    return 0;
}
