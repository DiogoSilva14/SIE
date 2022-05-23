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
#include "distance.h"

#define _MAX_PWM 95.0

int main(){
    // This function optimizes PIC32's performance to the frequency chosen
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    // Enable Multivectored interruptions
    INTEnableSystemMultiVectoredInt();
    
    // Enable interruptions
    INTEnableInterrupts();
    
    // Initialize UART communication at 115200 baud rate
    init_uart(115200);
    // Initialize ADC1
    init_adc1();
    // Initialize the timer2 with PWM module at 2kHz with 0% duty-cycle
    init_timer2_pwm(20000, 0);
   
    // Initialize the board LED and make its value 0
    TRISAbits.TRISA3 = 0;
    LATAbits.LATA3 = 0;
    
    // Initialize some values to be used inside the loop
    float distance = 0;
    float duty_cycle = 0;
    
    while(1){
        // Get the distance measured by the sensor
        distance = get_dist();
         
        if(distance < 100){ // If the distance is below 100mm turn LED off and display 'E'. The Current source should be at the minimum.
            pwm_dutycycle(0);
            LATAbits.LATA3 = 0;
            printf("Distance: E \n\r");
        }else if(distance > 600){   // If the distance is above 600mm turn LED off and display 'E'. The current source should be at the maximum
            pwm_dutycycle(_MAX_PWM);
            LATAbits.LATA3 = 0;
            printf("Distance: E \n\r");
        }else{  // Display the distance and signalize that the distance measurement is valid. Turn the LED ON. The current source should be at a value proportional to the distance measured
           printf("Distance: %f \n\r", distance);
           LATAbits.LATA3 = 1;
           duty_cycle = (distance - 100) * (_MAX_PWM/500);
           printf("%f \n\r", duty_cycle);
           pwm_dutycycle(duty_cycle);
        }   
        
        // Delay so that the system runs at 10 Hz
        delay_us(100000);
    }
}