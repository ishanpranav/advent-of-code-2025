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
    int dial = 50;
    bool isZero = false;
    unsigned int count = 0;

    while (fgets(buffer, sizeof buffer, stdin))
    {
        if (isspace(*buffer))
        {
            continue;
        }     

        isZero = dial == 0;

        int distance = atoi(buffer + 1);
        
        distance = buffer[0] == 'L' ? -distance : distance;
        dial += distance;

        if (dial < 0 && !isZero)
        {
            count++;
        }

        count += abs(dial) / 100;

        if (dial == 0)
        {
            count++;
        }
        
        dial = mod(dial, 100);
    }

    printf("%u\n", count);

    return EXIT_SUCCESS;
}
