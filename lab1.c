/* 
filename: lab1.c
ECE-231 Assignment #1
Assigned Wednesday 2/22/23
Lab check: Friday 3/3 Due: 11:59 pm Sunday 3/5/23

Description:
• blink a red LED at a 5 Hz rate when a push-button switch is pressed
• blink a green LED at a 5 Hz rate when a second push-button switch is pressed
• blink red and green LEDs simultaneously when a third push-button switch is pressed
• do nothing (no blinking) when more than 1 button is simultaneously pressed.
• both LEDs off when no buttons are pressed

Date        Code Author     Lab Collabarator      
2/27/2023   Ken Su          John Works

"All the code was written by Ken Su and Ken Su alone. None of the code was share to anyone nor any third party besides the professors and the TAs."
Huan-Cheng (Ken), Su : 33298385
*/

#include <avr/io.h>
#include <util/delay.h>
#define MYDELAY 100                                                             // define a vairable called delay so you dpn't have to change each delay number by number

int main(void){
    DDRD = 1<<DDD6|1<<DDD7;                                                     // Set D6 & D7 as outputs                                   
    PORTD = 1<<PORTD2|1<<PORTD3|1<<PORTD4;                                      // Set pull up on D2 , D3 , D4 : switch1 , switch 2 , switch 3

    while (1)       
    {

        // PIN D3 = SWICH 1
        // PORT D6 = LIGHT 1
        if ((PIND & (1<<PIND3)) == 0){                                          // If the switch is pressed, The condition is duplicated again because the second button comes after the function is called
            while((PIND & (1<<PIND3)) == 0){                                    // while the switch is pressed; 0, 
                if((PIND & (1<<PIND4)) != 0 && (PIND & (1<<PIND2)) != 0){       // If none of the other switches are pressed: 
                    PORTD |= (1<<PORTD6);                                       // Light on
                    _delay_ms(MYDELAY);                                         // Hold light for MYDELAY milliseconds
                    PORTD &= ~(1<<PORTD6);                                      // Light off
                    _delay_ms(MYDELAY);                                         // Lightg off for MYDELAY milliseconds
                } else {                                                        // else (the the other buttons are also pressed):
                    break;                                                      // break out of the loop
                }
            }
        } else {
            PORTD &= ~(1<<PORTD6);                                              // Turn light 1 off
            PORTD &= ~(1<<PORTD7);                                              // Turn light 2 off
        }

        // PIN D4 = SWICH 2
        // PORT D7 = LIGHT 2
        if ((PIND & (1<<PIND4)) == 0){
            while((PIND & (1<<PIND4)) == 0){
                if((PIND & (1<<PIND3)) != 0 && (PIND & (1<<PIND2)) != 0){
                    PORTD |= (1<<PORTD7); 
                    _delay_ms(MYDELAY);
                    PORTD &= ~(1<<PORTD7);
                    _delay_ms(MYDELAY);
                } else {
                    break;
                }
            }
        } else {
            PORTD &= ~(1<<PORTD6);
            PORTD &= ~(1<<PORTD7);
        }

        // PIN D2 = SWICH 3
        // PORT D6 = LIGHT 1 , PORT D7 = LIGHT 2
        if ((PIND & (1<<PIND2)) == 0){
            while((PIND & (1<<PIND2)) == 0){
                if((PIND & (1<<PIND3)) != 0 && (PIND & (1<<PIND4)) != 0){
                    PORTD |= (1<<PORTD6); 
                    PORTD |= (1<<PORTD7); 
                    _delay_ms(MYDELAY);
                    PORTD &= ~(1<<PORTD6);
                    PORTD &= ~(1<<PORTD7);
                    _delay_ms(MYDELAY);
                } else {
                    break;
                }
            }
        } else {
            PORTD &= ~(1<<PORTD6);
            PORTD &= ~(1<<PORTD7);
        }

    }
    return(0);

}
