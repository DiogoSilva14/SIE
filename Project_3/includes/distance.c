#include "distance.h"

float get_dist(){
    // Get the three zone's voltage from the ADC
    float zone_1_voltage = (float)get_adc_mean(ZONE_1)*3.3/1024;
    float zone_2_voltage = (float)get_adc_mean(ZONE_2)*3.3/1024;
    float zone_3_voltage = (float)get_adc_mean(ZONE_3)*3.3/1024;
    
    if(zone_1_voltage > zone_1_vals[0]){    // If the zone 1 voltage is lower than the lowest index of the LUT, the measurement is out of range
        return 90;
    }else if(zone_1_voltage < zone_1_vals[9]){  // Out of zone 1 range
        
        if(zone_2_voltage < zone_2_vals[19]){   // Out of zone 2 range
            if(zone_3_voltage < zone_3_vals[19]){   // If the zone 3 voltage is lower than the highest index of the LUT, the measurement is out of range
                return 610;
            }
            // ZONE 3 LINEARIZATION
            for(int i=0; i < 19; i++){
                if(zone_3_voltage < zone_3_vals[i] && zone_3_voltage > zone_3_vals[i+1]){
                    return 400 + 10*linearize(zone_3_vals[i], i, zone_3_vals[i+1], i+1, zone_3_voltage);
                }
            }
        }else{  // Value is in the zone 2 range
            // ZONE 2 LINEARIZATION
            for(int i=0; i < 19; i++){
                if(zone_2_voltage < zone_2_vals[i] && zone_2_voltage > zone_2_vals[i+1]){
                    return 200 + 10*linearize(zone_2_vals[i], i, zone_2_vals[i+1], i+1, zone_2_voltage);
                }
            }   
        }
    }else{  // Value is in zone 1 range
        // ZONE 1 LINEARIZATION
        for(int i=0; i < 9; i++){
            if(zone_1_voltage < zone_1_vals[i] && zone_1_voltage > zone_1_vals[i+1]){
                return 100 + 10*linearize(zone_1_vals[i], i, zone_1_vals[i+1], i+1, zone_1_voltage);
            }
        }
    }
}

float linearize(float upper, uint8_t upper_x, float lower, uint8_t lower_x, float val){
    // Find the slope of the two points
    float slope = (upper - lower)/(upper_x - lower_x);
    
    // Find the value at x = 0
    float offset = upper - slope*upper_x;
    
    // Do the inverse function and return it
    return ((val-offset)/slope);
}