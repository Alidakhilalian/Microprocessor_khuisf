#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;

int counter = 0;

void main(void)
{

DDRB= 0xFF;
DDRA= 0xFF;
DDRD= 0x00;

while (1)
    {
        
      if(PIND.0 == 1){
        if(counter >= 0 && counter < 55){
            PORTB = pat[counter / 10];
            PORTA = pat[counter % 10];
            if(PIND.1 == 0){
                counter++;
            } else if(PIND.1 == 1 && counter != 0){
                counter--; 
            }
            
        }
      }
      if(PIND.2 == 1){
        counter = 0;
      }
        
       delay_ms(500);
    }
}