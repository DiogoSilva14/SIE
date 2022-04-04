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

void PID_init(float setpoint);
float PID_loop(float temp);

#endif