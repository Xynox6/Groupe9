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
#include<math.h>

int convert_rad(float x){ 
    if (x < 0){
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

void matrice(float angle1, float angle2, float angle3, float angle4){
    //rad conversion
    double rad1 = angle1 * 3.14 / 180.0;
    double rad2 = angle2 * 3.14 / 180.0;
    double rad3 = angle3 * 3.14 / 180.0;
    double rad4 = angle4 * 3.14 / 180.0;
    
    // data a
    int a2=1;
    int a3=1;
    int a4=1;
    
    // data cos
    double c1 = cos(rad1);
    double c2 = cos(rad2);
    double c3 = cos(rad3);
    double c4 = cos(rad4);
    
    //data sin
    double s1 = sin(rad1);
    double s2 = sin(rad2);
    double s3 = sin(rad3);
    double s4 = sin(rad4);
    
    double c23 = c2*c3-s2*s3;
    double s23 = s2*c3+c2*s3;
    
    double w1 = c1*(a4*c4*c23-a4*s4*s23+a2*c2+a3*c23);
    double w2 = s1*(a4*c4*c23-a4*s4*s23+a2*c2+a3*c23);
    
    double b1 = c2*(a2+a3*c3)+s2*(-a3*s3);
    double b2 = c2*(a3*s3)+s2*(a2+a3*c3);
    
    double theta1 = atan2(w2,w1);
    double theta2 = atan2(b2*(a2+a3*c3)-b1*a3*s3,b1*(a2+a3*c3)+b2*a3*s3);
    double theta3 = acos((b1**2+b2**2-a2**2-a3**2)/2*a2*a3);
    double theta4 = 3.14*log(sqrt(w1**2+w2**2));
}

// 1 servo control (degree)
int motor1(int servo_num, float angle){
    
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
// 1 servo control (radian)
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

// 3 servo control (degree)
int motor3(float angle1, float angle2, float angle3){
    PTPER = PDC1 = convert_deg(angle1);
    PTPER = PDC2 = convert_deg(angle2);
    PTPER = PDC3 = convert_deg(angle3);
}
// 3 servo control (radian)
int motor4(float rad1, float rad2, float rad3){
    PTPER = PDC1 = convert_rad(rad1);
    PTPER = PDC2 = convert_rad(rad2);
    PTPER = PDC3 = convert_rad(rad3);
}


    /* Main Program                                                               */
int16_t main(void)
{  
    InitApp(); //user.c
        
    while (1) {
        motor3(0,0,0);
        __delay_ms(2000);
        motor3(30,60,90);
        __delay_ms(2000);
    }
    return 0;
}

