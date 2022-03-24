/* ************************************************************************** */
/**

  @file adc.h

    This is the header file for adc associated functions
 */
/* ************************************************************************** */

#ifndef _ADC_H    /* Guard against multiple inclusion */
#define _ADC_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "constants.h"

/** @brief 
 *
 *  @param 
 */

void init_adc1();

int read_adc1(uint8_t pin);

int get_adc_mean();

void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void);

#endif