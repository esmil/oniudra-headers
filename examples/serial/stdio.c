#include <stdint.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <arduino/pins.h>
#include <arduino/sleep.h>

#include "lib/serial_stdin_async.c"

//#include "lib/serial_stdout_busy.c"
//#include "lib/serial_stdout_sync.c"
#include "lib/serial_stdout_async.c"

int
main(void)
{
	serial_init(9600, 8n1);
	serial_init_stdin();
	serial_init_stdout();

	sleep_mode_idle();

	sei();
	while (1) {
		int c = getchar();

		printf_P(PSTR("You sent me '%c' (0x%02x)\r\n"), c, c);
	}
}
