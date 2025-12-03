// day02b.c
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

    while (scanf("%llu-%llu%*[,]", &left, &right) == 2)
    {
        unsigned int maxK = log10(right) + 1;

        printf("%llu-%llu:", left, right);

        for (unsigned int k = 1; k <= maxK; k++)
        {
            unsigned int maxR = maxK / k;

            for (unsigned int r = 2; r <= maxR; r++)
            {
                unsigned long long mask = (pow(10, k * r) - 1) / (pow(10, k) - 1);
                unsigned long long minX = max(pow(10, k - 1), ceil_div(left, mask));
                unsigned long long maxX = min(pow(10, k) - 1, right / mask);

                if (minX > maxX) {
                    continue;
                }
                result += ((minX + maxX) * (maxX - minX + 1) / 2) * mask;

                for (unsigned long long x = minX; x <= maxX; x++) {
                    printf(" %llu", x * mask);
                }
            }
        }

        printf("\n");
    }

    printf("%llu\n", result);

    return 0;
}
