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
//#include <unistd.h>

/** @brief Initializes UART1 and sets it as the output for stdio so we can use
 * printf() to output to UART1
 *
 *  @param baud_rate Baud rate to set for the UART
 */

void init_uart(uint32_t baud_rate);

/** @brief Gets a character from UART1
 *
 *  @param canblock If canblock is different than zero the function will block until a character is received. Otherwise it will return imediatelly, wherether the is a character or not
 */
int _mon_getc(int canblock);

/** @brief Trying to overwrite stdin function read()
 * 
 * The default return type is ssize_t but it isn't available in xc2.05 
 * so it was substituted by int
 *
 *  @param fd File descriptor to use reading (not implemented, the function
 * always reads from UART1
 *  @param buf Pointer to buffer to which the function should read into
 *  @param count Number of characters to read
 */
int read(int fd, void *buf, size_t count);
#endif