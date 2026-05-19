# arch

# Description
The arch command prints the architecture name and the kernel name 
separated by a period (unless the -s option is used) in this way the arch 
command behaves similarly to the OpenBSD version. 

# Options:

----------------------------------------------
| Options | Description                      |
|---------|----------------------------------|
|  `-s`   | Print only the architecture name |
----------------------------------------------

# General Options:

------------------------------------------------
| General Options |    Description             |
|-----------------|----------------------------|
|  `--help`       |   Print help information   |
| `--version`     |   Print version            |
------------------------------------------------

# Examples (Linux x86_64):

`arch` -> x86_64.Linux

`arch -s` -> x86_64

# Exit code:

- 0: Returns 0 if there was no error.
- 1: Returns 1 when an error has occurred in the program (example: uname syscall).
- 2: Returns 2 when an error has occurred in the option parser (example: unknown option or bad usage).

# GNU Compatibility:

- It behaves the same if the -s flag has been used.

# Authors:

- [littlefly365](https://github.com/cristianherrera26)
