#include "temperature.h"

static float thermocoupler_temps[] = {0.000, 0.039, 0.079, 0.119, 0.158, 0.198, 0.238, 0.277, 0.317, 0.357, 0.397, 0.437, 0.477, 0.517, 0.557, 0.597, 0.637, 0.677, 0.718, 0.758, 0.798, 0.838, 0.879, 0.919, 0.960, 1.000, 1.041, 1.081, 1.122, 1.163, 1.203, 1.244, 1.285, 1.326, 1.366, 1.407, 1.448, 1.489, 1.530, 1.571, 1.612, 1.653, 1.694, 1.735, 1.776, 1.817, 1.858, 1.899, 1.941, 1.982, 2.023, 2.064, 2.106, 2.147, 2.188, 2.230, 2.271, 2.312, 2.354, 2.395, 2.436, 2.478, 2.519, 2.561, 2.602, 2.644, 2.685, 2.727, 2.768, 2.810, 2.851, 2.893, 2.934, 2.976, 3.017, 3.059, 3.100, 3.142, 3.184, 3.225, 3.267, 3.308, 3.350, 3.391, 3.433, 3.474, 3.516, 3.557, 3.599, 3.640, 3.68, 3.723, 3.765, 3.806, 3.848, 3.889, 3.931, 3.972, 4.013, 4.055, 4.096, 4.138, 4.179, 4.220, 4.262, 4.303, 4.344, 4.385, 4.427, 4.468, 4.509, 4.550, 4.591, 4.633, 4.674, 4.715, 4.756, 4.797, 4.838, 4.879, 4.920, 4.961, 5.002, 5.043, 5.084, 5.124, 5.165, 5.206, 5.247, 5.288, 5.328, 5.369, 5.410, 5.450, 5.491, 5.532, 5.572, 5.613, 5.653, 5.694, 5.735, 5.775, 5.815, 5.856, 5.896, 5.937, 5.977, 6.017, 6.058, 6.098, 6.138};

float get_temp(uint8_t device){
    float voltage = 0;
    float temp = 0;
    
    if(device == THERMOCOUPLER){
        voltage = (float)get_adc_mean(THERMOCOUPLER)*3.3/1024;
        
        printf("Voltage: %f \n\r", voltage);
        
        voltage /= 0.71469;
        
        voltage += thermocoupler_temps[(int)get_temp(THERMISTOR)];
        
        for(int i = 1; i < 151; i++){
            if(voltage < thermocoupler_temps[i] && voltage > thermocoupler_temps[i-1]){
                temp = (float)i-1 + (voltage - thermocoupler_temps[i-1])/(thermocoupler_temps[i] - thermocoupler_temps[i-1]);
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

float get_setpoint(){
    char str[80]; 
    int i = 0;
    char input = 'a';
    
    printf("Insert the desired temperature setpoint: \r\n");
    
    while(input != '\r'){
        input = getchar();
        
        if(input != '\r'){
            //printf("%c", input);
            str[i++] = input;
        }       
    }
    
    printf("\n\r");
    
    return atof(str);
}
