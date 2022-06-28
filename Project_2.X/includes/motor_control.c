#include "motor_control.h"
    
float rpm = 0;
float duty_cycle = 0;
uint8_t direction = 1;

void init_motor(){
    uint32_t PR_REGISTER = GetPeripheralClock()/256/PI_LOOP_FREQ;
    
    OpenTimer3(T3_ON | T3_SOURCE_INT | T3_PS_1_256, PR_REGISTER);
    
    ConfigIntTimer3(T3_INT_ON | T3_INT_PRIOR_3);
    
    PI_init(10);
}

void __ISR(_TIMER_3_VECTOR, IPL3AUTO) Timer3Handler(void){
    rpm = get_RPM();
        
    duty_cycle = PI_loop(rpm);
    
    if(direction){
        pwm_dutycycle(50.0 + duty_cycle);
    }else{            
        pwm_dutycycle(50.0 - duty_cycle);
    }
    
    mT3ClearIntFlag();
}

void change_setpoint(float new_setpoint){
    PI_set(new_setpoint);
}

uint8_t get_direction(){
    return direction;
}

void change_direction(){
    direction = !direction;
}

float get_rpm_nocalc(){
    return rpm;
}

float get_duty_cycle(){
    return duty_cycle;
}