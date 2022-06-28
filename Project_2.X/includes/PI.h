/* ************************************************************************** */
/**

  @file PID.h

    This module is responsible for the PI implementation
 */
/* ************************************************************************** */

#ifndef _PI_H    /* Guard against multiple inclusion */
#define _PI_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "constants.h"

#define Kp 3
#define Ki 2

/** @brief Initiates the PI with the desired setpoint
 *
 *  @param setpoint Temperature desired for the PI controller
 */
void PI_init(float new_setpoint);

/** @brief Calcules the output of the controller for the given temperature
 *
 *  @param temp temperature measured on the heating element
 * 
 *  @return float value corresponding to the heater PWM
 */
float PI_loop(float val);

/** @brief Change the setpoint of the PI controller
 *
 *  @param setpoint new setpoint to set on the PI controller
 */
void PI_set(float new_setpoint);

float PI_get_setpoint();

#endif