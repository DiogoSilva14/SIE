#include "timers/timers.h"

uint32_t PR_REGISTER = 0;

void init_timer2_pwm(uint32_t freq, float duty_cycle){
    
    PR_REGISTER = GetPeripheralClock()/4/freq;
    
    OpenTimer2(T2_ON | T2_PS_1_4 , PR_REGISTER);
    
    pwm_dutycycle(duty_cycle);
    
    OC1CONbits.OC32 = 0; // Disable 32bit mode
    OC1CONbits.OCTSEL = 0; // Use Timer2 as a source
    OC1CONbits.OCM = 0b110; // PWM Mode, fault pin disabled
    OC1CONbits.ON = 1; // Enable Output compare
}

void pwm_dutycycle(float duty_cycle){
    float divisor = 100.0/duty_cycle;
    
    if(duty_cycle <= 0){
       OC1RS = 0; 
    }else{
       OC1RS = PR_REGISTER/divisor; 
    }
}
