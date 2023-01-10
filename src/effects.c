#include "effects.h"
#include "ws2812.h"

void clearStrip(rgb_color * strip)
{
    for (uint8_t i = 0; i < LED_COUNT_PER_ROW; i++)
    {
        strip[i].red = 0;
        strip[i].green = 0;
        strip[i].blue = 0;
    }
}

void fillTo(rgb_color * strip, uint8_t count)
{
    for (uint8_t i = 0; i < count; i++)
    {
        strip[i].red = 50;
        strip[i].green = 0;
        strip[i].blue = 0;
    }
}

void fillRainbowTo(rgb_color * strip, uint8_t count)
{
    double rgb[3];
    for (uint8_t i = 0; i < count; i++)
    {
        hsvToRgb((double)(100/LED_COUNT_PER_ROW) * i, 1, 1, 50, rgb);
        strip[i].red = rgb[0];
        strip[i].green = rgb[1];
        strip[i].blue = rgb[2];
    }
}

void toRow(rgb_color *target, rgb_color * strip)
{
    uint8_t stripIndex = 0;
    for (uint8_t i = 0; i < LED_COUNT; i++)
    {
        target[i] = strip[stripIndex];

        stripIndex++;
        if (stripIndex >= LED_COUNT_PER_ROW)
            stripIndex = 0;
    }
}

void toRowReverse(rgb_color *target, rgb_color * strip)
{
    int8_t stripIndex = 0;
    uint8_t foreward = 1;
    for (uint8_t i = 0; i < LED_COUNT; i++)
    {
        target[i] = strip[stripIndex];

        if (foreward)
        {
            stripIndex++;
            if (stripIndex >= LED_COUNT_PER_ROW)
            {
                stripIndex = LED_COUNT_PER_ROW - 1;
                foreward = 0;
            }
        }
        else
        {
            stripIndex--;
            if (stripIndex < 0)
            {
                stripIndex = 0;
                foreward = 1;
            }
        }
    }
}

void hsvToRgb(double hue, double brightness, double saturation, uint8_t maxBrightness, double * rgb2)
{

    double colorX, colorC, colorM;
    double r2, g2, b2;
    colorC = brightness * saturation; // zwischen resultat zur berechnung von HSV
    colorM = brightness - colorC; // zwischen resultat zur berechnung von HSV
    colorX = colorC * (1 - fabs(fmod((hue / 60), 2) - 1)); // zwischen resultat zur berechnung von HSV

    if (hue < 60)
    {
        r2 = 1;
        g2 = colorX;
        b2 = 0;
    }

    if ((hue >= 60) && (hue < 120))
    {
        r2 = colorX;
        g2 = 1;
        b2 = 0;
    }

    if ((hue >= 120) && (hue < 180))
    {
        r2 = 0;
        g2 = 1;
        b2 = colorX;
    }

    if ((hue >= 180) && (hue < 240))
    {
        r2 = 0;
        g2 = colorX;
        b2 = 1;
    }

    if ((hue >= 240) && (hue < 300))
    {
        r2 = colorX;
        g2 = 0;
        b2 = 1;
    }

    if ((hue >= 300) && (hue <= 360))
    {
        r2 = 1;
        g2 = 0;
        b2 = colorX;
    }

    rgb2[0] = (r2 + colorM) * maxBrightness;

    rgb2[1] = (g2 + colorM) * maxBrightness;

    rgb2[2] = (b2 + colorM) * maxBrightness;
}
