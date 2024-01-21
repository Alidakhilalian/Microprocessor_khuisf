
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;
int seg = 0;

void main(void)
{

DDRB= 0xFF; //1111-1111 => FF
DDRC= 0xFF;
DDRA= 0x00;
while (1)
    {
        
       seg = (PINA.0 * 1) + (PINA.1 * 2) + (PINA.2 * 4) + (PINA.3 * 8);
       seg += (PINA.4 * 16) + (PINA.5 * 32) + (PINA.6 * 64) + (PINA.7 * 128); 
       PORTC = pat[seg % 16];
       PORTB = pat[seg / 16]; 
       delay_ms(1);
    }
}