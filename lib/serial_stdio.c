#include "lib/serial_stdin_async.c"
#include "lib/serial_stdout_busy.c"

static void
serial_stdio_init(void)
{
	serial_init_stdin();
	serial_init_stdout();
}
