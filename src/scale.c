#include "scale.h"

uint8_t bufferedData (uint8_t data)
{
    static uint8_t buffer[20];
    static uint8_t bufferIndex = 0;
    uint32_t sum = 0;

    buffer[bufferIndex] = data;
    bufferIndex++;
    
    if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;

    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        sum += buffer[i];
    }


    return sum / BUFFER_SIZE;
}