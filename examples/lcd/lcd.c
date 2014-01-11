#include <stdint.h>
#include <util/delay.h>

#include <arduino/pins.h>
#include <arduino/sleep.h>

#include "lib/lcd_stdout.c"

int
main(void)
{
	uint8_t i;

	sleep_mode_idle();

	lcd_init();
	lcd_init_stdout();
	lcd_command(0x28); /* 2 lines, 5x8 dot font */
	lcd_command(0x10); /* move cursor on write */
	lcd_command(0x0C); /* cursor off */
	lcd_command(0x06); /* move cursor right */
	lcd_clear();       /* clear display */

	sei();
	for (i = 0;; i++) {
		printf("i = %3u", i);
		lcd_cursor_home();
		_delay_ms(200.0);
	}
}
