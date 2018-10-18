# CS460TEAM
## Team Semantic

Ian Jared and Clayton

![Alt Text](https://78.media.tumblr.com/cd6bf1ff5b7e508c78dd8522c52cc766/tumblr_op2o49oV6g1tzqospo1_500.gif)

Work Distribution
We all pair programmed on a large portion of the project. Some areas of
individual effort are the following:

Ian: Symbol Table, Debug Flags for Lex, Node Class, Symbol Table Driver, Symbol
Table integration.
Clayton: Yacc Grammar and Parts of Lex, Main in Yacc, Implementing file parsing
with command line argument.
Jared: Symbol Table, Yacc, and Lex, Symbol Table Driver, Symbol Table
Integration

## Building
#### Dependencies
    - Flex >= 2.6.4
    - Bison >= 3.1
    - g++ >= 8.2.1
    - make >= 3.81
Run make in the src folder in local terminal
```
make
```
#### Running
The binary is called fcc for Fred C Compliler.
###### Command Line Options:
    - -i <inputfile>: (Required) Provide a file to compile
    - -o <outputfile>: (Optional) Provide a file to output debug options to.
      Defaults to output.txt if no file is provided.
    - -dl: This will print out all of the tokens
    - -dp: This will print out all of the productions with the source code
    - -ds: This will print out all of the contents of the Symbol Table
    - -fh: Prints our inspiration -Ian

###### Source Code Debug Options
In order to use these options, put the flags inside of the source code.
    - !!dl: Turns on token output until the next !!dl flag is reached.
    - !!dp: Turns on production output until the next !!dp flag is reached.
    - !!ds: Turns on Symbol Table output until the next !!ds flag is reached.

Examples:
This example has an input file called foo.c and an output file called
fooOuput.txt
```
./fcc -i foo.c -o fooOuput.txt
```
This example has an input file called bar.c and prints out all of the tokens
that are matched.
```
./fcc -i bar.c -dl

```
This example has an input file called foo.c and prints out all productions and
the contents of the symbol table.
```
./fcc -i foo.c -dp -ds
```
