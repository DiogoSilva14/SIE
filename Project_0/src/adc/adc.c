#include "adc/adc.h"

static volatile uint32_t value_14;
static volatile uint32_t value_13;
static volatile uint32_t adc_pin = 14;

void init_adc1(){
   AD1CON1bits.SSRC = 0x7; // Use internal counter for conversion trigger source
   AD1CON1bits.ASAM = 0;   // Disable Sampling auto-start
   AD1CON3bits.ADCS = 5;   // Use PBCLK / 32 as clock source
   AD1CON3bits.SAMC = 20;  // Sample for 20 TAD (TAD = 1/(FPBCLK/ADCS))
   AD1PCFGbits.PCFG13 = 0; // Configure pin A13 as analog
   AD1PCFGbits.PCFG14 = 0; // Configure pin A14 as analog
   AD1CHSbits.CH0SA = adc_pin; // Pin to be sampled
   
   INTSetVectorPriority(INT_ADC_VECTOR, INT_PRIORITY_LEVEL_2); // Set interrupt priority
   INTSetVectorSubPriority(INT_ADC_VECTOR, INT_SUB_PRIORITY_LEVEL_3); // Set interrupt subpriority
   INTClearFlag(INT_AD1); // Clear interrupt flag
   INTEnable(INT_AD1, INT_ENABLED); // Enable ADC1 interrupt
   
   AD1CON1bits.ADON = 1; // Enable ADC1
     
   AD1CON1bits.SAMP = 1; // Start sampling
}

int get_adc_val(uint32_t pin){
    uint32_t val = 0;
    
    INTDisableInterrupts();
    
    if(pin == 14){
        val = value_14;
    }else{
        val = value_13;
    }
    
    INTEnableInterrupts();
    
    return val;
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
    // Alternate between conversions
    if(adc_pin == 14){
        adc_pin = 13;
        AD1CHSbits.CH0SA = adc_pin;
        
        value_14 = ADC1BUF0;
    }else{
        adc_pin = 14;
        AD1CHSbits.CH0SA = adc_pin;
        
        value_13 = ADC1BUF0;
    }
    
    // Start new conversion
    AD1CON1bits.SAMP = 1;
    
    // Clear interrupt flag
    INTClearFlag(INT_AD1);
}