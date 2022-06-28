/* ************************************************************************** */
/**

  @Company
    Universidade de Aveiro

  @File Name
    encoder.h

  @Summary
    Header file for all functions associated with the motor encoder
 */
/* ************************************************************************** */

#ifndef _ENCODER_H    /* Guard against multiple inclusion */
#define _ENCODER_H

#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "aux_functions.h"
#include "constants.h"
#include "motor_control.h"

#define RPM_AVG_VALUES 10 // Shouldn't be higher than 128
#define CPR 360.0
#define RPM_CALC_FREQ 100.0 // Frequency of the ISR to calculate the rpm

void init_encoder();
void __ISR(_CHANGE_NOTICE_VECTOR, IPL7AUTO) CNInterrupt(void);
float get_RPM();
uint32_t get_forward_ticks();
uint32_t get_backward_ticks();

#endif
