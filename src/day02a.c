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

int main(void)
{
    unsigned long long iMin, iMax;
    unsigned long long sum = 0;

    while (scanf("%llu-%llu%*[,]", &iMin, &iMax) == 2)
    {
        unsigned int nMin = log10(iMin) + 1;
        unsigned int kMin = (nMin + (nMin % 2)) / 2;
        unsigned int nMax = log10(iMax) + 1;
        unsigned int kMax = (nMax - (nMax % 2)) / 2;

        printf("%llu-%llu [%u-%u]: ", iMin, iMax, kMin, kMax);
        
        for (unsigned int k = kMin; k <= kMax; k++)
        {
            unsigned long long xMin = pow(10, k - 1);
            
            xMin = max(xMin, iMin / pow(10, nMin - k));

            unsigned long long xMax = pow(10, k) - 1;

            xMax = min(xMax, iMax / pow(10, nMax - k));
            
            if (xMin > xMax) {
                unsigned long long swap = xMin;
                xMin = xMax;
                xMax = swap;
                
            }
            if (kMin == 1 && kMax == 1) {
                printf("xMin = %llu xMax = %llu\n", xMin, xMax);
            }

            for (unsigned long long x = xMin; x <= xMax; x++)
            {
                unsigned long long pattern = x * pow(10, k) + x;
                
                if (pattern >= iMin && pattern <= iMax)
                {
                    printf("%llu ", pattern);

                    sum += pattern;
                }
            }
        }

        printf("\n");
    }

    printf("answer: %llu", sum);

    return 0;
}
