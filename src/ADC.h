/*****************************************************************************\
* Dateiname: ADC.h
*
* Projekt : I2C-Balkenanzeige AE3
* Hardware : DA-Simulatorprint, MoccaBoard(MSW)
*
* Copyright: MSW, AE3
*
* Beschreibung:
* Diese ist die Datei, welche ADC des Microcontroller initialisiert und
* Analogwert zu Digitalwert umwandelt.
*
* Datum:	 Autor:		Version,	Grund der �nderung:
* 26.03.2021 B.Ayfer	V1.0		Neuerstellung
*
\*****************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>


void ADC_init(void);
uint16_t ADC_read(uint8_t kanal);




#endif /* ADC_H_ */