#include "scale.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void addToBuffer (uint8_t data)
{
    static uint8_t bufferIndex = 0;
    uint32_t sum = 0;

    buffer[bufferIndex] = data;
    bufferIndex++;
    
    if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;
}

uint8_t getSmallest ()
{
    uint8_t small = 255;

    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] < small) small = buffer[i];
    }

    return small;
}

uint8_t getBiggest ()
{
    uint8_t big = 0;

    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] > big) big = buffer[i];
    }

    return big;
}

uint8_t scaleData (uint8_t value, uint8_t max)
{
    uint8_t result = 0;

    result = map(value, 0, 255, 0, 16);


    return result;
}