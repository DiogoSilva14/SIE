/* ************************************************************************** */
/** constants.h

  @File Name
    constants.h

  @Summary
    Constants header file

  @Description
    This file is used to set constants for use by various functions, such as SYSCLK
 * , PBCLK, etc...
 */
/* ************************************************************************** */

#ifndef _CONST_H    /* Guard against multiple inclusion */
#define _CONST_H

#define	GetSystemClock()              (80000000ul)
#define	GetPeripheralClock()          (GetSystemClock()/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()         (GetSystemClock())

#endif