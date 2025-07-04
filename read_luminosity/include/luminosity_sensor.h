// BH1750  .h file
#ifndef LUMINOSITY_SENSOR_H
#define LUMINOSITY_SENSOR_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include <stdlib.h>

#define I2C_PORT i2c0
#define I2C_SDA 8
#define I2C_SCL 9

void setup_I2C();
void bh1750_start_measurement();
uint16_t bh1750_read_lux();


#endif