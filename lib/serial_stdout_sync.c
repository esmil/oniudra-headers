#include <stdio.h>
#include <avr/sleep.h>
#include <arduino/serial.h>

serial_interrupt_dre_empty()

static int
serial_putchar(char c, FILE *stream __attribute__((unused)))
{
	while (1) {
		cli();
		if (serial_writeable())
			break;
		sleep_enable();
		sei();
		sleep_cpu();
		sleep_disable();
	}
	sei();

	serial_write(c);
	return 0;
}

static FILE serial_stdout = FDEV_SETUP_STREAM(serial_putchar, NULL, _FDEV_SETUP_WRITE);

static inline void
serial_init_stdout(void)
{
	serial_transmitter_enable();
	serial_interrupt_dre_enable();
	stdout = &serial_stdout;
}
