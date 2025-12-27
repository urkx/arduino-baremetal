#include <avr/io.h>
#include <util/delay.h>
void init();
void toggle(int delay);
void bounce_animation(int initial_delay, int min_delay, int max_delay);