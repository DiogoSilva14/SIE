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

#define SIGNAL 14
#define DELAY 13

#define SAMPLING_FREQ 100

int main(){
    // This function optimizes PIC32's performance to the frequency chosen
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    // Enable Multivectored interruptions
    INTEnableSystemMultiVectoredInt();
    
    // Enable interruptions
    INTEnableInterrupts();
    
    // Initialize UART communication at 9600 baud rate
    init_uart(9600);
    
    // Initialize the timer2 with PWM module at 2kHz with 0% duty-cycle
    init_timer2_pwm(2000, 0.0);
    
    // Initialize ADC1
    init_adc1();
    
    // This signal_vals array functions somewhat like a circular buffer, its
    // function is to store the values of the samples taken by the ADC, so
    // that we can vary the delay by adjusting the tail relating to the head
    uint16_t signal_vals[100] = {0};
    int16_t head = 0;
    int16_t tail = 0;
    int16_t delay_samples = 0;
   
    while(1){
        // Store the signal sample
        signal_vals[head] = get_adc_val(SIGNAL);
        
        // Get the amount of delay in samples by reading the delay potentiometer
        delay_samples = (get_adc_val(DELAY) * 100)/1024;
        
        // Prevent head from going over the array dimension
        head = head % 100;
        
        // The tail should be behind the head by an amount equal to
        // delay_samples. The + 100 is used to prevent negative values
        // The -1 prevents it from getting the head value
        tail = (head + 100 - delay_samples) % 100;
        
        // The PWM duty cycle is adjusted in regards to the signal to be displayed
        pwm_dutycycle((signal_vals[tail]*100)/1024);
        
        // Increment the head
        head++;
        
        // Regulate the sampling frequency
        delay_us(1000000/SAMPLING_FREQ);
    }
}