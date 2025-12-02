// day01a.c
// Copyright (c) 2025 Ishan Pranav
// Licensed under the MIT license.

// Secret Entrance

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned int mod(int dividend, int divisor)
{
    return ((dividend % divisor) + divisor) % divisor;
}

int main(void)
{
    char buffer[8];
    unsigned int dial = 50;
    unsigned int count = 0;

    while (fgets(buffer, sizeof buffer, stdin))
    {
        if (isspace(*buffer))
        {
            continue;
        }     

        int distance = atoi(buffer + 1);
        
        distance = buffer[0] == 'L' ? -distance : distance;
        
        int nextDial = dial + distance;

        if (dial != 0 && nextDial < 0)
        {
            count++;
        }

        count += abs(nextDial) / 100;

        if (nextDial == 0)
        {
            count++;
        }
        
        dial = mod(nextDial, 100);
    }

    printf("%u\n", count);

    return EXIT_SUCCESS;
}
