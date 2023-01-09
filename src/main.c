#include "ws2812.h"
#include "ADC.h"
#include "stdint.h"
#include "effects.h"
#include "scale.h"
#include <util/delay.h>

#define SOFTWARE_CLOCK 20

int main ()
{
    rgb_color strip[LED_COUNT];
    clearStrip(strip);
    uint8_t mic = 0;
    uint8_t res = 0;
    uint16_t refreshConter = 0;




    ADC_init();
    led_strip_write(strip);
    while (1)
    {
        mic = ADC_read(0);

        if (refreshConter >= 200)
        {
            res = bufferedData(mic);
            refreshConter = 0;

        }

        fillTo(strip, res);
        led_strip_write(strip);

        _delay_ms(SOFTWARE_CLOCK);
        refreshConter += SOFTWARE_CLOCK;
    }
    
}