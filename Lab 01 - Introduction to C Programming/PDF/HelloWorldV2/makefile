#
# Default rule to execute when the make command has no arguments
#
all: helloworld


#
# Preprocessor + compiler + assembler step (produces object files)
#
helloworld.o: helloworld.c helperfunctions.h
	gcc -c helloworld.c -o helloworld.o -Wall -pedantic
	
helperfunctions.o: helperfunctions.c
	gcc -c helperfunctions.c -o helperfunctions.o -Wall -pedantic


#
# linker step (produces final executable file)
#
helloworld: helloworld.o helperfunctions.o
	gcc helloworld.o helperfunctions.o -o helloworld -Wall -pedantic


#
# The command-line 'make clean' executes the following command
# (removes all files created during build).
#
clean:
	rm -f helloworld helloworld.o helperfunctions.o


#
# Lists the "phony" rules in this file ('all' and 'clean').
#
.PHONY: all clean