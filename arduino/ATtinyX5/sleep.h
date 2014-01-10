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

#ifndef _ARDUINO_SLEEP_H
#define _ARDUINO_SLEEP_H

#include <avr/io.h>
#include <avr/sleep.h>

/* set sleep mode */
static inline void
sleep_mode_idle(void)
{
	MCUCR = MCUCR & ~(_BV(SM1) | _BV(SM0));
}

static inline void
sleep_mode_noise_reduction(void)
{
	MCUCR = (MCUCR & ~(_BV(SM1))) | _BV(SM0);
}

static inline void
sleep_mode_power_down(void)
{
	MCUCR = (MCUCR & ~(_BV(SM0))) | _BV(SM1);
}
#endif
