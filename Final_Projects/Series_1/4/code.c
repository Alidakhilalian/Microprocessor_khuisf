
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0x00, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01, 0x03} ;

int input = 0;

void main(void)
{

DDRB= 0xFF;
DDRA= 0x00;

while (1)
    {
        input = (PINA.0 * 1) + (PINA.1 * 2) + (PINA.2 * 4);
        PORTB = pat[input];
        
        delay_ms(10);
    }
}
