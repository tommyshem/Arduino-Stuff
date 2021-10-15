## C compiler instructions for AVR

Need to install the avr c compiler

Mac install

```bash
brew install avr-gcc avrdude
```

Linux components need installing

```bash
sudo apt-get install gcc-avr binutils-avr avr-libc
sudo apt-get install avrdude
```


## QEMU Emulator and debug using GDB

```bash
avr-gcc -g -ggdb 
avr-objcopy -O binary prog.avr5.out main.bin
qemu-sysyem-avr -s -S -nographic -machine mega2560 -bios main.elf
avr-gdb -ex 'target remote :1234' main.bin
```
