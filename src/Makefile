# Makefile
# Copyright (c) 2025 Ishan Pranav
# Licensed under the MIT license.

CC = clang
CFLAGS = -fsanitize=undefined -gdwarf-4 -O3 -pedantic -std=c99 -Wall -Wextra

all: \
	day01a day01b

%: %.c
	$(CC) $(CFLAGS) $< -o $@.out

day02a: day02a.c
	$(CC) $(CFLAGS) -lm $< -o $@.out

day02b: day02b.c
	$(CC) $(CFLAGS) -lm $< -o $@.out

clean:
	rm -f *.out
	