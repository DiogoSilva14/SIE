#include "adc/adc.h"

static volatile uint32_t adc_value = 0;

void init_adc1(){
   AD1CON1bits.SSRC = 0x7;
   AD1CON1bits.ASAM = 0;
   AD1CON3bits.ADCS = 2;
   AD1CON3bits.SAMC = 20;
   AD1PCFGbits.PCFG15 = 0;
   AD1CHSbits.CH0SA = 15;
   
   AD1CON1bits.ADON = 1;
}

float get_adc_voltage(){
    return (float)adc_value/1024*3.3;
}

int read_adc1(uint8_t pin){    
    AD1CHSbits.CH0SA = pin;
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE){
        ;
    }
        
    adc_value = ADC1BUF0; 
}

void __ISR(_ADC_VECTOR, IPL2AUTO) Adc1Handler(void){
    adc_value = ADC1BUF0;
    
    INTClearFlag(INT_AD1);
}