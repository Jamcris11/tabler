# Tabler

a simple program to grab table values from a file.

## Compatibilities


Compiled and run on:

| Platform | Compiler | Success? |
|----------|----------|----------|
| Arch Linux | gcc-12.1.0 | ✔️ |
| Windows 10 | mingw32-4.8.3 | ✔️ |

## How to use

```
tabler FILENAME [patterns...]
```

**FILENAME**: is required, this points to your table file. The table file needs to be of the same format as the provided example_table.txt.

**patterns**: can be one or more arguments that will try and match the first column of your table file. If it finds the argument provided, the program will print out the second column corrolated to the match.