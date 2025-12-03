// day02a.c
// Copyright (c) 2025 Ishan Pranav
// Licensed under the MIT license.

// Gift Shop

#include <math.h>
#include <stdio.h>
#include <string.h>

static unsigned long long min(unsigned long long left, unsigned long long right)
{
    if (left < right)
    {
        return left;
    }

    return right;
}

static unsigned long long max(unsigned long long left, unsigned long long right)
{
    if (left > right)
    {
        return left;
    }

    return right;
}

static unsigned long long ceil_div(
    unsigned long long dividend,
    unsigned long long divisor)
{
    return (dividend + divisor - 1) / divisor;
}

int main(void)
{
    unsigned long long minI, maxI;
    unsigned long long result = 0;

    while (scanf("%llu-%llu%*[,]", &minI, &maxI) == 2)
    {
        unsigned int minK = ceil_div(log10(minI) + 1, 2);
        unsigned int maxK = (log10(maxI) + 1) / 2;

        for (unsigned int k = minK; k <= maxK; k++)
        {
            unsigned long long m = pow(10, k);
            unsigned long long minX =
                max(m / 10, ceil_div(minI, m + 1));
            unsigned long long maxX =
                min(m - 1, maxI / (m + 1));

            result += ((minX + maxX) * (maxX - minX + 1) / 2) * (m + 1);
        }
    }

    printf("%llu\n", result);

    return 0;
}
