#ifndef _EFFECTS
#define _EFFECTS

#include "ws2812.h"
#include <stdint.h>
void clearStrip (rgb_color * strip);
void fillTo (rgb_color * strip, uint8_t count);
void toRow (rgb_color * target, rgb_color * strip);
void toRowReverse (rgb_color * target, rgb_color * strip);
void fillRainbowTo(rgb_color * strip, uint8_t count);
void hsvToRgb(double hue, double brightness, double saturation, uint8_t maxBrightness, double * rgb2);
#endif