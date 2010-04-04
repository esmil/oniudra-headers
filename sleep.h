#ifndef _ARDUINO_SLEEP_H
#define _ARDUINO_SLEEP_H

#include <avr/io.h>
#include <avr/sleep.h>

/* set sleep mode */
static inline void
sleep_mode_idle()             { SMCR = 0; }
static inline void
sleep_mode_noise_reduction()  { SMCR = _BV(SM0); }
static inline void
sleep_mode_power_down()       { SMCR = _BV(SM1); }
static inline void
sleep_mode_power_save()       { SMCR = _BV(SM1) | _BV(SM0); }
static inline void
sleep_mode_standby()          { SMCR = _BV(SM2) | _BV(SM1); }
static inline void
sleep_mode_external_standby() { SMCR = _BV(SM2) | _BV(SM1) | _BV(SM0); }

#endif
