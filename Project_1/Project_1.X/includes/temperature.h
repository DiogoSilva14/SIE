/* ************************************************************************** */
/** 
 * 
  @file temperature.h

    This is the header for the library associated with temperature reading functions
 */
/* ************************************************************************** */

#ifndef _TEMPERATURE_H    /* Guard against multiple inclusion */
#define _TEMPERATURE_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "constants.h"
#include "adc/adc.h"

float get_thermistor_temp();

#endif