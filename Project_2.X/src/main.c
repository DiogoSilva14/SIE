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
#include "encoder.h"
#include "PI.h"
#include "motor_control.h"

int main(){
    // This function optimizes PIC32's performance to the frequency chosen
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    // Enable Multivectored interruptions
    INTEnableSystemMultiVectoredInt();
    
    // Enable interruptions
    INTEnableInterrupts();
    
    // Initialize UART communication at 115200 baud rate
    init_uart(115200);
    
    // Initialize the Encoder library so as to read the RPM of the motor
    init_encoder();
    
    // Initialize TIMER2 with PWM mode enabled to control motor speed
    init_timer2_pwm(40000, 0.0);
    
    init_motor();
    
    char str[80];
    int i = 0;
    char input = 'a';
    int print_counter = 0;
    float val = 0;
    float angle = 0;
    
    while(1){
        input = _mon_getc(0);
       
        if(input != -1){
            if(input == 'd'){
                change_direction();
            }else if(input == '\r'){
                val = atof(str);
                change_setpoint(val);
                
                for(int x=0; x < 80; x++){
                    str[x] = '\0';
                }
                
                i = 0;
            }else{
                str[i++] = input;
            }
        } 
        

        if(++print_counter > 10){
            angle = (get_forward_ticks() - get_backward_ticks())/4 % 360;
            printf("RPM: %f DUTY_CYCLE: %f SETPOINT: %f, ANGLE: %f\n\r", get_rpm_nocalc(), get_duty_cycle(), PI_get_setpoint(), angle);
            print_counter = 0;
        }
       
        delay_us(10000);
    }
}