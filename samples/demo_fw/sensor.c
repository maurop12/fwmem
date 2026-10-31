#include "sensor.h"

static const int calib_table[16] = {            /* .rodata */
    100, 104, 109, 115, 122, 130, 139, 149,
    160, 172, 185, 199, 214, 230, 247, 265
};
static int history[256];                         /* .bss    */
static unsigned history_pos;

int sensor_read(int channel)
{
    int value = calib_table[channel % 16] * 3 + channel;
    history[history_pos++ % 256] = value;
    return value;
}
