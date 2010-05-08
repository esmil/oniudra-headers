#ifndef _ARDUINO_SPI_H
#define _ARDUINO_SPI_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

static inline void
spi_interrupt_enable()    { SPCR |= _BV(SPIE); }
static inline void
spi_interrupt_disable()   { SPCR &= ~(_BV(SPIE)); }
static inline uint8_t
spi_interrupt_enabled()   { return SPCR & _BV(SPIE); }
static inline void
spi_enable()              { SPCR |= _BV(SPE); }
static inline void
spi_disable()             { SPCR &= ~(_BV(SPE)); }
static inline void
spi_data_order_lsb()      { SPCR |= _BV(DORD); }
static inline void
spi_data_order_msb()      { SPCR &= ~(_BV(DORD)); }
static inline void
spi_mode_master()         { SPCR |= _BV(MSTR); }
static inline void
spi_mode_slave()          { SPCR &= ~(_BV(MSTR)); }
static inline void
spi_clock_polarity_high() { SPCR |= _BV(CPOL); }
static inline void
spi_clock_polarity_low()  { SPCR &= ~(_BV(CPOL)); }
static inline void
spi_clock_phase_first()   { SPCR |= _BV(CPHA); }
static inline void
spi_clock_phase_last()    { SPCR &= ~(_BV(CPHA)); }

static inline void
spi_clock_d4()
{
	SPCR = SPCR & ~(_BV(SPR1) | _BV(SPR0));
}

static inline void
spi_clock_d16()
{
	SPCR = (SPCR & ~(_BV(SPR1))) | _BV(SPR0);
}

static inline void
spi_clock_d64()
{
	SPCR = (SPCR & ~(_BV(SPR0))) | _BV(SPR1);
}

static inline void
spi_clock_d128()
{
	SPCR = SPCR | _BV(SPR1) | _BV(SPR1);
}

#define spi_interrupt() ISR(SPI_STC_vect)
#define spi_interrupt_naked() ISR(SPI_STC_vect, ISR_NAKED)
#define spi_interrupt_empty() EMPTY_INTERRUPT(SPI_STC_vect)

static inline uint8_t
spi_interrupt_flag()  { return SPSR & _BV(SPIF); }
static inline uint8_t
spi_write_collision() { return SPSR & _BV(WCOL); }

static inline void
spi_clock_t2()        { SPSR |= _BV(SPI2X); }
static inline void
spi_clock_t1()        { SPSR &= ~(_BV(SPI2X)); }

static inline uint8_t
spi_read()            { return SPDR; }
static inline void
spi_write(uint8_t c)  { SPDR = c; }

#endif
