#include <stdint.h>
#include <util/delay.h>
#include <arduino/sleep.h>
#include <arduino/pins.h>
#include <arduino/adc.h>

#define PULLUP A1
#define LEDGND 10
#define RED    11
#define BLUE   12
#define DEBUG  13

#include "lib/serial_stdout_busy.c"

adc_interrupt_empty();

static uint16_t
adc_read(void)
{
	adc_start();

	sleep_enable();
	sleep_cpu();
	sleep_disable();

	return adc_data();
}

int main(void)
{
	pin_mode_output(LEDGND);
	pin_mode_output(PULLUP);
	pin_mode_output(RED);
	pin_mode_output(BLUE);
	//pin_mode_output(DEBUG);
	pin_low(RED);
	pin_low(BLUE);
	//pin_low(DEBUG);
	pin_low(LEDGND);
	pin_high(PULLUP);

	sleep_mode_noise_reduction();

	/*
	serial_init(9600, 8n1);
	serial_init_stdout();
	*/

	adc_reference_internal_5v();
	adc_pin_select(0);
	adc_clock_d128();
	adc_interrupt_enable();
	adc_enable();

	sei();
	while (1) {
		uint16_t val = adc_read();

		if (val > 221) {
			pin_low(RED);
			pin_high(BLUE);
		} else if (val <= 47) {
			pin_high(RED);
			pin_low(BLUE);
		} else {
			pin_low(RED);
			pin_low(BLUE);
		}

		//printf("%u\n", val);
	}
}
