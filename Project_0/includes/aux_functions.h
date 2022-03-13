/* ************************************************************************** */
/** aux_functions.h

  @File Name
    aux_functions.h

  @Summary
    Various utility functions

  @Description
    This is the header file for functions that provide some utility
 */
/* ************************************************************************** */

#ifndef _AUX_FUNC_H    /* Guard against multiple inclusion */
#define _AUX_FUNC_H

/** @brief Blocks the microcontroller for a brief amount of time
 *
 *  @param us Amount of time to block in microseconds
 */

void delay_us(unsigned int us);

#endif