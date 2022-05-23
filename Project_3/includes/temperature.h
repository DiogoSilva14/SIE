/* ************************************************************************** */
/** 
 * 
  @file temperature.h

    This is the header for the library associated with temperature reading functions
 */
/* ************************************************************************** */

#ifndef _TEMPERATURE_H    /* Guard against multiple inclusion */
#define _TEMPERATURE_H

#define THERMISTOR 14
#define THERMOCOUPLER 15
#define THERMISTOR_CALIB -3.13
#define THERMOCOUPLER_CALIB -10.7

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "constants.h"
#include "adc/adc.h"

/** @brief Gets the temperature of the specified device
 *
 *  @param device Device whose temperature is to be returned (use defines for
 *  THERMISTOR and THERMOCOUPLER)
 * 
 *  @return float temperature of the device
 */
float get_temp(uint8_t device);

/** @brief Asks the user for the setpoint of the heating element
 * 
 *  @return float of the setpoint entered
 */
float get_setpoint();

#endif