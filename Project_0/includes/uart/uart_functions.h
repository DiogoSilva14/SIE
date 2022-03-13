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

#ifndef _UART_FUNC_H    /* Guard against multiple inclusion */
#define _UART_FUNC_H

#include "constants.h"
#include <xc.h>
#include <p32xxxx.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

/** @brief Initializes UART1 and sets it as the output for stdio so we can use
 * printf() to output to UART1
 *
 *  @param baud_rate Baud rate to set for the UART
 */

void init_uart(uint32_t baud_rate);

#endif