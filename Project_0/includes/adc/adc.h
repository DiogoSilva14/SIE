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

/** @brief Inits the adc using sampling by interrupt. The pins A15 and A14 are 
 * initialized as analog pins. The sampling is also started at the end of the 
 * initialization
 *
 */

void init_adc1();

/** @brief Reads an adc pin by polling
 * 
 *  @param pin Pin to be read
 * 
 *  @return integer value read by adc
 *
 */

int read_adc1(uint8_t pin);

/** @brief Gets the last value read by the adc of a given pin
 * 
 *  @param pin Mean requested
 * 
 *  @return integer mean of the requested pin
 *
 */

int get_adc_val(uint32_t pin);

/** @brief Interrupt to read adc sampled value and store it in a variable.
 * Changes pin to be sampled in each call.
 *
 */

void __ISR(_ADC_VECTOR, IPL2AUTO) Adc1Handler(void);

#endif