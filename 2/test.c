
#include <mega32.h>
#include <delay.h>
#define led0 PORTB.0
#define led1 PORTB.1
#define led2 PORTB.2
#define led3 PORTB.3
#define led4 PORTB.4
#define led5 PORTB.5
#define led6 PORTB.6
#define led7 PORTB.7

void main(void)
{

DDRB= 0xFF; //1111-1111 => FF
while (1)
    {
       led0 = 1;
       delay_ms(1000);
       led0 = 0;
       delay_ms(1000); 
       
       led1 = 1;
       delay_ms(1000);
       led1 = 0;
       delay_ms(1000); 
       
       led2 = 1;
       delay_ms(1000);
       led2 = 0;
       delay_ms(1000); 
                      
       led3 = 1;
       delay_ms(1000);
       led3 = 0;
       delay_ms(1000); 
       
       led4 = 1;
       delay_ms(1000);
       led4 = 0;
       delay_ms(1000);
       
       led5 = 1;
       delay_ms(1000);
       led5 = 0;
       delay_ms(1000);  
       
       led6 = 1;
       delay_ms(1000);
       led6 = 0;
       delay_ms(1000); 
       
       led7 = 1;
       delay_ms(1000);
       led7 = 0;
       delay_ms(1000); 
    }
}
