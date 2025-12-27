#include "embed_led.h"

// Initialize Arduino embedded LED
void init() {
    // set PORTB7 as output
    DDRB = DDRB | (1 << DDB7);
}

// Toggles the embedded LED
// with the given delay in ms
void toggle(int delay) {
    PORTB |= (1 << PORTB7);
    _delay_ms(delay);
    PORTB &= ~(1 << PORTB7);
    _delay_ms(delay);
}

// Executes a bouncing animation with the
// given initial, minimum and maximum delay.
//
// It only runs with avr-gcc optimization disabled
void bounce_animation(int initial_delay, int min_delay, int max_delay) {
    int delay = initial_delay;
    char inc = 1;

    // loop
    while(1) {
        
        toggle(delay);
        
        if(inc == 1) {
            delay = delay * 2;
            if(delay >= max_delay) {
                inc = 0;
                delay = max_delay;
            }
        }

        if(inc == 0) {
            delay = delay / 2;
            if(delay <= min_delay) {
                inc = 1;
                delay = min_delay;
            }
        }

    }
}

