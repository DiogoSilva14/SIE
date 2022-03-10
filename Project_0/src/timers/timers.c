#include "timers/timers.h"

void init_timer4(){
    T4CON = 0x0;    // Stop Timer4 operation
    T4CONbits.TCKPS = 7;
    TMR4 = 0;
    PR4 = 65000;
    T4CONbits.ON = 1;
}