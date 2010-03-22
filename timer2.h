#ifndef _ARDUINO_TIMERS_H
#define _ARDUINO_TIMERS_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* timer2 mode select */
static inline void
timer2_mode_normal()        { TCCR2A = 0; }
static inline void
timer2_mode_phase_correct() { TCCR2A = _BV(WGM20); }
static inline void
timer2_mode_ctc()           { TCCR2A = _BV(WGM21); }
static inline void
timer2_mode_fastpwm()       { TCCR2A = _BV(WGM21) | _BV(WGM20); }

/* timer2 clocks select */
static inline void
timer2_clock_off()   { TCCR2B = 0; }
static inline void
timer2_clock_d1()    { TCCR2B = _BV(CS20); }
static inline void
timer2_clock_d8()    { TCCR2B = _BV(CS21); }
static inline void
timer2_clock_d32()   { TCCR2B = _BV(CS21) | _BV(CS20); }
static inline void
timer2_clock_d64()   { TCCR2B = _BV(CS22); }
static inline void
timer2_clock_d128()  { TCCR2B = _BV(CS22) | _BV(CS20); }
static inline void
timer2_clock_d256()  { TCCR2B = _BV(CS22) | _BV(CS21); }
static inline void
timer2_clock_d1024() { TCCR2B = _BV(CS22) | _BV(CS21) | _BV(CS20); }

static inline uint8_t
timer2_clock_running() { return TCCR2B & (_BV(CS22) | _BV(CS21) | _BV(CS20)); }

static inline void
timer2_clock_reset() { GTCCR = _BV(PSRASY); }

/* timer2 interrupts */
static inline void
timer2_interrupt_ovf_enable()  { TIMSK2 |= _BV(TOIE2); }
static inline void
timer2_interrupt_ovf_disable() { TIMSK2 &= ~(_BV(TOIE2)); }
static inline void
timer2_interrupt_a_enable()    { TIMSK2 |= _BV(OCIE2A); }
static inline void
timer2_interrupt_a_disable()   { TIMSK2 &= ~(_BV(OCIE2A)); }
static inline void
timer2_interrupt_b_enable()    { TIMSK2 |= _BV(OCIE2B); }
static inline void
timer2_interrupt_b_disable()   { TIMSK2 &= ~(_BV(OCIE2B)); }

#define timer2_interrupt_ovf() ISR(TIMER2_OVF_vect)
#define timer2_interrupt_ovf_naked() ISR(TIMER2_OVF_vect, ISR_NAKED)
#define timer2_interrupt_ovf_empty() EMPTY_INTERRUPT(TIMER2_OVF_vect)

/* timer2 flags */
static inline void
timer2_flags_clear()   { TIFR2 = 0; }
static inline uint8_t
timer2_flag_overflow() { return TIFR2 & _BV(TOV2); }
static inline uint8_t
timer2_flag_a()        { return TIFR2 & _BV(OCF2A); }
static inline uint8_t
timer2_flag_b()        { return TIFR2 & _BV(OCF2B); }

/* timer2 count */
static inline uint8_t
timer2_count()              { return TCNT2; }
static inline void
timer2_count_set(uint8_t n) { TCNT2 = n; }

#endif
