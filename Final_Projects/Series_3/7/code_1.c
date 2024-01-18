
#include <mega32.h>
#include <delay.h>
#include <stdio.h>


char temp;


void main(void)
{

#asm ("sei")

UCSRA = 0x00;
UCSRB = 0b10011100; //0x98; //enable interrupt //UCSZ2
UCSRC = 0x10100110; //Even Parity

UBRRH = 0;
UBRRL = 51;

DDRB = 0xff;



while(1){ 
        
        putchar(0x55);
        delay_ms(1000); 
        putchar(0x00);
        delay_ms(1000);
        
    }
}

interrupt[USART_RXC] void usart_rx_isr(){

   temp = getchar();
   PORTB = temp;

}
