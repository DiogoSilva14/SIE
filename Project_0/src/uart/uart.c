/** uart.c

  @File Name
    uart.c

  @Summary
 * Uart functions

  @Description
    Declaration of functions associated with UART
 */

#include "uart/uart.h"

void init_uart(uint32_t baud_rate){
    U1BRG = (PBCLK/(4*baud_rate)) - 1;
    U1STA = 0;
    U1MODE = 0x8000; // 8-bit, no parity bit, 1 stop bit
    U1STASET = 0x1400; // Rx and Tx
    U1MODEbits.ON = 1;
}