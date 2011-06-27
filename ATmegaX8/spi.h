/*
 * This file is part of arduino-headers.
 *
 * arduino-headers is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * arduino-headers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with arduino-headers.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ARDUINO_SPI_H
#define _ARDUINO_SPI_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

static inline void
spi_interrupt_enable(void)    { SPCR |= _BV(SPIE); }
static inline void
spi_interrupt_disable(void)   { SPCR &= ~(_BV(SPIE)); }
static inline uint8_t
spi_interrupt_enabled(void)   { return SPCR & _BV(SPIE); }
static inline void
spi_enable(void)              { SPCR |= _BV(SPE); }
static inline void
spi_disable(void)             { SPCR &= ~(_BV(SPE)); }
static inline void
spi_data_order_lsb(void)      { SPCR |= _BV(DORD); }
static inline void
spi_data_order_msb(void)      { SPCR &= ~(_BV(DORD)); }
static inline void
spi_mode_master(void)         { SPCR |= _BV(MSTR); }
static inline void
spi_mode_slave(void)          { SPCR &= ~(_BV(MSTR)); }
static inline void
spi_clock_polarity_high(void) { SPCR |= _BV(CPOL); }
static inline void
spi_clock_polarity_low(void)  { SPCR &= ~(_BV(CPOL)); }
static inline void
spi_clock_phase_first(void)   { SPCR |= _BV(CPHA); }
static inline void
spi_clock_phase_last(void)    { SPCR &= ~(_BV(CPHA)); }

static inline void
spi_clock_d4(void)
{
	SPCR = SPCR & ~(_BV(SPR1) | _BV(SPR0));
}

static inline void
spi_clock_d16(void)
{
	SPCR = (SPCR & ~(_BV(SPR1))) | _BV(SPR0);
}

static inline void
spi_clock_d64(void)
{
	SPCR = (SPCR & ~(_BV(SPR0))) | _BV(SPR1);
}

static inline void
spi_clock_d128(void)
{
	SPCR = SPCR | _BV(SPR1) | _BV(SPR1);
}

#define spi_interrupt() ISR(SPI_STC_vect)
#define spi_interrupt_naked() ISR(SPI_STC_vect, ISR_NAKED)
#define spi_interrupt_empty() EMPTY_INTERRUPT(SPI_STC_vect)

static inline uint8_t
spi_interrupt_flag(void)  { return SPSR & _BV(SPIF); }
static inline uint8_t
spi_write_collision(void) { return SPSR & _BV(WCOL); }

static inline void
spi_clock_t2(void)        { SPSR |= _BV(SPI2X); }
static inline void
spi_clock_t1(void)        { SPSR &= ~(_BV(SPI2X)); }

static inline uint8_t
spi_read(void)            { return SPDR; }
static inline void
spi_write(uint8_t c)  { SPDR = c; }

#endif
