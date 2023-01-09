/*********************************************************************************\
*
* MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
* MM   MM   MM   SS             WW   WW   WW   SCHULE
* MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
* MM   MM   MM             SS   WW   WW   WW
* MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: uart.c
*
* Projekt  : Uart Driver
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
* Copyright: MSW, AE3
*
* Beschreibung:
* =============
* Treiber f�r die USART Schnitstelle der Atmel AVR Mikrocontroller
*
* Portbelegung:
* =============
* UART 2:   Serielle verbindung
*
* Verlauf:
* ========
* Datum:      Autor:         Version   Grund der �nderung:
* 01.07.2022  J. Bolli       V1.0      Neuerstellung
*
\*********************************************************************************/
#include <avr/io.h>
#include "uart.h"
#include <avr/interrupt.h>

#include <util/atomic.h>



void USART_Init( unsigned int ubrr){
    /* Set baud rate */
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
    /* Set frame format: 8data, 1stop bit */
    UCSR0C = (0<<USBS0)|(3<<UCSZ00);
} // USART_Init


void USART_Transmit( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) )
    ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

unsigned char USART_Receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
    ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_Transmit_Array (uint8_t * data, uint8_t len)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        for (uint8_t i = 0; i < len; i++)
        {
            USART_Transmit(data[i]);
        }
    }
    
}