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
#include <p32xxxx.h>
#include <stdio.h>
#include <stdint.h>
#include <xc.h>
#include "config_bits.h"
#include "constants.h"
#include "timers/timers.h"
#include "uart/uart_functions.h"

void delay_us(unsigned int us)
{
    // Convert microseconds us into how many clock ticks it will take
    us *= GetSystemClock() / 1000000 / 2; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (us > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}

int main(){
 
    init_uart(115200);

    for(int i=0; i < 100; i++){
        printf("Num: %d \n\r", i);
        delay_us(1000000);
    }
    
    int a = 0;
    
    while(1)
    {
        printf("COUNT DONE\n\r");
        delay_us(1000000);
    }
}
