# NanoTekSpice — README

## Build
```bash
make

## Run

```bash
./nanotekspice <file.nts>
```

## `.nts` format

### Example

```txt
.chipsets:
input a
input b
output y
4071 or1

.links:
a:1 or1:1
b:1 or1:2
or1:3 y:1
```

### Rules

* `.chipsets:` declares components as: `<type> <name>`
* `.links:` connects pins as: `<name>:<pin> <name>:<pin>`

## Commands

* `simulate` : advance one tick
* `display`  : print tick + all inputs/outputs
* `name=value` : set an input/clock (`0` / `1` / `U` if your parser supports it)
* `exit` : quit

## Supported components

### Basic

* `input`
* `output`
* `clock`
* `true`
* `false`

### Gates ICs

* `4001` (NOR)
* `4011` (NAND)
* `4030` (XOR)
* `4069` (NOT)
* `4071` (OR)
* `4081` (AND)

### Other ICs

* `4008` (4-bit adder)
* `4013` (dual D flip-flop)
* `4017` (decade counter)
* `4040` (12-bit counter)
* `4094` (8-bit shift register)
* `4512` (8-channel selector)
* `4514` (4-to-16 decoder)
* `4801` (RAM)
* `2716` (ROM loaded from `./rom.bin`)
* `logger` (writes bytes to `./log.bin`)
