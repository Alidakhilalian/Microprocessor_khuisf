
#include <mega32.h>
#include <delay.h>

flash unsigned char pat[16] = {0xBF, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0xFD, 0x07, 0xFF, 0xEF, 0xF7, 0xFC, 0xB9, 0x5C, 0xF9 ,0xF1 } ;

int i = 0;
int bilink = 0;

void main(void)
{

DDRA= 0xFF;
DDRC= 0xFF;
DDRD= 0xFF;

while (1)
    {   
        PORTA.2 = 0;
        PORTA.3 = 0;
        PORTA.0 = 1;
        PORTA.4 = 1;
        for(i = 60; i > 0; i--){
            PORTC = pat[i / 10];
            PORTD = pat[i % 10];
            delay_ms(1000);
        }
        
        
        PORTA.0 = 0;
        PORTA.1 = 1;
        for(i = 10; i > 0; i--){
            PORTC = pat[i / 10];
            PORTD = pat[i % 10];
            delay_ms(1000);
        }
        
        PORTA.1 = 0;
        PORTA.2 = 1;
        PORTA.4 = 0;
        PORTA.3 = 1;
        for(i = 60; i > 0; i--){
            PORTC = pat[i / 10];
            PORTD = pat[i % 10];
            if(i <= 10){
                  if(bilink == 0){
                     PORTA.3 = 0;
                     bilink = 1;
                  } else {
                      PORTA.3 = 1;
                      bilink = 0;
                  }
            }
            delay_ms(1000);
        }
        
    }
}
