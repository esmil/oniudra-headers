#include <util/delay.h>
#include <arduino/pins.h>

#ifndef LCD_PIN_RS
#define LCD_PIN_RS     7
#endif
#ifndef LCD_PIN_ENABLE
#define LCD_PIN_ENABLE 6
#endif
#ifndef LCD_PIN_DATA4
#define LCD_PIN_DATA4  5
#endif
#ifndef LCD_PIN_DATA5
#define LCD_PIN_DATA5  4
#endif
#ifndef LCD_PIN_DATA6
#define LCD_PIN_DATA6  3
#endif
#ifndef LCD_PIN_DATA7
#define LCD_PIN_DATA7  2
#endif

static void
lcd_pulse(void)
{
	pin_low(LCD_PIN_ENABLE);
	_delay_us(5.0);
	pin_high(LCD_PIN_ENABLE);
	/* commands need > 37us to settle */
	_delay_us(40.0);
}

static void
lcd_sync(void)
{
	/* make sure we start in 8-bit mode */
	pin_low(LCD_PIN_RS);
	pin_low(LCD_PIN_DATA7);
	pin_low(LCD_PIN_DATA6);
	pin_high(LCD_PIN_DATA5);
	pin_high(LCD_PIN_DATA4);
	lcd_pulse();
	lcd_pulse();
	lcd_pulse();

	/* now set 4-bit mode */
	pin_low(LCD_PIN_DATA4);
	lcd_pulse();
}

static void
lcd_init(void)
{
	pin_mode_output(LCD_PIN_RS);
	pin_mode_output(LCD_PIN_ENABLE);
	pin_mode_output(LCD_PIN_DATA4);
	pin_mode_output(LCD_PIN_DATA5);
	pin_mode_output(LCD_PIN_DATA6);
	pin_mode_output(LCD_PIN_DATA7);
	pin_high(LCD_PIN_ENABLE);

	lcd_sync();
}

static void
lcd_send(uint8_t c)
{
	pin_low(LCD_PIN_DATA7);
	pin_low(LCD_PIN_DATA6);
	pin_low(LCD_PIN_DATA5);
	pin_low(LCD_PIN_DATA4);

	if (c & 0x80)
		pin_high(LCD_PIN_DATA7);
	if (c & 0x40)
		pin_high(LCD_PIN_DATA6);
	if (c & 0x20)
		pin_high(LCD_PIN_DATA5);
	if (c & 0x10)
		pin_high(LCD_PIN_DATA4);

	lcd_pulse();

	pin_low(LCD_PIN_DATA7);
	pin_low(LCD_PIN_DATA6);
	pin_low(LCD_PIN_DATA5);
	pin_low(LCD_PIN_DATA4);

	if (c & 0x08)
		pin_high(LCD_PIN_DATA7);
	if (c & 0x04)
		pin_high(LCD_PIN_DATA6);
	if (c & 0x02)
		pin_high(LCD_PIN_DATA5);
	if (c & 0x01)
		pin_high(LCD_PIN_DATA4);

	lcd_pulse();
}

static void
lcd_command(uint8_t command)
{
	pin_low(LCD_PIN_RS);
	lcd_send(command);
}

static void __attribute__((unused))
lcd_clear(void)
{
	lcd_command(0x01);
	_delay_ms(2.0); /* delay at least 1.52ms */
}

static void __attribute__((unused))
lcd_cursor_home(void)
{
	lcd_command(0x02);
	_delay_ms(2.0); /* delay at least 1.52ms */
}

static void __attribute__((unused))
lcd_cursor_set(uint8_t pos)
{
	lcd_command(0x80 | pos);
}

static void __attribute__((unused))
lcd_write(uint8_t c)
{
	pin_high(LCD_PIN_RS);
	lcd_send(c);
}

static void __attribute__((unused))
lcd_puts(char *str)
{
	uint8_t c;

	pin_high(LCD_PIN_RS);
	while ((c = *str++) != '\0')
		lcd_send(c);
}

static void __attribute__((unused))
lcd_print_uint8_b2(uint8_t n)
{
	uint8_t mask;

	for (mask = 0x80; mask; mask >>= 1) {
		if (n & mask)
			lcd_write('1');
		else
			lcd_write('0');
	}
}

static void __attribute__((unused))
lcd_print_uint8_b10(uint8_t n)
{
	if (n >= 100) {
		if (n >= 200)
			lcd_write('2');
		else
			lcd_write('1');
	} else
		lcd_write(' ');

	if (n >= 10)
		lcd_write(((n / 10) % 10) + '0');
	else
		lcd_write(' ');

	lcd_write((n % 10) + '0');
}

static void __attribute__((unused))
lcd_print_uint8_b16(uint8_t n)
{
	uint8_t c;

	c = n >> 4;
	if (c >= 10)
		lcd_write(c + 'A' - 10);
	else
		lcd_write(c + '0');

	c = n & 0x0F;
	if (c >= 10)
		lcd_write(c + 'A' - 10);
	else
		lcd_write(c + '0');
}

static void __attribute__((unused))
lcd_print_uint16_b10(uint16_t n)
{
	uint16_t d;

	for (d = 10000; d > 1; d /= 10) {
		if (n >= d)
			lcd_write(((n / d) % 10) + '0');
		else
			lcd_write('0');
	}

	lcd_write((n % 10) + '0');
}
