#include "temperature.h"

float get_thermistor_temp(){
   float voltage = (float)get_adc_mean()*3.3/1024;
   printf("Adc Value: %d \n\r", get_adc_mean());
   printf("Voltage: %f \n\r", voltage);
   float temp = (voltage-1.08)/0.032 + 10; 
   
   return temp;
}

