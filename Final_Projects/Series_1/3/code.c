
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;

int counter = 0;
int step = 0;

void main(void)
{

DDRB= 0xFF;
DDRA= 0xFF;
DDRD= 0x00;
DDRC= 0x00;

while (1)
    {
      step = (PINC.0 * 1) + (PINC.1 * 2) + (PINC.2 * 4) + (PINC.3 * 8) + (PINC.4 * 16) + (PINC.5 * 32) + (PINC.6 * 64) + (PINC.7 * 128);
      if(PIND.0 == 1){
        if(counter >= 0 && counter < 55){
            PORTB = pat[counter / 10];
            PORTA = pat[counter % 10];
            if(PIND.1 == 0){
                counter += step ;
            } else if(PIND.1 == 1 && counter != 0){
                counter -= step; 
            }
            
        }
      }
      if(PIND.2 == 1){
        counter = 0;
      }
        
       delay_ms(500);
    }
}
