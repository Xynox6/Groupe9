/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    // output
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    
    //Duty cycle
    P1TCONbits.PTCKPS = 0; // page 217
    P1TCONbits.PTMOD = 0; // page 217
    
    
    PTPER = 3684;
    //servo 1
    PWM1CON1bits.PEN1L = 1; // page 220
    
    
    PWM1CON1bits.PMOD1 = 0; // page 220
    PDC1 = 3684;
    
    //servo 2
    PWM1CON1bits.PEN1H = 1; // page 220

    P1TCONbits.PTEN = 1; // page 217
}
