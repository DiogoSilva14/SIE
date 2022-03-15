/* ************************************************************************** */
/**
* @file timers.h
*
* This is the header file for functions associated to the initialization, 
* configuration and manipulation of timers
*/
/* ************************************************************************** */

#ifndef TIMERS_H   /* Guard against multiple inclusion */
#define TIMERS_H

#include <p32xxxx.h>
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include <sys/attribs.h>
#include "constants.h"

/** @brief Function to init timer4
 *
 *  @param freq Frequency of timer4 interrupt
 */
void init_timer4(uint32_t freq);

/** @brief Timer 5 ISR
 */
void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void);

#endif