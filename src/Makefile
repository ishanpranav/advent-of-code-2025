# Makefile
# Copyright (c) 2025 Ishan Pranav
# Licensed under the MIT license.

CC = clang
CFLAGS = -gdwarf-4 -O3 -pedantic -std=c99 -Wall -Wextra

all: \
	day01a day01b

%: %.c
	$(CC) $(CFLAGS) $< -o $@.out

clean:
	rm -f *.out
	