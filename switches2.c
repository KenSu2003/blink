#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRD = 1<<DDD6|1<<DDD7;
    PORTD = 1<<PORTD3|1<<PORTD4;

    while (1)
    {
        // PIN D3 = SWICH 1
        // PORT D6 = LIGHT 1
        if ((PIND & (1<<PIND3)) == 0){
            PORTD |= (1<<PORTD6);
        } else {
            PORTD &= ~(1<<PORTD6);
        }

        // PIN D4 = SWICH 2
        // PORT D7 = LIGHT 2
        if ((PIND & (1<<PIND4)) == 0){
            PORTD |= (1<<PORTD7);
        } else {
            PORTD &= ~(1<<PORTD7);
        }
    }
    return(0);

}