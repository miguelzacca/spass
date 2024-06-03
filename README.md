# spass

Password generator with command line.

## Install - Linux

```bash
git clone https://github.com/miguelzacca/spass.git
chmod +x ~/spass/main-deb ~/spass/config.sh
~/spass/config.sh
```

## Install - Windows

```cmd
git clone https://github.com/miguelzacca/spass.git
cd %HOMEPATH%/spass
config.bat
cd %HOMEPATH%
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
