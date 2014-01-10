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

/* macros for factoring out pin mappings */
#define pin_mode_output_(nr) pin##nr##_mode_output()
#define pin_mode_output(nr) pin_mode_output_(nr)
#define pin_mode_input_(nr) pin##nr##_mode_input()
#define pin_mode_input(nr) pin_mode_input_(nr)
#define pin_high_(nr) pin##nr##_high()
#define pin_high(nr) pin_high_(nr)
#define pin_low_(nr) pin##nr##_low()
#define pin_low(nr) pin_low_(nr)
#define pin_toggle_(nr) pin##nr##_toggle()
#define pin_toggle(nr) pin_toggle_(nr)
#define pin_is_high_(nr) pin##nr##_is_high()
#define pin_is_high(nr) pin_is_high_(nr)
#define pin_interrupt_mask_(nr) pin##nr##_interrupt_mask()
#define pin_interrupt_mask(nr) pin_interrupt_mask_(nr)
#define pin_interrupt_unmask_(nr) pin##nr##_interrupt_unmask()
#define pin_interrupt_unmask(nr) pin_interrupt_unmask_(nr)
#define pin_digital_input_disable_(nr) pin##nr##_digital_input_disable()
#define pin_digital_input_disable(nr) pin_digital_input_disable_(nr)
#define pin_digital_input_enable_(nr) pin##nr##_digital_input_enable()
#define pin_digital_input_enable(nr) pin_digital_input_enable_(nr)

#define define_pin_basic(nr, ddr, port, pinx, bit)\
	static __attribute__((always_inline)) inline void\
	pin##nr##_mode_output(void) { ddr  |= _BV(bit); }\
	static __attribute__((always_inline)) inline void\
	pin##nr##_mode_input(void)  { ddr  &= ~(_BV(bit)); }\
	static __attribute__((always_inline)) inline void\
	pin##nr##_high(void)        { port |= _BV(bit); }\
	static __attribute__((always_inline)) inline void\
	pin##nr##_low(void)         { port &= ~(_BV(bit)); }\
	static __attribute__((always_inline)) inline void\
	pin##nr##_toggle(void)      { pinx |= _BV(bit); }\
	static inline uint8_t\
	pin##nr##_is_high(void)	{ return pinx & _BV(bit); }

#define define_pin_change_mask(nr, pcmsk, bit)\
	static inline void\
	pin##nr##_interrupt_mask(void)   { pcmsk |= _BV(bit); }\
	static inline void\
	pin##nr##_interrupt_unmask(void) { pcmsk &= ~(_BV(bit)); }

#define define_pin_digital_input(nr, didr, bit)\
	static inline void\
	pin##nr##_digital_input_disable(void) { didr |= _BV(bit); }\
	static inline void\
	pin##nr##_digital_input_enable(void)  { didr &= ~(_BV(bit)); }
