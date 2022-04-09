/* ************************************************************************** */
/**
  @File main.c

  This is the file which has the main function
 */
#include "config_bits.h"
#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "aux_functions.h"
#include "constants.h"
#include "timers/timers.h"
#include "uart/uart_functions.h"
#include "adc/adc.h"
#include "temperature.h"
#include "PID.h"

int main(){
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    INTEnableSystemMultiVectoredInt();
    
    INTEnableInterrupts();
    
    init_uart(115200);
    init_adc1();
    init_timer2_pwm(20000, 0);
    
    float setpoint = get_setpoint();
    
    PI_init(setpoint);
    
    while(1){
        
        float pwm = PI_loop(get_temp(THERMOCOUPLER));
        
        printf("Setpoint: %f Amb: %f Thermocoupler: %f\n\r", setpoint, get_temp(THERMISTOR), get_temp(THERMOCOUPLER));
        
        pwm_dutycycle(pwm);
        
        delay_us(100000);
        
    }
}