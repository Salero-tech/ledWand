#include "ws2812.h"
#include "ADC.h"
#include "stdint.h"
#include "effects.h"
#include "scale.h"
#include <util/delay.h>
#include "uart.h"


#define SOFTWARE_CLOCK 20

int main ()
{
    rgb_color strip[LED_COUNT_PER_ROW];
    rgb_color targetStrip[LED_COUNT];
    clearStrip(strip);
    clearStrip(targetStrip);
    uint8_t mic = 0;
    uint8_t res = 0;
    uint16_t refreshConter = 0;



    USART_Init(UBRR);
    ADC_init();
    led_strip_write(targetStrip);
    while (1)
    {
        mic = 255 - ADC_read(0);
        

        if (refreshConter >= 50)
        {
            res = scaleData(mic, LED_COUNT);
            refreshConter = 0;
        }

        clearStrip(strip);
        fillRainbowTo(strip, res);
        toRowReverse(targetStrip, strip);
        led_strip_write(targetStrip);

        

        _delay_ms(SOFTWARE_CLOCK);
        refreshConter += SOFTWARE_CLOCK;
    }
    
}