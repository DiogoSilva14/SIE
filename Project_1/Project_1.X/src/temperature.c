#include "temperature.h"

float get_thermistor_temp(){
   float voltage = (float)read_adc1(15)*3.3/1024;
   float temp = (voltage-1.08)/0.032 + 10; 
   
   return temp;
}

