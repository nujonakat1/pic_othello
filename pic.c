// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include<xc.h>
#define _XTAL_FREQ 8000000

void PICinit(){
  OSCCON = 0b01110000;
  ANSELA = 0b00000000;
  ANSELB = 0b00000000;
  TRISA  = 0b00000000;
  TRISB  = 0b00000000;
  TRISC  = 0b00000000;
  PORTA  = 0b00000000;    //2????????????????????????
  PORTB  = 0x00;          //16????????????????????????
  PORTC  = 0;            //10????????????????????????
}

void pwmLED(int duty,int time){
    int i=0;
    int j=0;
    for(j=1;j<time;j++){
        for(i=1;i<100;i++){
            if(i<duty){
                RA1 = 1;    //LED?????????
            }else{
                RA1 = 0;    //LED?????????
            }
            __delay_us(100);
        }
    }

}

int main(void){
  PICinit();      //PIC????????????
  while(1){
      for(int i = 1;i<100;i++){     //???????????????
          pwmLED(i,4);
      }
      for(int i = 100;i>1;i--){     //????????????
          pwmLED(i,2);
      }
  }


  return 0;
}

