/* ************************************************************************** */
/** uart.h
 * 
  @File Name
    uart.h

  @Summary
    Uart functions header file

  @Description
    Header file for functions associated with the uart
 */
/* ************************************************************************** */

#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H

#define SYSCLK 48000000U
#define PBCLK SYSCLK/2

#include <p32xxxx.h>
#include <stdio.h>
#include <stdint.h>

void init_uart(uint32_t baud_rate);

#endif
