# blink leds on and off

To build the project run command

```bash
cargo build
```

To flash the elf file to the arduino nano run command

```bash
cargo run
```

```bash
RUSTFLAGS="--emit asm" cargo build
cat target/debug/deps/project_name-hash.s
```

Or in release mode (with optimizations):

```bash
RUSTFLAGS="--emit asm" cargo build --release
cat target/release/deps/project_name-hash.s
```

You can pass different values to the --emit parameter, including (but not limited to):

    mir (Rust intermediate representation)
    llvm-ir (LLVM intermediate representation)
    llvm-bc (LLVM byte code)
    asm (assembly)
