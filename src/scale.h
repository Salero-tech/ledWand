#ifndef SALE_
#define SALE_

#include <stdint.h>

#define BUFFER_SIZE 50

uint8_t buffer[BUFFER_SIZE];

uint8_t scaleData (uint8_t value, uint8_t max);
void addToBuffer (uint8_t data);

#endif /* ADC_H_ */