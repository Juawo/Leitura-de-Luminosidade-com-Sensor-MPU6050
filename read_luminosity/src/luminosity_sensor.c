// BH1750 .c file implementation
#include "luminosity_sensor.h"

// I2C Initialisation. Using it at 400Khz.
 // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c
void bh1750_start_measurement()
{
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

void setup_I2C()
{
    uint8_t cmd = BH1750_CMD_START;
    i2c_write_blocking(I2C_PORT, BH1750_ADDR, &cmd, 1, false);
}

uint16_t bh1750_read_lux()
{
    uint8_t data[2];
    i2c_read_blocking(I2C_PORT, BH1750_ADDR, data, 2, false);
    return (data[0] << 8) | data[1];
}
