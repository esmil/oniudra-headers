arduino-headers
===============


About
-----

This is a collection of inline functions and macros I use for programming
my [Arduino][1] in pure old C. It enables me to write simply

    pin12_mode_input();

instead of the more cryptic

    DDRB &= ~(_BV(4));

and since GCC is clever there is absolutely no overhead in doing this.

My Arduino has an [ATmega328P][2] microprocessor running at 16MHz, and
unfortunately this is all the headers support right now. If somebody
wants to lend me an Arduino with another chip or clock speed
I'd be happy to change this.

[1]: http://www.arduino.cc/
[2]: http://www.atmel.com/dyn/products/product_card.asp?part_id=4198


Usage
-----

Here is a simple C program, which just blinks the diode connected to
pin 13.

    #include <util/delay.h>
    #include <arduino/pins.h>
    
    int main()
    {
            pin13_mode_output();
    
            while (1) {
                    pin13_high();
                    _delay_ms(100.0);
                    pin13_low();
                    _delay_ms(900.0);
            }
    
            return 0;
    }

See the [doorduino][4] code for a larger example. There you can also
find a [Makefile][5] for compiling and uploading Arduino programs.

[4]: http://github.com/labitat/doorduino
[5]: http://github.com/labitat/doorduino/blob/master/Makefile


License
-------

arduino-headers is free software. It is distributed under the terms of
the [GNU General Public License][6]

[6]: http://www.fsf.org/licensing/licenses/gpl.html


Contact
-------

Please send bug reports, patches, feature requests, praise and general
gossip to me, Emil Renner Berthing <esmil@mailme.dk>.
