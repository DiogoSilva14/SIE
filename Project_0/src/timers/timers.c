#include "timers/timers.h"

void init_timer4(uint32_t freq){
    
    uint32_t tick = GetPeripheralClock()/OSCCONbits.PBDIV/256/freq;
    
    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_256 | T4_32BIT_MODE_ON, tick);
    
    OpenTimer5(T5_ON | T5_SOURCE_INT, 0);
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
}

void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer4Handler(void){
    LATAbits.LATA3 = !LATAbits.LATA3;
    mT5ClearIntFlag();
}
