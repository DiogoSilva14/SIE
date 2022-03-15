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
#include "config_bits.h"
#include <p32xxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "aux_functions.h"
#include "constants.h"
#include "timers/timers.h"
#include "uart/uart_functions.h"

int main(){
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    INTDisableInterrupts();
    
    TRISAbits.TRISA3 = 0;
    init_uart(115200);
    init_timer4(1);
    
    INTEnableSystemMultiVectoredInt();
    
    INTEnableInterrupts();
    
    while(1){
        delay_us(100000);
    }
}