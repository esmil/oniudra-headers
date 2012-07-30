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

#ifndef _ARDUINO_SPI_H
#define _ARDUINO_SPI_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define SS   10
#define MOSI 11
#define MISO 12
#define SCLK 13

enum spi_intstatus {
	SPI_INTERRUPT_DISABLED = 0,
	SPI_INTERRUPT_ENABLED  = _BV(SPIE),
};

enum spi_role {
	SPI_SLAVE  = 0,
	SPI_MASTER = _BV(MSTR),
};

enum spi_endianess {
	SPI_MSB = 0,
	SPI_LSB = _BV(DORD),
};

enum spi_mode {
	SPI_MODE0 = 0,
	SPI_MODE1 = _BV(CPHA),
	SPI_MODE2 = _BV(CPOL),
	SPI_MODE3 = _BV(CPOL) | _BV(CPHA),
};

enum spi_clock {
	SPI_CLOCK_D4   = 0,
	SPI_CLOCK_D16  = _BV(SPR0),
	SPI_CLOCK_D64  = _BV(SPR1),
	SPI_CLOCK_D128 = _BV(SPR1) | _BV(SPR0),
};

static inline void
spi_off(void)         { SPCR = 0; }
static inline void
spi_config(uint8_t v) { SPCR = _BV(SPE) | v; }

static inline void
spi_interrupt_enable(void)    { SPCR |= _BV(SPIE); }
static inline void
spi_interrupt_disable(void)   { SPCR &= ~(_BV(SPIE)); }
static inline uint8_t
spi_interrupt_enabled(void)   { return SPCR & _BV(SPIE); }

#define spi_interrupt() ISR(SPI_STC_vect)
#define spi_interrupt_naked() ISR(SPI_STC_vect, ISR_NAKED)
#define spi_interrupt_empty() EMPTY_INTERRUPT(SPI_STC_vect)

static inline uint8_t
spi_interrupt_flag(void)       { return SPSR & _BV(SPIF); }
static inline uint8_t
spi_write_collision(void)      { return SPSR & _BV(WCOL); }

static inline void
spi_double_speed_disable(void) { SPSR = 0; }
static inline void
spi_double_speed_enable(void)  { SPSR = _BV(SPI2X); }

static inline uint8_t
spi_read(void)                 { return SPDR; }
static inline void
spi_write(uint8_t c)           { SPDR = c; }

#endif
