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

static inline void
wdt_reset(void) { __asm__ __volatile__ ("wdr\n"); }

static inline void
wdt_config(uint8_t v)
{
	WDTCSR = _BV(WDCE) | _BV(WDE);
	WDTCSR = v;
}

static inline void
wdt_off(void)         { wdt_config(0x00); }
static inline void
wdt_timer_16ms(void)  { wdt_config(_BV(WDIE)); }
static inline void
wdt_timer_32ms(void)  { wdt_config(_BV(WDIE) | _BV(WDP0)); }
static inline void
wdt_timer_64ms(void)  { wdt_config(_BV(WDIE) | _BV(WDP1)); }
static inline void
wdt_timer_125ms(void) { wdt_config(_BV(WDIE) | _BV(WDP1) | _BV(WDP0)); }
static inline void
wdt_timer_250ms(void) { wdt_config(_BV(WDIE) | _BV(WDP2)); }
static inline void
wdt_timer_500ms(void) { wdt_config(_BV(WDIE) | _BV(WDP2) | _BV(WDP0)); }
static inline void
wdt_timer_1s(void)    { wdt_config(_BV(WDIE) | _BV(WDP2) | _BV(WDP1)); }
static inline void
wdt_timer_2s(void)    { wdt_config(_BV(WDIE) | _BV(WDP2) | _BV(WDP1) | _BV(WDP0)); }
static inline void
wdt_timer_4s(void)    { wdt_config(_BV(WDIE) | _BV(WDP3)); }
static inline void
wdt_timer_8s(void)    { wdt_config(_BV(WDIE) | _BV(WDP3) | _BV(WDP0)); }

static inline void
wdt_reset_16ms(void)  { wdt_config(_BV(WDE)); }
static inline void
wdt_reset_32ms(void)  { wdt_config(_BV(WDE) | _BV(WDP0)); }
static inline void
wdt_reset_64ms(void)  { wdt_config(_BV(WDE) | _BV(WDP1)); }
static inline void
wdt_reset_125ms(void) { wdt_config(_BV(WDE) | _BV(WDP1) | _BV(WDP0)); }
static inline void
wdt_reset_250ms(void) { wdt_config(_BV(WDE) | _BV(WDP2)); }
static inline void
wdt_reset_500ms(void) { wdt_config(_BV(WDE) | _BV(WDP2) | _BV(WDP0)); }
static inline void
wdt_reset_1s(void)    { wdt_config(_BV(WDE) | _BV(WDP2) | _BV(WDP1)); }
static inline void
wdt_reset_2s(void)    { wdt_config(_BV(WDE) | _BV(WDP2) | _BV(WDP1) | _BV(WDP0)); }
static inline void
wdt_reset_4s(void)    { wdt_config(_BV(WDE) | _BV(WDP3)); }
static inline void
wdt_reset_8s(void)    { wdt_config(_BV(WDE) | _BV(WDP3) | _BV(WDP0)); }

static inline uint8_t
wdt_interrupt_flag(void)       { return WDTCSR & _BV(WDIF); }
static inline void
wdt_interrupt_flag_clear(void) { WDTCSR |= _BV(WDIF); }

#define wdt_interrupt()       ISR(WDT_vect)
#define wdt_interrupt_naked() ISR(WDT_vect, ISR_NAKED)
#define wdt_interrupt_empty() EMPTY_INTERRUPT(WDT_vect)
