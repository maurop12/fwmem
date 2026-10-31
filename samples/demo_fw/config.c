#include "config.h"

static const char device_name[] = "demo-firmware v0.1";   /* .rodata */
static int baud = 9600;                                   /* .data   */

void config_load(void)
{
    baud = 115200;
}

int config_get_baud(void)
{
    return baud;
}

const char *config_device_name(void)
{
    return device_name;
}
