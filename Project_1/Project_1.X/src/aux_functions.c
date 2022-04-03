#include <p32xxxx.h>
#include <stdio.h>
#include <stdint.h>
#include <xc.h>
#include "constants.h"

void delay_us(unsigned int us){
    // Convert microseconds us into how many clock ticks it will take
    us *= GetSystemClock() / 1000000 / 2; // Core Timer updates every 2 ticks

    unsigned long int start = _CP0_GET_COUNT(); // Set Core Timer count to 0

    while (us > (_CP0_GET_COUNT() - start)); // Wait until Core Timer count reaches the number we calculated earlier
}