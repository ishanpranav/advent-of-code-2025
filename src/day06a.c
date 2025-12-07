// day06a.c
// Copyright (c) 2025 Ishan Pranav and Iris Lim
// Licensed under the MIT license.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buffer[4096];
    char* p = NULL;
    unsigned int a[4][1024];
    unsigned char f[1024];
    unsigned int n = 0;
    unsigned int m;

    while (fgets(buffer, sizeof buffer, stdin))
    {
        p = strtok(buffer, " ");

        if (*p == '+' || *p == '*') { break; }

        m = 0;

        do
        {
            a[n][m] = atoi(p);
            m++;
            p = strtok(NULL, " ");
        }
        while (p);

        n++;
    }

    unsigned int j = 0;

    do
    {
        f[j] = *p;
        j++;
        p = strtok(NULL, " ");
    }
    while (p);

    unsigned long long b[1024];

    for (unsigned int j = 0; j < m; j++) { b[j] = a[0][j]; }

    for (unsigned int i = 1; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            b[j] = f[j] == '*' ? (b[j] * a[i][j]) : (b[j] + a[i][j]);
        }
    }

    for (j = 1; j < m; j++) { b[0] += b[j]; }

    printf("%llu\n", b[0]);

    return EXIT_SUCCESS;
}
