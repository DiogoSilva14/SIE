#include "temperature.h"

static float thermistor_temps[] = {0.000, 0.039, 0.079, 0.119, 0.158, 0.198, 0.238, 0.277, 0.317, 0.357, 0.397, 0.437, 0.477, 0.517, 0.557, 0.597, 0.637, 0.677, 0.718, 0.758, 0.798, 0.838, 0.879, 0.919, 0.960, 1.000, 1.041, 1.081, 1.122, 1.163, 1.203, 1.244, 1.285, 1.326, 1.366, 1.407, 1.448, 1.489, 1.530, 1.571, 1.612, 1.653, 1.694, 1.735, 1.776, 1.817, 1.858, 1.899, 1.941, 1.982, 2.023, 2.064, 2.106, 2.147, 2.188, 2.230, 2.271, 2.312, 2.354, 2.395, 2.436, 2.478, 2.519, 2.561, 2.602, 2.644, 2.685, 2.727, 2.768, 2.810, 2.851, 2.893, 2.934, 2.976, 3.017, 3.059, 3.100, 3.142, 3.184, 3.225, 3.267, 3.308, 3.350, 3.391, 3.433, 3.474, 3.516, 3.557, 3.599, 3.640, 3.68, 3.723, 3.765, 3.806, 3.848, 3.889, 3.931, 3.972, 4.013, 4.055, 4.096};

float get_temp(uint8_t device){
    float voltage = 0;
    float temp = 0;
    
    if(device == THERMOCOUPLER){
        voltage = (float)get_adc_mean(THERMOCOUPLER)*3.3/1024;
        
        voltage /= 0.401;
        
        voltage += thermistor_temps[(int)get_temp(THERMISTOR)];
        
        for(int i = 1; i < 101; i++){
            if(voltage < thermistor_temps[i] && voltage > thermistor_temps[i-1]){
                temp = (float)i - 0.5;
                break;
            }
        }
        
        temp += (THERMOCOUPLER_CALIB);
    }else if(device == THERMISTOR){
        voltage = (float)get_adc_mean(THERMISTOR)*3.3/1024;
        
        temp = (voltage-1.0557)/0.031755 + 10;
        temp += (THERMISTOR_CALIB);
    }
   
   return temp;
}
