NAME  ?= main

MODEL ?= uno

BAUD  ?= 9600
MODE  ?= $(MODE_RAW) $(MODE_8) $(MODE_N) $(MODE_1)# 8N1

ifeq ($(MODEL),duemilanove)
MCU       = atmega328p
F_CPU     = 16000000UL
PORT      = /dev/ttyUSB0
PROG      = arduino
PROG_BAUD = 57600
else ifeq ($(MODEL),uno)
MCU       = atmega328p
F_CPU     = 16000000UL
PORT      = /dev/ttyACM0
PROG      = arduino
PROG_BAUD = 115200
endif

BASE           = $(realpath $(dir $(lastword $(MAKEFILE_LIST))))
DEFAULT       ?= $(NAME).hex

CROSS_COMPILE  = avr-
CC             = $(CROSS_COMPILE)gcc
OBJCOPY        = $(CROSS_COMPILE)objcopy
OBJDUMP        = $(CROSS_COMPILE)objdump
NM             = $(CROSS_COMPILE)nm
AVRDUDE        = avrdude
STTY           = stty
SED            = sed
CAT            = cat
SCREEN         = screen
STAT           = stat

MODE_RAW = raw -echo -hup
MODE_7   = cs7
MODE_8   = cs8
MODE_N   = -parenb
MODE_E   = parenb -parodd
MODE_O   = parenb parodd
MODE_1   = -cstopb
MODE_2   = cstopb

PROG_arduino    = -D -P$(PORT) -b$(PROG_BAUD)
PROG_avrispmkII = -Pusb

OPT      = 2
CFLAGS   = -std=gnu99 -O$(OPT) -pipe -gdwarf-2 -Wall -Wextra -Wno-variadic-macros -fstrict-aliasing -fshort-enums
CFLAGS  += -mmcu=$(MCU) -DF_CPU=$(F_CPU) -iquote$(BASE) -I$(BASE)

LDFLAGS  = -Wl,--relax

ifeq ($(PRINTF),minimal)
LDFLAGS += -Wl,-u,vfprintf
LIBS    += -lprintf_min
else ifeq ($(PRINTF),float)
LDFLAGS += -Wl,-u,vfprintf
LIBS    += -lm -lprintf_flt
endif

ifeq ($(SCANF),minimal)
LDFLAGS += -Wl,-u,vfscanf
LIBS    += -lscanf_min
else ifeq ($(SCANF),float)
LDFLAGS += -Wl,-u,vfscanf
LIBS    += -lm -lscanf_flt
endif

ifdef V
E=@\#
Q=
else
E=@echo
Q=@
endif

.PHONY: all list tty cat screen
.PRECIOUS: %.elf

all: $(DEFAULT)

%.elf: $(or $(FILES),%.c)
	$E '  CC $@'
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS) $(LIBS)

%.hex: %.elf
	$E '  OBJCOPY $@'
	$Q$(OBJCOPY) -O ihex -R .eeprom -S $< $@
	@echo "  $$((0x$$($(OBJDUMP) -h $@ | $(SED) -n '6{s/^  0 \.sec1         //;s/ .*//;p}'))) bytes"

%.bin: %.elf
	$E '  OBJCOPY $@'
	$Q$(OBJCOPY) -O binary -R .eeprom -S $< $@
	@$(STAT) -c '  %s bytes' $@

# Create extended listing file from ELF output file.
%.lss: %.elf
	$E '  OBJDUMP > $@'
	$Q$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	$E '  NM $@'
	$Q$(NM) -n $< > $@

upload: $(NAME).hex
	$(AVRDUDE) -v -p$(MCU) -c$(PROG) $(PROG_$(PROG)) -Uflash:w:$<:i

list: $(NAME).lss

tty: $(PORT)
	$E '  STTY -F$(PORT) $(MODE) $(BAUD)'
	$Q$(STTY) -F$(PORT) $(MODE) $(BAUD)

cat: $(PORT)
	$Q$(CAT) $(PORT)

screen: $(PORT)
	$(SCREEN) $(PORT) $(BAUD)

clean:
	rm -f *.elf *.hex *.bin *.map *.lst *.lss *.sym
