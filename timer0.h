#ifndef _ARDUINO_TIMER0_H
#define _ARDUINO_TIMER0_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* timer0 mode select */
static inline void
timer0_mode_normal()        { TCCR0A = 0; }
static inline void
timer0_mode_phase_correct() { TCCR0A = _BV(WGM00); }
static inline void
timer0_mode_ctc()           { TCCR0A = _BV(WGM01); }
static inline void
timer0_mode_fastpwm()       { TCCR0A = _BV(WGM01) | _BV(WGM00); }

/* timer0 clocks select */
static inline void
timer0_clock_off()
{
	TCCR0B = TCCR0B & ~(_BV(CS02) | _BV(CS01) | _BV(CS00));
}

static inline void
timer0_clock_d1()
{
	TCCR0B = (TCCR0B & ~(_BV(CS02) | _BV(CS01))) | _BV(CS00);
}

static inline void
timer0_clock_d8()
{
	TCCR0B = (TCCR0B & ~(_BV(CS02) | _BV(CS00))) | _BV(CS01);
}

static inline void
timer0_clock_d64()
{
	TCCR0B = (TCCR0B & ~(_BV(CS02))) | _BV(CS01) | _BV(CS00);
}

static inline void
timer0_clock_d256()
{
	TCCR0B = (TCCR0B & ~(_BV(CS01) | _BV(CS00))) | _BV(CS02);
}

static inline void
timer0_clock_d1024()
{
	TCCR0B = (TCCR0B & ~(_BV(CS01))) | _BV(CS02) | _BV(CS00);
}

static inline void
timer0_clock_external_falling()
{
	TCCR0B = (TCCR0B & ~(_BV(CS00))) | _BV(CS02) | _BV(CS01);
}

static inline void
timer0_clock_external_rising()
{
	TCCR0B = TCCR0B | _BV(CS02) | _BV(CS01) | _BV(CS00);
}

static inline uint8_t
timer0_clock_running()
{
	return TCCR0B & (_BV(CS02) | _BV(CS01) | _BV(CS00));
}

static inline void
timer0_clock_reset()
{
	GTCCR |= _BV(PSRSYNC);
}

/* timer0 pins */
static inline void
timer0_pin6_off()
{
	TCCR0A = TCCR0A & ~(_BV(COM0A1) | _BV(COM0A0));
}

static inline void
timer0_pin6_toggle()
{
	TCCR0A = (TCCR0A & ~(_BV(COM0A1))) | _BV(COM0A0);
}

static inline void
timer0_pin6_clear()
{
	TCCR0A = (TCCR0A & ~(_BV(COM0A0))) | _BV(COM0A1);
}

static inline void
timer0_pin6_set()
{
	TCCR0A = TCCR0A | _BV(COM0A1) | _BV(COM0A0);
}

static inline void
timer0_pin5_off()
{
	TCCR0A = TCCR0A & ~(_BV(COM0B1) | _BV(COM0B0));
}

static inline void
timer0_pin5_toggle()
{
	TCCR0A = (TCCR0A & ~(_BV(COM0B1))) | _BV(COM0B0);
}

static inline void
timer0_pin5_clear()
{
	TCCR0A = (TCCR0A & ~(_BV(COM0B0))) | _BV(COM0B1);
}

static inline void
timer0_pin5_set()
{
	TCCR0A = TCCR0A | _BV(COM0B1) | _BV(COM0B0);
}

/* timer0 interrupts */
static inline void
timer0_interrupt_ovf_enable()  { TIMSK0 |= _BV(TOIE0); }
static inline void
timer0_interrupt_ovf_disable() { TIMSK0 &= ~(_BV(TOIE0)); }
static inline void
timer0_interrupt_a_enable()    { TIMSK0 |= _BV(OCIE0A); }
static inline void
timer0_interrupt_a_disable()   { TIMSK0 &= ~(_BV(OCIE0A)); }
static inline void
timer0_interrupt_b_enable()    { TIMSK0 |= _BV(OCIE0B); }
static inline void
timer0_interrupt_b_disable()   { TIMSK0 &= ~(_BV(OCIE0B)); }

#define timer0_interrupt_ovf() ISR(TIMER0_OVF_vect)
#define timer0_interrupt_ovf_naked() ISR(TIMER0_OVF_vect, ISR_NAKED)
#define timer0_interrupt_ovf_empty() EMPTY_INTERRUPT(TIMER0_OVF_vect)
#define timer0_interrupt_a() ISR(TIMER0_COMPA_vect)
#define timer0_interrupt_a_naked() ISR(TIMER0_COMPA_vect, ISR_NAKED)
#define timer0_interrupt_a_empty() EMPTY_INTERRUPT(TIMER0_COMPA_vect)
#define timer0_interrupt_b() ISR(TIMER0_COMPB_vect)
#define timer0_interrupt_b_naked() ISR(TIMER0_COMPB_vect, ISR_NAKED)
#define timer0_interrupt_b_empty() EMPTY_INTERRUPT(TIMER0_COMPB_vect)

/* timer0 count */
static inline uint8_t
timer0_count()              { return TCNT0; }
static inline void
timer0_count_set(uint8_t n) { TCNT0 = n; }

/* timer0 compare registers */
static inline uint8_t
timer0_compare_a()              { return OCR0A; }
static inline uint8_t
timer0_compare_b()              { return OCR0B; }
static inline void
timer0_compare_a_set(uint8_t v) { OCR0A = v; }
static inline void
timer0_compare_b_set(uint8_t v) { OCR0B = v; }

/* timer0 flags */
static inline void
timer0_flags_clear() { TIFR0 = 0; }
static inline uint8_t
timer0_flag_ovf()    { return TIFR0 & _BV(TOV0); }
static inline uint8_t
timer0_flag_a()      { return TIFR0 & _BV(OCF0A); }
static inline uint8_t
timer0_flag_b()      { return TIFR0 & _BV(OCF0B); }

#endif
