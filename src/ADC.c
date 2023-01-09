/*****************************************************************************\
* Dateiname: ADC.c
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

#include <avr/io.h>                 // ATmega2560v I/O-Definitionen
#include <util/delay.h>				// Standart delay Library



/******************************************************************************\
* <<ADC-init>>
*
* ADC des Microcontroller initialisieren
*
\******************************************************************************/
void ADC_init(void) //Initialisierung der ADC
{
	ADMUX  = 0x40;	//AVCC Als referenz
	DIDR0  = 0x0F;	// IO pins von Potentiometer deaktivieren
	// ADC einschalten, ADC clok = 8MHz / 128, Free runing mode
	ADCSRA = 0b10000111;
}

/******************************************************************************\
* <<ADC_read>>
*
* Liest und wandelt den Analogwert zum Digitalwert
*
* Parameter:
* <<kanal>> = <<kanal des ADC's>>
*
\******************************************************************************/
uint16_t ADC_read(uint8_t kanal)
{
	// Kanal definieren
	ADMUX&=0xf0;
	ADMUX|=kanal&0x07;		//write lsb to ADMUX
	ADCSRB&=~0x08;
	ADCSRB|=kanal&0x08;		//write msb to ADCSRB
	
	ADCSRA |= _BV(ADSC);	 	// ADC Starten
	while(ADCSRA & _BV(ADSC));	// Warten bis Messung abgeschllossen
	
	return ADC;
}