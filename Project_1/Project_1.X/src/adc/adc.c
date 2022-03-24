#include "adc/adc.h"

volatile int values[10];
volatile int counter = 0;

void init_adc1(){
   AD1CON1bits.SSRC = 0x7;
   AD1CON1bits.ASAM = 0;
   AD1CON3bits.ADCS = 2;
   AD1CON3bits.SAMC = 20;
   AD1PCFGbits.PCFG15 = 0;
   AD1CHSbits.CH0SA = 15;
   AD1CON1bits.SAMP = 1;
   
   INTSetVectorPriority(INT_ADC_VECTOR, INT_PRIORITY_LEVEL_2);
   INTSetVectorSubPriority(INT_ADC_VECTOR, INT_SUB_PRIORITY_LEVEL_3);
   INTClearFlag(INT_AD1);
   INTEnable(INT_AD1, INT_ENABLED); 
   
   AD1CON1bits.ADON = 1;
   
}

int get_adc_mean(){
    int sum = 0;
    
    for(int i=0; i < 10; i++){
        sum += values[i];
    }
    
    return sum/10;
}

int read_adc1(uint8_t pin){
    
    int sum = 0;
    
    for(int i=0; i < 10; i++){
        AD1CHSbits.CH0SA = pin;
        AD1CON1bits.SAMP = 1;
        while(!AD1CON1bits.DONE){
            ;
        }
        
        sum += ADC1BUF0;
    }
     
    
    return sum/10; 
}

void __ISR(_ADC_VECTOR, IPL2AUTO) Adc1Handler(void){
    printf("a\n");
    
    values[counter++] = ADC1BUF0;
    
    if(counter == 10){
        counter = 0;
    }
    
    INTClearFlag(INT_AD1);
}