#ifndef __AVR_ATmega2560__
    #define __AVR_ATmega2560__
#endif

#include "embed_led/embed_led.h"

int main(void) {
    init();
    bounce_animation(500, 50, 2000);
}
