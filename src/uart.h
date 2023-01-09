/*********************************************************************************\
*
* MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
* MM   MM   MM   SS             WW   WW   WW   SCHULE
* MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
* MM   MM   MM             SS   WW   WW   WW
* MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: uart.h
*
* Projekt  : Uart Driver
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
* Copyright: MSW, AE3
*
* Beschreibung:
* =============
* Treiber für die USART Schnitstelle der Atmel AVR Mikrocontroller
*
* Portbelegung:
* =============
* UART 2:   Serielle verbindung
*
* Verlauf:
* ========
* Datum:      Autor:         Version   Grund der Änderung:
* 01.07.2022  J. Bolli       V1.0      Neuerstellung
*
\*********************************************************************************/


#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define UBRR FOSC/16/BAUD-1






void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void USART_Transmit_Array (uint8_t * data, uint8_t len);

#endif /* INCFILE1_H_ */