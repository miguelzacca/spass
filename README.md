# spass

Simple password generator with command line. Linux only

## Install

```bash
git clone https://github.com/miguelzacca/spass.git
chmod +x ~/spass/main ~/spass/config.sh
~/spass/config.sh
```

## Use

```bash
spass <-|-l|-n> <SIZE>
```

- `-` letters and numbers
- `-l` only letters
- `-n` only numbers

## Example

```bash
spass - 16 
```

```bash
spass -n 16
```
