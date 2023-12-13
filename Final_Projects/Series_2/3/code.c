
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;

long value = 0;

void main(void)
{


DDRC= 0xFF;
DDRD= 0xFF;
DDRB= 0x00;
DDRA= 0x00;


while (1)
    {
      
    value = (PINA.0 * 1) + (PINA.1 * 2) + (PINA.2 * 4) + (PINA.3 * 8) + (PINA.4 * 16) + (PINA.5 * 32) + (PINA.6 * 64) + (PINA.7 * 128);
    value += (PINB.0 * 256) + (PINB.1 * 512) + (PINB.2 * 1024) + (PINB.3 * 2048) + (PINB.4 * 4096) + (PINB.5 * 8192) + (PINB.6 * 16384) + (PINB.7 * 32768);
    
    PORTD = 0x10;
    PORTC = pat[value % 10];
    delay_ms(10);
    
    PORTD = 0x08;
    PORTC = pat[(value % 100) / 10];
    delay_ms(10);
    
    PORTD = 0x04;
    PORTC = pat[(value % 1000) / 100];
    delay_ms(10);
    
    PORTD = 0x02;
    PORTC = pat[(value % 10000) / 1000];
    delay_ms(10);
    
    PORTD = 0x01;
    PORTC = pat[(value % 100000) / 10000];
    delay_ms(10);
    

        
    }
}
