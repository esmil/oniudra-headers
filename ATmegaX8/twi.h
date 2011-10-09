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

#ifndef _ARDUINO_TWI_H
#define _ARDUINO_TWI_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

static inline void
twi_bitrate_set(uint8_t v)
{
	TWBR = v;
}

static inline void
twi_start(void)        { TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN); }
static inline void
twi_stop(void)         { TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN); }
static inline void
twi_continue(void)     { TWCR = _BV(TWINT) | _BV(TWEN); }
static inline void
twi_continue_ack(void) { TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN); }

static inline void
twi_istart(void)        { TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN) | _BV(TWIE); }
static inline void
twi_istop(void)         { TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWIE); }
static inline void
twi_icontinue(void)     { TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWIE); }
static inline void
twi_icontinue_ack(void) { TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE); }

static inline uint8_t
twi_write_collision(void)      { return TWCR & _BV(TWWC); }
static inline uint8_t
twi_interrupt_flag(void)       { return TWCR & _BV(TWINT); }

static inline void
twi_prescale_1(void)           { TWSR &= ~(_BV(TWPS1) | _BV(TWPS0)); }
static inline void
twi_prescale_4(void)           { TWSR = (TWSR & ~(_BV(TWPS1))) | _BV(TWPS0); }
static inline void
twi_prescale_16(void)          { TWSR = (TWSR & ~(_BV(TWPS0))) | _BV(TWPS1); }
static inline void
twi_prescale_64(void)          { TWSR |= _BV(TWPS1) | _BV(TWPS0); }

static inline uint8_t
twi_state(void)                { return TWSR >> 3; }
static inline uint8_t
/* twi_state_isnt(uint8_t v)      { return TWSR ^ v) < 3; } */
twi_state_isnt(uint8_t v)      { return (TWSR & 0xF8) != v; }
static inline void
twi_state_reset(void)          { TWSR &= 0x07; }

static inline void
twi_data_set(uint8_t v)        { TWDR = v; }
static inline uint8_t
twi_data(void)                 { return TWDR; }

static inline void
twi_address_set(uint8_t v)         { TWAR = v << 1; }
static inline void
twi_call_recognition_enable(void)  { TWAR |= _BV(TWGCE); }
static inline void
twi_call_recognition_disable(void) { TWAR &= ~(_BV(TWGCE)); }

static inline void
twi_address_mask_set(uint8_t v)    { TWAMR = v; }

#define twi_interrupt()       ISR(TWI_vect)
#define twi_interrupt_naked() ISR(TWI_vect, ISR_NAKED)
#define twi_interrupt_empty() EMPTY_INTERRUPT(TWI_vect)

#endif
