#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/timer.h"
#include "pico/cyw43_arch.h"
#include "luminosity_sensor.h"

// I2C defines
// This example will use I2C0 on GPIO8 (SDA) and GPIO9 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments

// int64_t alarm_callback(alarm_id_t id, void *user_data) {
//     // Put your timeout handler code in here
//     return 0;
// }

int main()
{
    stdio_init_all();

    // Aguardar um momento para o stdio se inicializar
    sleep_ms(2000);

    printf("=== INICIANDO PROGRAMA ===\n");

    // Inicializar arquitetura do Pico W
    if (cyw43_arch_init())
    {
        printf("Falha ao inicializar CYW43\n");
        return -1;
    }

    printf("Iniciando sensor de luminosidade...\n");

    // Primeiro inicializar o I2C
    bh1750_start_measurement();
    printf("I2C inicializado.\n");

    // Aguardar estabilização
    sleep_ms(100);

    // Depois configurar o sensor
    setup_I2C();
    printf("Sensor BH1750 configurado.\n");

    printf("Sensor inicializado. Iniciando leituras...\n");

    while (true)
    {
        uint16_t lux = bh1750_read_lux();
        printf("Luminosidade: %u lux\n", lux);
        sleep_ms(1000);
    }
}
