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

int main(){
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    INTEnableSystemMultiVectoredInt();
    
    INTEnableInterrupts();
    
    init_timer4(500);
    init_uart(9600);
    init_timer2_pwm(2000, 10.0);
    init_adc1();
    
    float pwm_val = 0;
    
    while(1){
        printf("PWM Val: %f \n", get_adc_voltage());
        pwm_val = get_adc_voltage()/3.3*100;
        pwm_dutycycle(pwm_val);
        delay_us(1000);
    }
}