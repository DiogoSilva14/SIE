#include "PI.h"

long unsigned int core_timer_last = 0;
float setpoint = 0;


void PI_init(float new_setpoint){
    setpoint = new_setpoint;
    core_timer_last = _CP0_GET_COUNT();
}

float PI_loop(float temp){
    static float last_error = 0;
    static float last_integral = 0;
    
    float error = setpoint - temp;
    
    float delta_ms = (float)((_CP0_GET_COUNT()- core_timer_last))/(GetSystemClock()) * 2;
    core_timer_last = _CP0_GET_COUNT();
    
    float new_integral = last_integral + Ki*(error + last_error)*delta_ms/2;
    
    if(new_integral > 50){
        new_integral = last_integral;
    }else if(new_integral <= 0){
        new_integral = last_integral;
    }
    
    float output = Kp*error + new_integral;
    
    last_integral = new_integral;
    last_error = error;
    
    if(output < 0){
        output = 0;
    }else if(output > 50){
        output = 50;
    }
    
    //printf("Error: %f New_integral: %f Output: %f \n\r", error, new_integral, output);
    
    return output;
    
}

void PI_set(float new_setpoint){
    setpoint = new_setpoint;
}

float PI_get_setpoint(){
    return setpoint;
}