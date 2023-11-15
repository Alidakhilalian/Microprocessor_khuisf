
#include <mega32.h>
#include <delay.h>
#define led0 PORTB.0
#define led1 PORTB.1
#define led2 PORTB.2
#define led3 PORTB.3
#define led4 PORTB.4

void main(void)
{

DDRB= 0x1F; //1111-1111 => FF
while (1)
    {
       led0 = 1;
       led1 = 0;
       led2 = 0;
       //
       led3 = 0;
       led4 = 1;
       delay_ms(60000);     
       led0 = 0;
       led1 = 1;
       delay_ms(10000);
       led1 = 0;
       led2 = 1;
       //
       led3 = 1;
       led4 = 0;
       delay_ms(30000);
      
    }
}
