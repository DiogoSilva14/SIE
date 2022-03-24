/** uart.c

  @File Name
    uart.c

  @Summary
 * Uart functions

  @Description
    Declaration of functions associated with UART
 */

#include "uart/uart_functions.h"

void init_uart(uint32_t baud_rate){
    __XC_UART = 1;  // Defines UART1 as the UART for stdout
    
    setbuf(stdin,NULL); // Clears in and out buffers
    setbuf(stdout,NULL);
    
    U1BRG = GetPeripheralClock()/(4*baud_rate) - 1; // Define baud rate in high speed mode
    
    U1MODEbits.ON = 0; // Turn UART off while configuring
    
    U1MODEbits.UEN = 0; // Only use Tx and Rx pins
    U1MODEbits.BRGH = 1; // Enable High-Speed Mode
    U1MODEbits.PDSEL = 0; // 8-bit data, no parity
    U1MODEbits.STSEL = 0; // 1 Stop bit
    
    U1STAbits.UTXSEL = 0; // Tx Interrupt when the transmit buffer contains at least one empty space
    U1STAbits.URXISEL = 0; // Rx Interrupt when a charachter is received
    U1STAbits.URXEN = 1; // Rx Enabled
    U1STAbits.UTXEN = 1; // Tx Enabled
    
    U1MODEbits.ON = 1; // Turn UART ON
}

int _mon_getc(int canblock){
    volatile unsigned int *rxreg = &U1RXREG;
    
    if(canblock == 0)
        if(U1STAbits.URXDA)
            return *rxreg;
        else
            return -1;
    else{
        while(!U1STAbits.URXDA);
        return *rxreg;
    }
}
/*
int read(int fd, void *buf, size_t count){
    for(int i=0; i < count; i++){
        char read_val = _mon_getc(1);
        
        if(!read_val){
            return -1;
        }
        else{
            *(char*)(buf+i) = read_val;
        }
    }
    
    return count;
}
*/