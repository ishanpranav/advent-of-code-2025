// day01a.c
// Copyright (c) 2025 Ishan Pranav
// Licensed under the MIT license.

// Secret Entrance

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned int mod(int dividend, int divisor)
{
    return ((dividend % divisor) + divisor) % divisor;
}

int main(void)
{
    char buffer[5];
    unsigned int dial = 50;
    unsigned int count = 0;

    while (fgets(buffer, sizeof buffer, stdin))
    {
        if (isspace(*buffer))
        {
            continue;
        }     

        int direction = buffer[0] == 'L' ? -1 : 1;
        int distance = atoi(buffer + 1);

        dial = mod(dial + direction * distance, 100);

        if (dial == 0)
        {
            count++;
        }
    }

    printf("%u\n", count);

    return EXIT_SUCCESS;
}
