
#include <mega32.h>
#include <delay.h>
#include <lcd.h>
#include <stdio.h>

#asm 
.equ __lcd_port=0x15
#endasm


int value = 0;
char buf[4];
int i = 0;
int j = 0;

void main(void)
{

DDRA= 0x00;
lcd_init(16);
lcd_clear();


while (1)
    { 
           
        for(i = 0; i < 2; i++){
            for(j = 15; j >= 0; j--){
                value = (PINA.0 * 1) + (PINA.1 * 2) + (PINA.2 * 4) + (PINA.3 * 8) + (PINA.4 * 16) + (PINA.5 * 32) + (PINA.6 * 64) + (PINA.7 * 128);
                sprintf(buf,"%d",value);
                lcd_clear();
                lcd_gotoxy(j,i);
                lcd_puts(buf);
                delay_ms(250);
            }
           
        }
        
    }
}
