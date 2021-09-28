# Arduino-Stuff

## Arduino Nano Setup

Make sure you can read and write to the port used for the usb conection.
Change permissions for the port used so it can be used by the programmer with sudo.

```bash
chmod a+rw /dev/ttyUSB0
```

## Rust setup for programming the Arduino Nano

Rust nightly must be used.

Use this crate package for programming the hardware
https://github.com/Rahix/avr-hal

You need to install tools first before you can build and flash the hardware in fedora linux.

```bash
dnf install systemd-devel pkgconf-pkg-config avrdude avr-gcc
```


```bash
cargo +stable install ravedude
cargo +stable install cargo-generate
```

Generate rust template for Nano 

```bash
cargo generate --git https://github.com/Rahix/avr-hal-template.git
```

Change the .cargo/config.toml

```toml
[target.'cfg(target_arch = "avr")']
runner = "ravedude nano -cb 57600 -P /dev/ttyUSB0"
```

Now build and flash your Nano hardware with

```bash
cargo run
```
