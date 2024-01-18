
#include <mega32.h>
#include <delay.h>
#include <lcd.h>
#include <stdio.h>

#asm 
.equ __lcd_port=0x15
#endasm


char temp[16];


void main(void)
{

lcd_init(16);
lcd_clear();

UCSRA = 0x00;
UCSRB = 0x18;
UCSRC = 0x86;

UBRRH = 0;
UBRRL = 51;



while(1){ 

        scanf("%s", temp);
        lcd_clear();
        lcd_gotoxy(0,0);
        lcd_puts(temp);
        delay_ms(10);
        
    }
}

