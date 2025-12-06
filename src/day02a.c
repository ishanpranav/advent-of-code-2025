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
    unsigned long long left, right;
    unsigned long long result = 0;

    while (scanf(" %llu-%llu%*[,]", &left, &right) == 2)
    {
        unsigned int minK = ceil_div(log10(left) + 1, 2);
        unsigned int maxK = (log10(right) + 1) / 2;
        unsigned long long a = pow(10, minK);

        for (unsigned int k = minK; k <= maxK; k++)
        {
            unsigned long long mask = a + 1;
            unsigned long long minX = max(mask / 10, ceil_div(left, mask));
            unsigned long long maxX = min(mask - 2, right / mask);

            result += ((minX + maxX) * (maxX - minX + 1) / 2) * mask;
            a *= 10;
        }
    }

    printf("%llu\n", result);

    return 0;
}
