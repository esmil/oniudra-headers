#ifndef ONEWIRE_PIN
#error "ONEWIRE_PIN not defined"
#endif

static uint8_t __attribute__((unused))
onewire_crc(const uint8_t *data, uint8_t len)
{
	uint8_t crc = 0;

	while (len--) {
		uint8_t c = *data++;
		uint8_t i;

		for (i = 0; i < 8; i++) {
			if ((crc ^ c) & 1)
				crc = (crc >> 1) ^ 0x8C;
			else
				crc >>= 1;

			c >>= 1;
		}
	}

	return crc;
}

static inline void
onewire_pin_low(void)
{
#ifdef ONEWIRE_INTERNAL_PULLUP
	pin_low(ONEWIRE_PIN);
#endif
	pin_mode_output(ONEWIRE_PIN);
}

static inline void
onewire_pin_release(void)
{
	pin_mode_input(ONEWIRE_PIN);
#ifdef ONEWIRE_INTERNAL_PULLUP
	pin_high(ONEWIRE_PIN); /* enable internal pull-up */
#endif
}

static void
onewire_init(void)
{
	onewire_pin_release();
#ifndef ONEWIRE_INTERNAL_PULLUP
	pin_low(ONEWIRE_PIN);
#endif
}

static int8_t
onewire_reset(void)
{
	onewire_pin_low();

	/* sleep for at least 480 us */
	_delay_us(500.0);

	onewire_pin_release();

	_delay_us(65.0);

	if (pin_is_high(ONEWIRE_PIN))
		return -1;

	_delay_us(435.0);

	return 0;
}

static void
onewire_transmit_1bit(uint8_t bit)
{
	if (bit) {
		onewire_pin_low();
		_delay_us(3.0);
		onewire_pin_release();
		_delay_us(55.0);
	} else {
		onewire_pin_low();
		_delay_us(60.0);
		onewire_pin_release();
		_delay_us(5.0);
	}
}

static void
onewire_transmit_8bit(uint8_t byte)
{
	uint8_t mask;

	for (mask = 1; mask; mask <<= 1)
		onewire_transmit_1bit(byte & mask);
}

static uint8_t
onewire_receive_1bit(void)
{
	uint8_t ret;

	onewire_pin_low();
	_delay_us(3.0);
	onewire_pin_release();

	_delay_us(9.0);

	ret = pin_is_high(ONEWIRE_PIN);

	_delay_us(53.0);

	return ret;
}

static uint8_t
onewire_receive_8bit(void)
{
	uint8_t byte = 0;
	uint8_t mask;

	for (mask = 1; mask; mask <<= 1) {
		if (onewire_receive_1bit())
			byte |= mask;
	}

	return byte;
}

static int8_t __attribute__((unused))
onewire_read_rom(uint8_t rom[8])
{
	uint8_t i;

	if (onewire_reset())
		return -1;

	/* transmit READ ROM command */
	onewire_transmit_8bit(0x33);

	for (i = 0; i < 8; i++)
		rom[i] = onewire_receive_8bit();

	return 0;
}

static int8_t __attribute__((unused))
onewire_match_rom(const uint8_t rom[8])
{
	uint8_t i;

	if (onewire_reset())
		return -1;

	/* transmit MATCH ROM command */
	onewire_transmit_8bit(0x55);

	for (i = 0; i < 8; i++)
		onewire_transmit_8bit(rom[i]);

	return 0;
}

static int8_t __attribute__((unused))
onewire_skip_rom(void)
{
	if (onewire_reset())
		return -1;

	/* transmit SKIP ROM command */
	onewire_transmit_8bit(0xCC);

	return 0;
}

static uint8_t
onewire__search(uint8_t *state, uint8_t rom[8])
{
	uint8_t lastzb = 0;
	uint8_t bit = 1;
	uint8_t i;

	for (i = 0; i < 8; i++) {
		uint8_t mask;

		for (mask = 1; mask; mask <<= 1) {
			uint8_t tx;

			if (bit > *state)
				rom[i] &= ~mask;

			if (onewire_receive_1bit()) {
				if (onewire_receive_1bit()) {
					/* no slaves */
					return 1;
				} else {
					/* only slaves with 1 bits here */
					rom[i] |= mask;
					tx = 1;
				}
			} else {
				if (onewire_receive_1bit()) {
					/* only slaves with 0 bits here */
					tx = 0;
				} else {
					/* branch point */
					if (bit == *state) {
						rom[i] |= mask;
						tx = 1;
					} else {
						tx = rom[i] & mask;
						if (tx == 0)
							lastzb = bit;
					}
				}
			}

			onewire_transmit_1bit(tx);
			bit++;
		}
	}

	*state = lastzb;
	return 0;
}

static uint8_t __attribute__((unused))
onewire_search_rom(uint8_t *state, uint8_t rom[8])
{
	if (onewire_reset())
		return 1;

	/* transmit SEARCH ROM command */
	onewire_transmit_8bit(0xF0);

	return onewire__search(state, rom);
}

static uint8_t __attribute__((unused))
onewire_alarm_search(uint8_t *state, uint8_t rom[8])
{
	if (onewire_reset())
		return 1;

	/* transmit ALARM SEARCH command */
	onewire_transmit_8bit(0xEC);

	return onewire__search(state, rom);
}
