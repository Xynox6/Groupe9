/* 3 servomotors Code*/


#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33FJ128MC802.h>
    #endif
#endif

/* Global Variable Declaration  */

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>
#include <p33FJ128MC802.h>
    /*
    Servomotor rotation type: (datasheet: 500-2500 us (180))
     * 1000 us sets it to 0 degrees
     * 1500 us sets the servomotor to its neutral position (90 degrees)
     * 2000 us sets it to 180 degrees
*/


int convert_rad(float x){

    float rad = ((x * 2000.0) / 3.141592);
    
    int test = (int)(rad * 7.37 - 1.0)+3685.0;
    
    return test;
}

int convert_deg(int x){

    float angle = ((x * 2000.0) / 180.0);
    
    int test = (int)(angle * 7.37 - 1.0)+3685.0;
    
    return test;
}

    /* Main Program                                                               */
int16_t main(void)
{  

    InitApp(); //user.c
    
    //infinite loop (1 -> true)
    /*
     led rouge -> arret
     led vert -> marche
     */
    while (1) {
        //servo 1
        
        PTPER = PDC1 = convert_deg(0);
        __delay_ms(1000);
               
        PTPER = PDC1 = convert_deg(180);
        __delay_ms(1000);
        
        PTPER = PDC2 = convert_deg(180);
        __delay_ms(1000);
        
        PTPER = PDC2 = convert_deg(90);
        __delay_ms(1000);
        
        PTPER = PDC2 = convert_deg(0);
        __delay_ms(1000);
        
        PTPER = PDC3 = convert_deg(0);
        __delay_ms(1000);
        
        PTPER = PDC3 = convert_deg(90);
        __delay_ms(1000);
        
        PTPER = PDC3 = convert_deg(0);
        __delay_ms(1000);
    
    }
    return 0;
}

