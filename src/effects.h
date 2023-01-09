#ifndef _EFFECTS
#define _EFFECTS

#include "ws2812.h"
#include <stdint.h>
void clearStrip (rgb_color * strip);
void fillTo (rgb_color * strip, uint8_t count);

#endif