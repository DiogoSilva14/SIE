#include "timers/timers.h"

uint32_t PR_REGISTER = 0;

void init_timer4(uint32_t freq){
    
    uint32_t PR_REGISTER = GetPeripheralClock()/256/freq;
    
    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_256 | T4_32BIT_MODE_ON, PR_REGISTER);
    
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
}

void init_timer2_pwm(uint32_t freq, float duty_cycle){
    
    PR_REGISTER = GetPeripheralClock()/4/freq;
    
    OpenTimer2(T2_ON | T2_PS_1_4 , PR_REGISTER);
    
    float divisor = 100/duty_cycle;
    
    OC1RS = PR_REGISTER/divisor;
    
    OC1CONbits.OC32 = 0; // Disable 32bit mode
    OC1CONbits.OCTSEL = 0; // Use Timer2 as a source
    OC1CONbits.OCM = 0b110; // PWM Mode, fault pin disabled
    OC1CONbits.ON = 1; // Enable Output compare
}

void pwm_dutycycle(float duty_cycle){
    float divisor = 100/duty_cycle;
    
    OC1RS = PR_REGISTER/divisor;
}

void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void){
    LATAbits.LATA3 = !LATAbits.LATA3;
    mT5ClearIntFlag();
}
