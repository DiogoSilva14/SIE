/* ************************************************************************** */
/**

  @Company
    Universidade de Aveiro

  @File Name
    motor_control.h

  @Summary
    Header file for all functions associated with the motor control
 */
/* ************************************************************************** */

#ifndef _MOTOR_CONTROL_H    /* Guard against multiple inclusion */
#define _MOTOR_CONTROL_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "aux_functions.h"
#include "constants.h"
#include "encoder.h"
#include "PI.h"
#include "adc/adc.h"
#include "timers/timers.h"

#define PI_LOOP_FREQ 100

void init_motor();
void __ISR(_TIMER_3_VECTOR, IPL3AUTO) Timer3Handler(void);
void change_setpoint(float new_setpoint);
void change_direction();
float get_rpm_nocalc();
float get_duty_cycle();
uint8_t get_direction();

#endif
