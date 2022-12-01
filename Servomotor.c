#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>
#include "lib_lcd_modificada.h"
#include <xc.h>
#include <pic18f4550.h>
#include "i2c.h"   // Libreria del protocolo I2C
#include "mpu6050.h" 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "servo.h"                      // Libreria para control de servomotores

float ax, ay, az, gx, gy, gz;

long map(long x, long eMin, long eMax, long sMin, long sMax) {
    return (x - eMin)*(sMax - sMin) / (eMax - eMin) + sMin;
}
//Hola

long map(long x, long eMin, long eMax, long sMin, long sMax);
char buffer[10];
float value;
float v1;

void main() {
    ADCON1bits.PCFG = 0x0F; // Coloca todos los pines como digitales
    I2C_Init_Master(I2C_100KHZ); // Inicializa el protocolo I2C
    MPU6050_Init();
    Servo_Init(); // Inicializa la funcion de los servos
    //LCD_Init();
    Servo_1_Write(0); // Servo 1, 0°
    __delay_ms(1000);
    while (1) {

        value = map(v1, -10, 10, 180, 0);

        Servo_1_Write(0); // Servo 1, 0°
        __delay_ms(1000);
       Servo_1_Write(90); // Servo 1, 0°
        __delay_ms(1000);
        Servo_1_Write(180); // Servo 1, 0°
        __delay_ms(1000);

    }
}
