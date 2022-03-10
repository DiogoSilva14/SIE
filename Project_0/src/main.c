/* ************************************************************************** */
/** Descriptive File Name

  @Company
    University of Aveiro

  @File Name
    main.c

  @Summary
    Main file for the project

  @Description
    This is the file which has the main function
 */
#define _SUPPRESS_PLIB_WARNING

#include <p32xxxx.h>
#include <stdio.h>
#include <stdint.h>
#include "config_bits.h"
#include "timers/timers.h"
#include "uart/uart.h"

int main(){
    // LED4 is connected to Pin 13, which is RA3    
    
    TRISAbits.TRISA3 = 0;
    
    LATAbits.LATA3 = 1;
    
    init_uart(115200);
    
    while(1){
        U1TXREG = 'a';
    }
    
    init_timer4();
    
    while(1){
        if(TMR4 > 30000){
           LATAbits.LATA3 = 1; 
        }else{
           LATAbits.LATA3 = 0;
        }
    }
    
    return 0;
}
