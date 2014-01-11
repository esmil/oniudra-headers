#include <stdio.h>
#include <arduino/serial.h>

#ifndef SERIAL_INBUF
#define SERIAL_INBUF 128
#endif

static struct {
	uint8_t buf[SERIAL_INBUF];
	uint8_t volatile start;
	uint8_t volatile end;
} serial_input;

serial_interrupt_rx()
{
	uint8_t end = serial_input.end;

	serial_input.buf[end] = serial_read();
	serial_input.end = (end + 1) & (SERIAL_INBUF - 1);
}

static int
serial_getchar(FILE *stream __attribute__((unused)))
{
	uint8_t start;
	int ret;

	while (1) {
		cli();
		if (serial_input.start != serial_input.end)
			break;
		sleep_enable();
		sei();
		sleep_cpu();
		sleep_disable();
	}
	sei();

	start = serial_input.start;
	ret = serial_input.buf[start];
	serial_input.start = (start + 1) & (SERIAL_INBUF - 1);

	return ret;
}

static FILE serial_stdin = FDEV_SETUP_STREAM(NULL, serial_getchar, _FDEV_SETUP_READ);

static inline void
serial_init_stdin(void)
{
	serial_receiver_enable();
	serial_interrupt_rx_enable();
	stdin = &serial_stdin;
}
