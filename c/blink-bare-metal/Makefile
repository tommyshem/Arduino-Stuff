# chip to compile and flash
MCU=atmega328p
MCU2=
# frequency of the board for timing functions to work correctly
F_CPU=16000000UL  # 16mhz
# compiler to use
CC=avr-gcc
# bin to ihex converter to use
OBJCOPY=avr-objcopy
# compiler flags to use
RELEASE-CFLAGS=-Wall -Wextra -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
DEBUG-CFLAGS=-Wall -Wextra -save-temps=obj -g3 -ggdb -Og -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
# Port to flash the chip using avrdude
PORT=/dev/ttyUSB0
BAUDRATE=57600
TARGET=main
# c source files
SRCS=main.c

# build all c files with release flags and convert to ihex file in /tmp/avrbuild folder
.PHONY: all
all: clean release flash

# build all c files with release flags and convert to ihex file in /tmp/avrbuild folder
.PHONY: release
release:
	mkdir -p /tmp/avrbuild/
	${CC} ${RELEASE-CFLAGS} -o /tmp/avrbuild/${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex /tmp/avrbuild/${TARGET}.bin /tmp/avrbuild/${TARGET}.hex

# build all c files with debug flags and convert to ihex file in /tmp/avrbuild folder
.PHONY: debug
debug:
	mkdir -p /tmp/avrbuild/
	${CC} ${DEBUG-CFLAGS}  -o /tmp/avrbuild/${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex /tmp/avrbuild/${TARGET}.bin /tmp/avrbuild/${TARGET}.hex

# run qemu simulator
.PHONY: sim
sim:
	qemu-system-avr -nographic -s -S -machine arduino-uno -bios /tmp/avrbuild/${TARGET}.bin

# run gdb debugger
.PHONY: gdb
gdb:
	gdb -ex 'target remote :1234' -tui -cd=/tmp/avrbuild/ /tmp/avrbuild/${TARGET}.bin

# flash the i hex file to the usb port
# -c the proctol for programming
# -p chip part number
# -b baudrate for the serial communcation for flashing the chip
# -P the port used for programming the chip
# -U the command for avrdude 
.PHONY: flash
flash:	
	avrdude -p ${MCU} -c arduino -Uflash:w:/tmp/avrbuild/${TARGET}.hex:i -b${BAUDRATE} -F -P ${PORT}

# clean files out of the tmp folder
.PHONY: clean
clean:
	rm -f /tmp/avrbuild/*.bin /tmp/avrbuild/*.hex

# print commands out and breif description
.PHONY: help
help:
	@echo "Build commands available"
	@echo "all    -- builds all the files with release flags and converts hex file and flash chip"
	@echo "release -- builds all the files with release flags and converts it to a i hex file in the /tmp/avrbuild folder"
	@echo "debug  -- builds all the files with debug flags and converts it to a i hex file in the /tmp/avrbuild folder"
	@echo ""
	@echo "Flash the chip commands available"
	@echo "flash  -- will flash the ihex file to the connected chip via usb using avrdude"
	@echo ""
	@echo "Clean commands available"
	@echo "clean  -- will delete the bin and hex files form the /tmp/avtbuild folder"
	@echo ""
	@echo "simulator commands available"
	@echo "sim    -- run qemu simulator"
	@echo ""
	@echo "Debug commands available"
	@echo "gdb    -- run gdb and connect to the simulator"

	
