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
#include "adc/adc.h"

/** @brief Function to init timer4
 *
 *  @param freq Frequency of timer4 interrupt
 */
void init_timer4(uint32_t freq);

/** @brief Timer 5 ISR
 */
void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void);

/** @brief Function to initiate timer2 with output compare in PWM mode
 *
 *  @param freq Frequency of timer2 PWM
 *  @param duty_cycle Duty cycle of PWM signal from 0 to 100
 */
void init_timer2_pwm(uint32_t freq, float duty_cycle);

/** @brief Function to change the duty cycle of output compare PWM
 *
 *  @param duty_cycle New duty cycle value from 0 to 100
 */
void pwm_dutycycle(float duty_cycle);

#endif