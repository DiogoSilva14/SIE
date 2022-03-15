#include "timers/timers.h"

void init_timer4(uint32_t freq){
    
    uint32_t PR_REGISTER = GetPeripheralClock()/256/freq;
    
    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_256 | T4_32BIT_MODE_ON, PR_REGISTER);
    
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
}

void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void){
    LATAbits.LATA3 = !LATAbits.LATA3;
    mT5ClearIntFlag();
}
