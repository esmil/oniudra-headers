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

pin__define_basic( 0, DDRD, PORTD, PIND, 0)
pin__define_basic( 1, DDRD, PORTD, PIND, 1)
pin__define_basic( 2, DDRD, PORTD, PIND, 2)
pin__define_basic( 3, DDRD, PORTD, PIND, 3)
pin__define_basic( 4, DDRD, PORTD, PIND, 4)
pin__define_basic( 5, DDRD, PORTD, PIND, 5)
pin__define_basic( 6, DDRD, PORTD, PIND, 6)
pin__define_basic( 7, DDRD, PORTD, PIND, 7)

pin__define_basic( 8, DDRB, PORTB, PINB, 0)
pin__define_basic( 9, DDRB, PORTB, PINB, 1)
pin__define_basic(10, DDRB, PORTB, PINB, 2)
pin__define_basic(11, DDRB, PORTB, PINB, 3)
pin__define_basic(12, DDRB, PORTB, PINB, 4)
pin__define_basic(13, DDRB, PORTB, PINB, 5)

pin__define_basic(A0, DDRC, PORTC, PINC, 0)
pin__define_basic(A1, DDRC, PORTC, PINC, 1)
pin__define_basic(A2, DDRC, PORTC, PINC, 2)
pin__define_basic(A3, DDRC, PORTC, PINC, 3)
pin__define_basic(A4, DDRC, PORTC, PINC, 4)
pin__define_basic(A5, DDRC, PORTC, PINC, 5)
pin__define_basic(A6, DDRC, PORTC, PINC, 6)

/* external interrupts */
static inline void
pin2_interrupt_mode_low(void)     { EICRA = EICRA & ~(_BV(ISC01) | _BV(ISC00)); }
static inline void
pin2_interrupt_mode_change(void)  { EICRA = (EICRA & ~(_BV(ISC01))) | _BV(ISC00); }
static inline void
pin2_interrupt_mode_falling(void) { EICRA = (EICRA & ~(_BV(ISC00))) | _BV(ISC01); }
static inline void
pin2_interrupt_mode_rising(void)  { EICRA = EICRA | _BV(ISC01) | _BV(ISC00); }

static inline void
pin3_interrupt_mode_low(void)     { EICRA = EICRA & ~(_BV(ISC11) | _BV(ISC10)); }
static inline void
pin3_interrupt_mode_change(void)  { EICRA = (EICRA & ~(_BV(ISC11))) | _BV(ISC10); }
static inline void
pin3_interrupt_mode_falling(void) { EICRA = (EICRA & ~(_BV(ISC10))) | _BV(ISC11); }
static inline void
pin3_interrupt_mode_rising(void)  { EICRA = EICRA | _BV(ISC11) | _BV(ISC10); }

#define pin2_interrupt() ISR(INT0_vect)
#define pin2_interrupt_naked() ISR(INT0_vect, ISR_NAKED)
#define pin2_interrupt_empty() EMPTY_INTERRUPT(INT0_vect)
static inline void
pin2_interrupt_enable(void)       { EIMSK |= _BV(INT0); }
static inline void
pin2_interrupt_disable(void)      { EIMSK &= ~(_BV(INT0)); }

#define pin3_interrupt() ISR(INT1_vect)
#define pin3_interrupt_naked() ISR(INT1_vect, ISR_NAKED)
#define pin3_interrupt_empty() EMPTY_INTERRUPT(INT1_vect)
static inline void
pin3_interrupt_enable(void)       { EIMSK |= _BV(INT1); }
static inline void
pin3_interrupt_disable(void)      { EIMSK &= ~(_BV(INT1)); }

static inline uint8_t
pin2_interrupt_flag(void)         { return EIFR & INTF0; }
static inline void
pin2_interrupt_flag_clear(void)   { EIMSK |= _BV(INTF0); }
static inline uint8_t
pin3_interrupt_flag(void)         { return EIFR & INTF1; }
static inline void
pin3_interrupt_flag_clear(void)   { EIMSK |= _BV(INTF1); }

/* pin change interrupts */
pin__define_change_mask(0, PCMSK2, PCINT16)
pin__define_change_mask(1, PCMSK2, PCINT17)
pin__define_change_mask(2, PCMSK2, PCINT18)
pin__define_change_mask(3, PCMSK2, PCINT19)
pin__define_change_mask(4, PCMSK2, PCINT20)
pin__define_change_mask(5, PCMSK2, PCINT21)
pin__define_change_mask(6, PCMSK2, PCINT22)
pin__define_change_mask(7, PCMSK2, PCINT23)

pin__define_change_mask( 8, PCMSK0, PCINT0)
pin__define_change_mask( 9, PCMSK0, PCINT1)
pin__define_change_mask(10, PCMSK0, PCINT2)
pin__define_change_mask(11, PCMSK0, PCINT3)
pin__define_change_mask(12, PCMSK0, PCINT4)
pin__define_change_mask(13, PCMSK0, PCINT5)

pin__define_change_mask(A0, PCMSK1, PCINT8)
pin__define_change_mask(A1, PCMSK1, PCINT9)
pin__define_change_mask(A2, PCMSK1, PCINT10)
pin__define_change_mask(A3, PCMSK1, PCINT11)
pin__define_change_mask(A4, PCMSK1, PCINT12)
pin__define_change_mask(A5, PCMSK1, PCINT13)

#define pin_0to7_interrupt() ISR(PCINT2_vect)
#define pin_0to7_interrupt_naked() ISR(PCINT2_vect, ISR_NAKED)
#define pin_0to7_interrupt_empty() EMPTY_INTERRUPT(PCINT2_vect)
static inline void
pin_0to7_interrupt_enable(void)   { PCICR |= _BV(PCIE2); }
static inline void
pin_0to7_interrupt_disable(void)  { PCICR &= ~(_BV(PCIE2)); }
#define pin_8to13_interrupt() ISR(PCINT0_vect)
#define pin_8to13_interrupt_naked() ISR(PCINT0_vect, ISR_NAKED)
#define pin_8to13_interrupt_empty() EMPTY_INTERRUPT(PCINT0_vect)
static inline void
pin_8to13_interrupt_enable(void)  { PCICR |= _BV(PCIE0); }
static inline void
pin_8to13_interrupt_disable(void) { PCICR &= ~(_BV(PCIE0)); }
#define pin_A0toA5_interrupt() ISR(PCINT1_vect)
#define pin_A0toA5_interrupt_naked() ISR(PCINT1_vect, ISR_NAKED)
#define pin_A0toA5_interrupt_empty() EMPTY_INTERRUPT(PCINT1_vect)
static inline void
pin_A0toA5_interrupt_enable(void)  { PCICR |= _BV(PCIE1); }
static inline void
pin_A0toA5_interrupt_disable(void) { PCICR &= ~(_BV(PCIE1)); }

/* enable/disable digital input */
pin__define_digital_input(6, DIDR1, AIN0D)
pin__define_digital_input(7, DIDR1, AIN1D)

pin__define_digital_input(A0, DIDR0, ADC0D)
pin__define_digital_input(A1, DIDR0, ADC1D)
pin__define_digital_input(A2, DIDR0, ADC2D)
pin__define_digital_input(A3, DIDR0, ADC3D)
pin__define_digital_input(A4, DIDR0, ADC4D)
pin__define_digital_input(A5, DIDR0, ADC5D)
