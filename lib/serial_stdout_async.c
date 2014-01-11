#include <stdio.h>
#include <arduino/serial.h>

#ifndef SERIAL_OUTBUF
#define SERIAL_OUTBUF 128
#endif

static struct {
	uint8_t buf[SERIAL_OUTBUF];
	uint8_t volatile start;
	uint8_t volatile end;
} serial_output;

serial_interrupt_dre()
{
	uint8_t start = serial_output.start;

	if (start == serial_output.end)
		serial_interrupt_dre_disable();
	else {
		serial_write(serial_output.buf[start]);
		serial_output.start = (start + 1) & (SERIAL_OUTBUF - 1);
	}
}

static int
serial_putchar(char c, FILE *stream __attribute__((unused)))
{
	uint8_t end = serial_output.end;

	serial_output.buf[end] = c;
	serial_output.end = (end + 1) & (SERIAL_OUTBUF - 1);
	serial_interrupt_dre_enable();

	return 0;
}

static FILE serial_stdout = FDEV_SETUP_STREAM(serial_putchar, NULL, _FDEV_SETUP_WRITE);

static inline void
serial_init_stdout(void)
{
	serial_transmitter_enable();
	stdout = &serial_stdout;
}
