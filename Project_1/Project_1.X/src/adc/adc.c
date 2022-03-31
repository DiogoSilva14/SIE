#include "adc/adc.h"

static volatile uint32_t values_14[10];
static volatile uint32_t counter_14 = 0;
static volatile uint32_t values_15[10];
static volatile uint32_t counter_15 = 0;
static volatile uint32_t adc_pin = 14;

void init_adc1(){
   AD1CON1bits.SSRC = 0x7;
   AD1CON1bits.ASAM = 0;
   AD1CON3bits.ADCS = 2;
   AD1CON3bits.SAMC = 20;
   AD1PCFGbits.PCFG15 = 0;
   AD1PCFGbits.PCFG14 = 0;
   AD1CHSbits.CH0SA = adc_pin;
   
   INTSetVectorPriority(INT_ADC_VECTOR, INT_PRIORITY_LEVEL_2);
   INTSetVectorSubPriority(INT_ADC_VECTOR, INT_SUB_PRIORITY_LEVEL_3);
   INTClearFlag(INT_AD1);
   INTEnable(INT_AD1, INT_ENABLED); 
   
   AD1CON1bits.ADON = 1;
     
   AD1CON1bits.SAMP = 1;
}

int get_adc_mean(uint32_t pin){
    uint32_t sum = 0;
    
    INTDisableInterrupts();
    
    
    for(int i=0; i < 10; i++){
        if(pin == 14){
            sum += values_14[i];
        }else{
            sum += values_15[i];
        }
    }
    
    INTEnableInterrupts();
    
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
    if(adc_pin == 14){
        adc_pin = 15;
        AD1CHSbits.CH0SA = adc_pin;
        
        values_14[counter_14++] = ADC1BUF0;

        if(counter_14 == 10){
            counter_14 = 0;
        }
    }else{
        adc_pin = 14;
        AD1CHSbits.CH0SA = adc_pin;
        
        values_15[counter_15++] = ADC1BUF0;

        if(counter_15 == 10){
            counter_15 = 0;
        }
    }
    
    
    AD1CON1bits.SAMP = 1;
    
    INTClearFlag(INT_AD1);
}