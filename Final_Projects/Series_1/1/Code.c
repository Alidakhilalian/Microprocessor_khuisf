
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;
//#define led0 PORTB.0


void main(void)
{

DDRB= 0xFF; //1111-1111 => FF
DDRC= 0xFF;
DDRA= 0x00;
while (1)
    {
        
       int seg1 = (PINA.0 * 1) + (PINA.1 * 2) + (PINA.2 * 4) + (PINA.3 * 8);
       int seg2 = (PINA.4 * 1) + (PINA.5 * 2) + (PINA.6 * 4) + (PINA.7 * 8);
       PORTB = pat[seg1]; 
       PORTC = pat[seg2];
       delay_ms(1);
    }
}
