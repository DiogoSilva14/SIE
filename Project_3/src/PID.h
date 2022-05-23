/* ************************************************************************** */
/**

  @file PID.h

    This module is responsible for the PI implementation
 */
/* ************************************************************************** */

#ifndef _PID_H    /* Guard against multiple inclusion */
#define _PID_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "constants.h"

#define Kp 5
#define Ki 7

/** @brief Initiates the PI with the desired setpoint
 *
 *  @param setpoint Temperature desired for the PI controller
 */
void PI_init(float setpoint);

/** @brief Calcules the output of the controller for the given temperature
 *
 *  @param temp temperature measured on the heating element
 * 
 *  @return float value corresponding to the heater PWM
 */
float PI_loop(float temp);

#endif