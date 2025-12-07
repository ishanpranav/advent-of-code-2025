// day03b.c
// Copyright (c) 2025 Ishan Pranav and Iris Lim
// Licensed under the MIT license.

// Lobby

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char items[12];
    unsigned int count;
}
Stack;

int main(void)
{
    char a[256];
    unsigned long long result = 0;

    while (fgets(a, sizeof a, stdin))
    {
        Stack s;

        s.count = 0;

        unsigned int n = strlen(a);

        while (isspace(a[n - 1])) { n--; }

        for (unsigned int i = 0; i < n; i++)
        {
            while (s.count
                && s.items[s.count - 1] < a[i]
                && (n - i + s.count) > 12)
            {
                s.count--;
            }

            if (s.count < 12)
            {
                s.items[s.count] = a[i];
                s.count++;
            }
        }

        s.items[s.count] = '\0';

        result += strtoull(s.items, NULL, 10);
    }

    printf("%llu\n", result);

    return EXIT_SUCCESS;
}
