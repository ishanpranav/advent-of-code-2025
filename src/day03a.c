// day03a.c
// Copyright (c) 2025 Ishan Pranav and Iris Lim
// Licensed under the MIT license.

#include <ctype.h>
#include <stdio.h>

#include <string.h>
int main(void)
{
    char a[256];
    unsigned int result = 0;

    while (fgets(a, sizeof a, stdin))
    {
        const char* p;

        for (p = &a[1]; *(p + 1) && !isspace(*(p + 1)); p++)
        {
            if (*p > a[0])
            {
                a[0] = *p;
                a[1] = *(p + 1);

                continue;
            }

            if (*p > a[1])
            {
                a[1] = *p;
            }
        }

        if (*p > a[1])
        {
            a[1] = *p;
        }

        result += (a[0] - '0') * 10 + (a[1] - '0');
    }

    printf("%u\n", result);

    return 0;
}
