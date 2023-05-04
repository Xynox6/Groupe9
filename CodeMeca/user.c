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
    TRISBbits.TRISB13 = 0; // Set RB13 as output
    
    // duty cycle
    // page 217 - datasheet
    P1TCONbits.PTCKPS = 0; // Set PWM time base input clock prescale
    P1TCONbits.PTMOD = 0; // Set PWM time base mode
    
    PTPER = 3684; // Set PWM time base period

    // page 220
    //servo 1
    PWM1CON1bits.PEN1L = 1; // Enable PWM1L output
    PWM1CON1bits.PMOD1 = 0;
    PDC1 = 3684;
    PDC2 = 3684;
    PDC3 = 3684; // Set initial duty cycle for servomotors
    
    //servo 2
    PWM1CON1bits.PEN1H = 1;

    //servo 3
    PWM1CON1bits.PEN2L = 1; // Enable PWM2L output
    PWM1CON1bits.PMOD2 = 0;

    // page 217
    P1TCONbits.PTEN = 1;
}
