#include <stdio.h>
#include <arduino/serial.h>

static int
serial_putchar(char c, FILE *stream __attribute__((unused)))
{
	while (!serial_writeable())
		/* do nothing */;
	serial_write(c);
	return 0;
}

static FILE serial_stdout = FDEV_SETUP_STREAM(serial_putchar, NULL, _FDEV_SETUP_WRITE);

static inline void
serial_init_stdout(void)
{
	serial_transmitter_enable();
	stdout = &serial_stdout;
}
