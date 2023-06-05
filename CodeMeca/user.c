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

// Variable pour stocker la valeur analogique

void InitApp(void)
{
    // output
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB13 = 0; // Set RB13 as output
    TRISBbits.TRISB11 = 0;
    //TRISAbits.TRISA0 = 0;
    
    ADPCFGbits.PCFG1 = 0; // Définir la broche comme entrée analogique
    AD1CON1bits.AD12B = 0; // Résolution 10 bits
    AD1CON1bits.FORM = 0; // Format de sortie entier non signé
    AD1CON2bits.VCFG = 0; // Tension de référence VDD et VSS
    AD1CON3bits.ADCS = 2; // Horloge ADC : TAD = 3*Tcy
    AD1CHS0bits.CH0SA = 00000; // Sélectionner la broche analogique
    AD1CON1bits.ADON = 1; // Activer le module ADC
  
    // duty cycle
    // page 217 - datasheet
    P1TCONbits.PTCKPS = 0; // 227
    P1TCONbits.PTMOD = 0; // 217
    
    PTPER = 11054; // Set PWM time base period

    // page 220
    //servo 1
    PWM1CON1bits.PEN1L = 1; // Enable PWM1L1 output
    PWM1CON1bits.PMOD1 = 1;
    PDC1 = 11054;
    
    //servo 2
    PWM1CON1bits.PEN2L = 1; // Enable PWM1L2 output
    PWM1CON1bits.PMOD2 = 1;
    PDC2 = 11054;
    
    //servo 3
    
    PWM1CON1bits.PEN3L = 1;  // Enable PWM1H1 output
    PWM1CON1bits.PMOD3 = 1;
    PDC3 = 3684;
    
    // page 217
    P1TCONbits.PTEN = 1;
}
