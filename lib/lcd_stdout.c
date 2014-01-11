#include <stdio.h>

#include "lib/lcd.c"

static int
lcd_putchar(char c, FILE *stream __attribute__((unused)))
{
	lcd_write(c);
	return 0;
}

static FILE lcd_stdout = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

static inline void
lcd_init_stdout(void)
{
	stdout = &lcd_stdout;
}
