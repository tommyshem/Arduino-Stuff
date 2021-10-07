# chip to compile and flash
MCU=atmega328p
MCU2=
# frequency of the board for timing functions to work correctly
F_CPU=8000000UL
# compiler to use
CC=avr-gcc
# bin to ihex converter to use
OBJCOPY=avr-objcopy
# compiler flags to use
CFLAGS=-Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
# Port to flash the chip using avrdude
PORT=/dev/ttyusbB
TARGET=main
# c source files
SRCS=main.c

# build all c files and convert to ihex file in /tmp/avrbuild folder
.PHONY: all
all:
	mkdir -p /tmp/avrbuild/
	${CC} ${CFLAGS} -o /tmp/avrbuild/${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex /tmp/avrbuild/${TARGET}.bin /tmp/avrbuild/${TARGET}.hex

# flash the i hex file to the usb port
.PHONY: flash
flash:	
	avrdude -p ${MCU} -c -Uflash:w:/tmp/avrbuild/${TARGET}.hex:i -F -P ${PORT}

# clean files out of the tmp folder
.PHONY: clean
clean:
	rm -f /tmp/avrbuild/*.bin /tmp/avrbuild/*.hex

# print commands out and breif description
.PHONY: help
help:
	@echo "Commands available"
	@echo "all    -- builds all the files and converts it to a i hex file in the /tmp/avrbuild folder"
	@echo "flash  -- will flash the ihex file to the connected chip via usb using avrdude"
	@echo "clean  -- will delete the bin and hex files form the /tmp/avtbuild folder"
	
