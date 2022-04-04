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

float get_temp(uint8_t device);
float get_setpoint();

#endif