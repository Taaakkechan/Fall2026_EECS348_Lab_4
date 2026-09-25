CC = gcc
CFLAGS = -Wall -Wextra -std=c11
PROGRAMS = nfl_score another_program

.PHONY: all clean

all: $(PROGRAMS)

# Pattern rule: builds any program from its matching .c file
%: %.c
	$(CC) $(CFLAGS) -o $@ $

clean:
	rm -f $(PROGRAMS)