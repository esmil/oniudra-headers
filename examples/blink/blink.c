#include <util/delay.h>
#include <arduino/pins.h>

#define LED 13

int main(void)
{
	pin_mode_output(LED);

	while (1) {
		pin_high(LED);
		_delay_ms(100.0);
		pin_low(LED);
		_delay_ms(900.0);
	}
}
