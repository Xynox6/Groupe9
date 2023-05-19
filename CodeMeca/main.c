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
#include <xc.h>

int convert_rad(float x){ 
    if (x < 0){
        printf("x cannot be negative");
        float rad = -((x * 2000.0) / 3.141592);
        int test = (int)(rad * 7.37 - 1.0)+3685.0;
        return test;
    }
    else{
    float rad = ((x * 2000.0) / 3.141592);
    int test = (int)(rad * 7.37 - 1.0)+3685.0;
    return test;
    }
}

int convert_deg(int x){
    if (x < 0){
        printf("x cannot be negative");
        float angle = -((x * 2000.0) / 180.0);
        int test = (int)(angle * 7.37 - 1.0)+3685.0;
        return test;
    }
    else{
    float angle = ((x * 2000.0) / 180.0);
    int test = (int)(angle * 7.37 - 1.0)+3685.0;
    return test;
    }
}
/*
void rotate(double angle, double x, double y, double z) {
    double rad = angle * 3.14 / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    double mat[3][3] = {{c + (1 - c) * x * x, (1 - c) * x * y - s * z, (1 - c) * x * z + s * y},
                        {(1 - c) * y * x + s * z, c + (1 - c) * y * y, (1 - c) * y * z - s * x},
                        {(1 - c) * z * x - s * y, (1 - c) * z * y + s * x, c + (1 - c) * z * z}};
    double vec[3] = {1.0, 2.0, 3.0};
    double res[3] = {0.0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i] += mat[i][j] * vec[j];
        }
    }
}
*/
int motor(int servo_num, float angle){
    
    if (servo_num == 1) {
        PTPER = PDC1 = convert_deg(angle);
            
    } else if (servo_num == 2) {
        PTPER = PDC2 = convert_deg(angle);
            
    } else if (servo_num == 3) {
        PTPER = PDC3 = convert_deg(angle);
            
    } else {
        printf("Invalid servo number.\n");
    }   
}

int motor2(int servo_num, float rad){
    
    if (servo_num == 1) {
        PTPER = PDC1 = convert_rad(rad);
            
    } else if (servo_num == 2) {
        PTPER = PDC2 = convert_rad(rad);
            
    } else if (servo_num == 3) {
        PTPER = PDC3 = convert_rad(rad);
            
    } else {
        printf("Invalid servo number.\n");
    }   
}
    /* Main Program                                                               */
int16_t main(void)
{  
    InitApp(); //user.c
        
    while (1) {
        __delay_ms(4000);
        motor(3,0);
        motor(2,0);
        motor(1,0);
        
        __delay_ms(4000);
        motor(1,30);
        motor(2,30);
        motor(3,30);
        
        __delay_ms(4000);
        motor(1,50);
        motor(2,50);
        motor(3,50);
    }
    return 0;
}

