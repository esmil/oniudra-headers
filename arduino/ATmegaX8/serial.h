/*
 * This file is part of oniudra-headers.
 *
 * oniudra-headers is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * oniudra-headers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with oniudra-headers.  If not, see <http://www.gnu.org/licenses/>.
 */

/* baud settings */
static inline void
serial_baud_2400(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 832;
}

static inline void
serial_baud_4800(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 416;
}

static inline void
serial_baud_9600(void)
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = 103;
}

static inline void
serial_baud_14400(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 138;
}

static inline void
serial_baud_19200(void)
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = 51;
}

static inline void
serial_baud_28800(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 68;
}

static inline void
serial_baud_38400(void)
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = 25;
}

static inline void
serial_baud_57600(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 34;
}

static inline void
serial_baud_115200(void)
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = 16;
}

static inline void
serial_baud_250k(void)
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = 3;
}

static inline void
serial_baud_500k(void)
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = 1;
}

/* bit size */
static inline void
serial_bits_5(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C & ~(_BV(UCSZ01) | _BV(UCSZ00));
}

static inline void
serial_bits_6(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UCSZ01))) | _BV(UCSZ00);
}

static inline void
serial_bits_7(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UCSZ00))) | _BV(UCSZ01);
}

static inline void
serial_bits_8(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_bits_9(void)
{
	UCSR0B |= _BV(UCSZ02);
	UCSR0C = UCSR0C | _BV(UCSZ01) | _BV(UCSZ00);
}

/* parity */
static inline void
serial_parity_off(void)
{
	UCSR0C = UCSR0C & ~(_BV(UPM01) | _BV(UPM00));
}

static inline void
serial_parity_even(void)
{
	UCSR0C = (UCSR0C & ~(_BV(UPM00))) | _BV(UPM01);
}

static inline void
serial_parity_odd(void)
{
	UCSR0C = UCSR0C | _BV(UPM01) | _BV(UPM00);
}

/* stop bits */
static inline void
serial_stopbits_1(void) { UCSR0C &= ~(_BV(USBS0)); }
static inline void
serial_stopbits_2(void) { UCSR0C |= _BV(USBS0); }

/* combined mode settings */
static inline void
serial_mode_8n1(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM01) | _BV(UPM00) | _BV(USBS0)))
	       | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8e1(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM00) | _BV(USBS0)))
	       | _BV(UPM01) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8o1(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(USBS0)))
	       | _BV(UPM01) | _BV(UPM00) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8n2(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM01) | _BV(UPM00)))
	       | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8e2(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM00)))
	       | _BV(UPM01) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8o2(void)
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C
	       | _BV(UPM01) | _BV(UPM00) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

/* receiver and transmitter */
static inline void
serial_receiver_enable(void)     { UCSR0B |= _BV(RXEN0); }
static inline void
serial_receiver_disable(void)    { UCSR0B &= ~(_BV(RXEN0)); }
static inline void
serial_transmitter_enable(void)  { UCSR0B |= _BV(TXEN0); }
static inline void
serial_transmitter_disable(void) { UCSR0B &= ~(_BV(TXEN0)); }

/* interrupts */
static inline void
serial_interrupt_dre_enable(void)  { UCSR0B |= _BV(UDRIE0); }
static inline void
serial_interrupt_dre_disable(void) { UCSR0B &= ~(_BV(UDRIE0)); }
static inline uint8_t
serial_interrupt_dre_enabled(void) { return UCSR0B & _BV(UDRIE0); }
static inline void
serial_interrupt_rx_enable(void)   { UCSR0B |= _BV(RXCIE0); }
static inline void
serial_interrupt_rx_disable(void)  { UCSR0B &= ~(_BV(RXCIE0)); }
static inline uint8_t
serial_interrupt_rx_enabled(void)  { return UCSR0B & _BV(RXCIE0); }
static inline void
serial_interrupt_tx_enable(void)   { UCSR0B |= _BV(TXCIE0); }
static inline void
serial_interrupt_tx_disable(void)  { UCSR0B &= ~(_BV(TXCIE0)); }
static inline uint8_t
serial_interrupt_tx_enabled(void)  { return UCSR0B & _BV(TXCIE0); }

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
serial_readable(void)       { return UCSR0A & _BV(RXC0); }
static inline uint8_t
serial_read(void)           { return UDR0; }
static inline uint8_t
serial_writeable(void)      { return UCSR0A & _BV(UDRE0); }
static inline void
serial_write(uint8_t c) { UDR0 = c; }
