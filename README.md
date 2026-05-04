# SystemONE Utilities

SystemONE-Utilities is a set of common unix utilities (like echo, pwd, uname). the motto of this project is
"Simple as BSD, useful as GNU". This utilities are not completely posix, in some of the concept is the same 
but the flags or implementation is different, examples of this are:

- sleep
This command is simpler than GNU contrapart, uses only integers and required the -s (seconds) flag.

- yes
It has more function than BSD but it slower than GNU (not use buffer), extra function: -i (interval in seconds) 
and -n (number of repetitions), and print all arguments (BSD only print the first one)

- seq
Do not support float number and do not support negative integers for increment value

# Custom Utilities
- prime 
print if a number is prime or not, with the next ouput: "x is prime" or "x is not prime".

- SystemONE-version
an information tool about SystemONE

# Why?
The goal is make an useful userland from scratch, and to be able to replace GNU software:
- Coreutils
- Findutils
- Diffutils
- and more

The goal is not only to be able to replace GNU, but rather other projects like: uutils, Chimerauitls, Busybox...

# Important
This project do not (and will not) have all gnu options, only the useful and needed options will be added
