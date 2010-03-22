#ifndef _ARDUINO_SERIAL_H
#define _ARDUINO_SERIAL_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* baud settings */
static inline void
serial_baud_9600()
{
	UCSR0A = 0;
	UBRR0H = 0;
	UBRR0L = 103;
}

static inline void
serial_baud_14400()
{
	UCSR0A = _BV(U2X0);
	UBRR0H = 0;
	UBRR0L = 138;
}

static inline void
serial_baud_57600()
{
	UCSR0A = _BV(U2X0);
	UBRR0H = 0;
	UBRR0L = 34;
}

static inline void
serial_baud_250k()
{
	UCSR0A = 0;
	UBRR0H = 0;
	UBRR0L = 3;
}

static inline void
serial_baud_500k()
{
	UCSR0A = 0;
	UBRR0H = 0;
	UBRR0L = 1;
}

/* mode settings */
static inline void
serial_mode_8n1() { UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); }
static inline void
serial_mode_8e1() { UCSR0C = _BV(UPM01) | _BV(UCSZ01) | _BV(UCSZ00); }
static inline void
serial_mode_8o1() { UCSR0C = _BV(UPM01) | _BV(UPM00) | _BV(UCSZ01) | _BV(UCSZ00); }
static inline void
serial_mode_8n2() { UCSR0C = _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00); }
static inline void
serial_mode_8e2() { UCSR0C = _BV(UPM01) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00); }
static inline void
serial_mode_8o2() {
	UCSR0C = _BV(UPM01) | _BV(UPM00) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

/* enable/disable */
static inline void
serial_off()       { UCSR0B = 0; }
static inline void
serial_rx()        { UCSR0B = _BV(RXEN0); }
static inline void
serial_tx()        { UCSR0B = _BV(TXEN0); }
static inline void
serial_rxtx()      { UCSR0B = _BV(RXEN0) | _BV(TXEN0); }

/* interrupts */
static inline void
serial_interrupt_dre_enable()  { UCSR0B |= _BV(UDRIE0); }
static inline void
serial_interrupt_dre_disable() { UCSR0B &= ~(_BV(UDRIE0)); }
static inline void
serial_interrupt_rx_enable()   { UCSR0B |= _BV(RXCIE0); }
static inline void
serial_interrupt_rx_disable()  { UCSR0B &= ~(_BV(RXCIE0)); }
static inline void
serial_interrupt_tx_enable()   { UCSR0B |= _BV(TXCIE0); }
static inline void
serial_interrupt_tx_disable()  { UCSR0B &= ~(_BV(TXCIE0)); }

#define serial_interrupt_dre()       ISR(USART_UDRE_vect)
#define serial_interrupt_dre_naked() ISR(USART_UDRE_vect, ISR_NAKED)
#define serial_interrupt_dre_empty() EMPTY_INTERRUPT(USART_UDRE_vect)
#define serial_interrupt_rx()        ISR(USART_RX_vect)
#define serial_interrupt_rx_naked()  ISR(USART_RX_vect, ISR_NAKED)
#define serial_interrupt_rx_empty()  EMPTY_INTERRUPT(USART_RX_vect)
#define serial_interrupt_tx()        ISR(USART_TX_vect)
#define serial_interrupt_tx_naked()  ISR(USART_TX_vect, ISR_NAKED)
#define serial_interrupt_tx_empty()  EMPTY_INTERRUPT(USART_TX_vect)

static inline uint8_t
serial_readable()       { return UCSR0A & _BV(RXC0); }
static inline uint8_t
serial_read()           { return UDR0; }
static inline uint8_t
serial_writeable()      { return UCSR0A & _BV(UDRE0); }
static inline void
serial_write(uint8_t c) { UDR0 = c; }

#endif