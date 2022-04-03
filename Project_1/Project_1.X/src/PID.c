#include "PID.h"

long unsigned int core_timer_last = 0;
float temp_setpoint = 0;


void PID_init(float setpoint){
    temp_setpoint = setpoint;
    core_timer_last = _CP0_GET_COUNT();
}

float PID_loop(float temp){
    static float last_error = 0;
    static float last_integral = 0;
    
    float error = temp_setpoint - temp;
    
    float delta_ms = (float)((_CP0_GET_COUNT()- core_timer_last))/(GetSystemClock()) * 2;
    core_timer_last = _CP0_GET_COUNT();
    
    float new_integral = last_integral + Ki*(error + last_error)*delta_ms/2;
    
    if(new_integral > 100){
        new_integral = last_integral;
    }else if(new_integral <= 0){
        new_integral = last_integral;
    }
    
    float output = Kp*error + new_integral;
    
    last_integral = new_integral;
    last_error = error;
    
    //printf("Error: %f New_integral: %f Output: %f \n\r", error, new_integral, output);
    
    return output;
    
}