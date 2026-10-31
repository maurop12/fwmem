#include <stdio.h>
#include "uart.h"

static char tx_buffer[512];        /* .bss  */
static int current_baud = 9600;    /* .data */

void uart_init(int baud)
{
    current_baud = baud;
    tx_buffer[0] = '\0';
}

void uart_send_int(int value)
{
    snprintf(tx_buffer, sizeof tx_buffer, "[%d baud] value=%d", current_baud, value);
    puts(tx_buffer);
}
