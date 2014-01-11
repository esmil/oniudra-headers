#include <util/delay.h>
#include <arduino/sleep.h>
#include <arduino/pins.h>

#define GND  8
#define DQ   9
#define VDD 10

#include "lib/serial_stdout_busy.c"

#define ONEWIRE_PIN DQ
#define ONEWIRE_INTERNAL_PULLUP
#include "lib/onewire.c"

static int8_t
dtemp_convert(uint8_t rom[8])
{
	if (onewire_match_rom(rom))
		return -1;

	/* transmit convert temperature command */
	onewire_transmit_8bit(0x44);

	/* wait for conversion to complete */
	while (onewire_receive_1bit() == 0);

	return 0;
}

static int8_t
dtemp_scratchpad_read(uint8_t rom[8], uint8_t scratchpad[9])
{
	uint8_t i;

	if (onewire_match_rom(rom))
		return -1;

	/* transmit read scratchpad command */
	onewire_transmit_8bit(0xBE);

	/* read scratchpad bytes */
	for (i = 0; i < 9; i++)
		scratchpad[i] = onewire_receive_8bit();

	return 0;
}

static void
find_and_query(void)
{
	uint8_t search_state = 0;
	uint8_t rom[8];
	uint8_t scratchpad[9];
	int16_t val;

	do {
		if (onewire_search_rom(&search_state, rom)) {
			printf("No slaves found.\r\n");
			return;
		}

		if (onewire_crc(rom, 8)) {
			printf("Error validating ROM.\r\n");
			return;
		}

		printf("Found slave: %02x%02x%02x%02x%02x%02x%02x%02x\r\n",
				rom[0], rom[1], rom[2], rom[3],
				rom[4], rom[5], rom[6], rom[7]);

		if (dtemp_convert(rom)) {
			printf("Error converting temperature.\r\n.");
			continue;
		}

		if (dtemp_scratchpad_read(rom, scratchpad)) {
			printf("Error reading temperature.\r\n.");
			continue;
		}

		printf("Scratchpad is: %02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",
				scratchpad[0], scratchpad[1], scratchpad[2],
				scratchpad[3], scratchpad[4], scratchpad[5],
				scratchpad[6], scratchpad[7], scratchpad[8]);

		val = (scratchpad[1] << 8) | scratchpad[0];
		printf("Read %d\r\n", val / 2);
	} while (search_state);

	printf("No more slaves.\r\n");
}

int
main(void)
{
	pin_mode_output(GND);
	pin_mode_output(VDD);
	pin_high(VDD);

	onewire_init();

	sleep_mode_idle();

	serial_init(9600, 8n1);
	serial_init_stdout();

	sei();
	while (1) {
		find_and_query();
		_delay_ms(1000.0);
	}
}
