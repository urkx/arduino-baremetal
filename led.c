#ifndef __AVR_ATmega2560__
    #define __AVR_ATmega2560__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    // set PORTB7 as output
    DDRB = DDRB | (1 << DDB7);

    // loop
    while(1) {
        
        // set PORTB5
        PORTB = PORTB | (1 << PORTB7);

        // wait
        _delay_ms(1000);

        // unset PORTB5
        PORTB = PORTB & ~(1 << PORTB7);

        // wait
        _delay_ms(1000);

    }

}