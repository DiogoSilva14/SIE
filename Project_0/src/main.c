/* ************************************************************************** */
/**
  @File main.c

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
    init_timer2_pwm(2000, 10.0);
    
    INTEnableSystemMultiVectoredInt();
    
    INTEnableInterrupts();
    
    char str[80];
    
    while(1){
        scanf("%s",str);
        printf("%s\n\r",str);
        //delay_us(100000);
    }
}