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

#if defined(__AVR_ATmega8__)
#  include <arduino/ATmega8/pins.h>
#elif defined(__AVR_ATmega168__) \
   || defined(__AVR_ATmega328P__)
#  include <arduino/ATmegaX8/pins.h>
#elif defined(__AVR_ATmega1280__)
#  include <arduino/ATmega1280/pins.h>
#elif defined(__AVR_ATtiny25__) \
   || defined(__AVR_ATtiny45__) \
   || defined(__AVR_ATtiny85__)
#  include <arduino/ATtinyX5/pins.h>
#elif defined(__AVR_ATmega8U2__) \
   || defined(__AVR_ATmega16U2__) \
   || defined(__AVR_ATmega32U2__)
#  include <arduino/ATmegaXU2/pins.h>
#else
#  error "arduino/pins.h: Unknown chip type"
#endif
