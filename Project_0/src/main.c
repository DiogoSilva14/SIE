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
#include <stdint.h>
#include <xc.h>
#include "constants.h"
#include "timers/timers.h"
#include "uart/uart_functions.h"

int main(){
 
    init_uart(115200);

    for(int i=0; i < 10; i++){
        printf("Num: %d \n\r", i);
        delay_us(1000000);
    }
    
    while(1){
        printf("%c",_mon_getc(1));
    }
}