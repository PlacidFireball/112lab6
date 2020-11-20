# Written by Jared Weiss with help from:
# gnu.org/software/make/manual/make.html

# The compiler
CC = gcc
# Flags for the compiler
CFLAGS = -Wall -lm

# The name of the project
PROJ_NAME = lab6
# DEPENDANCIES
DEPS = fns.h
# SOURCE FILES
SRCS = main.c runcomm.c analyze.c
# OBJECT FILES
# - for each word in SRCS replace .c with .o
OBJS = $(SRCS:.c=.o)

# Upon successful compilation, notify the user
all: $(PROJ_NAME)
	@echo Compiled project!

# Executable -> changes based on object files
# comes out as:
# gcc -o pgm2 main.o read_classes.o display.o search.o
$(PROJ_NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROJ_NAME) $(OBJS)

# generic recipe for compiling c files
# makes a .o file based on a .c file
# for example (for main.c), comes out as:
# gcc -Wall fns.h -c main.c
.c.o:
	$(CC) $(CFLAGS) $(DEPS) -c $<

.PHONY: clean
clean:
	rm *.txt
	rm -f *.o *~ $(PROJ_NAME)

# end makefile
