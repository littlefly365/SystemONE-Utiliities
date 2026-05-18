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
------------------------------------------------
| `--version`     |   Print version            |
------------------------------------------------

# Examples (Linux x86_64):

`arch` ---> "x86_64.Linux"

`arch -s` ---> "x86_64"

`arch --version` ---> " arch (SystemONE coreutils) 1.0"
