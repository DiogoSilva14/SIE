#include "encoder.h"

float rpm[RPM_AVG_VALUES];
uint8_t rpm_head = 0;

uint32_t tick_count = 0;

uint8_t last_stat = 0;
uint8_t stat = 0;

uint32_t forward_ticks = 0;
uint32_t backward_ticks = 0;

void init_encoder(){
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD5 = 1;
    
    IPC6bits.CNIP = 1;
    IPC6bits.CNIS = 2;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    
    CNENbits.CNEN15 = 1;
    CNENbits.CNEN14 = 1;
    CNCONbits.ON = 1;
    
    uint32_t PR_REGISTER = GetPeripheralClock()/256/RPM_CALC_FREQ;
    
    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_256 | T4_32BIT_MODE_ON, PR_REGISTER);
    
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7AUTO) CNInterrupt(void){   
    stat = PORTDbits.RD5  + (PORTDbits.RD6 << 1);
    
    if(last_stat != stat){
        tick_count++;
        if(get_direction()){
            forward_ticks++;
        }else{
            backward_ticks++;
        }
    }
    
    last_stat = stat;
    
    IFS1bits.CNIF = 0;
}

float get_RPM(){   
    static float avg;
    
    avg = 0;
    
    for(int i=0; i < RPM_AVG_VALUES; i++){
        avg += rpm[i];
    }
    
    avg /= RPM_AVG_VALUES;
    
    return avg;
}

void __ISR(_TIMER_5_VECTOR, IPL3AUTO) Timer5Handler(void){    
    rpm[rpm_head++] = ((float)tick_count * RPM_CALC_FREQ * 60.0)/(CPR * 4.0);
    
    rpm_head = rpm_head % RPM_AVG_VALUES;
    
    tick_count = 0;
    
    mT5ClearIntFlag();
}

uint32_t get_forward_ticks(){
    return forward_ticks;
}

uint32_t get_backward_ticks(){
    return backward_ticks;
}