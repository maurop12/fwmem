#include <stdio.h>
#include "uart.h"
#include "config.h"
#include "sensor.h"

int main(void)
{
    config_load();
    uart_init(config_get_baud());
    for (int i = 0; i < 8; i++) {
        uart_send_int(sensor_read(i));
    }
    printf("%s\n", config_device_name());
    return 0;
}
