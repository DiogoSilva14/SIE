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

int main(){
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    INTEnableSystemMultiVectoredInt();
    
    INTEnableInterrupts();
    
    init_timer2_pwm(20000, 0);
    init_uart(9600);
    init_adc1();
    
    printf("Hi!\n\r");
    
    int pwm = 0;
    
    while(1){
        
        //printf("Thermistor: %f Thermocoupler: %f\n\r", get_temp(THERMISTOR), get_temp(THERMOCOUPLER));
        
        //delay_us(1000000);
        
        pwm_dutycycle(pwm++);
        
        if(pwm == 101){
            pwm = 0;
        }
        
        delay_us(100000);
    }
}