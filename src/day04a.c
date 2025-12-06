// day04a.c
// Copyright (c) 2025 Ishan Pranav
// Licensed under the MIT license.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[256][256];

    if (!fgets(&a[1][1], sizeof * a - 1, stdin))
    {
        return 1;
    }
    
    unsigned int n = 2;
    
    a[1][0] = '.';

    unsigned int m = strlen(a[1]);

    while (isspace(a[1][m - 1])) { m--; }

    m++;

    a[1][m - 1] = '.';

    memset(a[0], '.', m * sizeof ** a);
    
    while (fgets(&a[n][1], sizeof * a - 1, stdin))
    {
        a[n][0] = '.';
        a[n][m - 1] = '.';
        n++;
    }

    memset(a[n], '.', m * sizeof ** a);

    n++;

    unsigned int count = 0;

    for (unsigned int i = 1; i < n - 1; i++)
    {
        for (unsigned int j = 1; j < m - 1; j++)
        {
            if (a[i][j] == '@' &&
                ((a[i - 1][j - 1] == '@') +
                (a[i - 1][j] == '@') +
                (a[i - 1][j + 1] == '@') +
                (a[i][j - 1] == '@') +
                (a[i][j + 1] == '@') +
                (a[i + 1][j - 1] == '@') +
                (a[i + 1][j] == '@') +
                (a[i + 1][j + 1] == '@') < 4))
            {
                count++;
            }
        }
    }

    printf("%u\n", count);

    return 0;
}
