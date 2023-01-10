#include "effects.h"

void clearStrip (rgb_color * strip)
{
    for (uint8_t i = 0; i < LED_COUNT; i++){
        strip[i].red = 0;
        strip[i].green = 0;
        strip[i].blue = 0;
    }
}

void fillTo (rgb_color * strip, uint8_t count)
{
    for (uint8_t i = 0; i < count; i++){
        strip[i].red = 50;
        strip[i].green = 0;
        strip[i].blue = 0;
    }
}