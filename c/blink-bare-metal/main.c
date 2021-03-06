// Bare bones example not using the arduino libs or include files

// compile the program with avr-gcc using the chip part number
// avr-gcc -mmcu=atmega328p main.c

// convert the compiled elf file format to a intel hex format so the avrdude can flash the chip
// avr-objcopy -O ihex -j .text -j .data a.out main.hex

// use arvdude to flash the intel hex file onto the chip
// -c the proctol for programming
// -p chip part number
// -b baudrate for the serial communcation for flashing the chip
// -P the port used for programming the chip
// -U the command for avrdude
// -v verbose output
//
// avrdude -v -patmega328p -carduino -P/dev/ttyUSB0 -b57600 -D -Uflash:w:main.hex:i

// define the direct memory address
#include "debug.h"
#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL // telling controller crystal frequency (16 MHz AVR ATMega328P)
#endif

// #define DDRB *((volatile unsigned char *)0x24)  // output mode address
// #define PORTB *((volatile unsigned char *)0x25) // portb output address
// bit macros
#define BITSET(address, bit) ((address) |= (1UL << (bit)))
#define BITCLEAR(address, bit) ((address) &= ~(1UL << (bit)))
#define BITTOGGLE(address, bit) ((address) ^= (1UL << (bit)))
#define BIT(b) (1UL << (b))

// the chip program
int main()
{
    DDRB = 32; // set ouput mode
	PORTB = 0;
    while (1)
    { // loop
       BITSET(PORTB, 5);
       _delay_ms(100);
       BITCLEAR(PORTB, 5);
       _delay_ms(100);
    }
}
