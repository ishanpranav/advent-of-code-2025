// day05a.c
// Copyright (c) 2025 Ishan Pranav and Iris Lim
// Licensed under the MIT license.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned long long left;
    unsigned long long right;
} Interval;

static int interval_compare(const void* left, const void* right)
{
    const Interval* p = left;
    const Interval* q = right;

    if (p->left < q->left) { return -1; }
    if (p->left > q->left) { return 1; }
    if (p->right > q->right) { return -1; }
    if (p->right < q->right) { return 1; }

    return 0;
}

static int interval_ullong_compare(const void* key, const void* element)
{
    unsigned long long value = *(const unsigned long long*)key;
    const Interval* interval = element;
    
    if (value < interval->left) { return -1; }
    if (value > interval->right) { return 1; }

    return 0;
}

int main(void)
{
    Interval intervals[256];
    unsigned int n = 0;
    int status = 0;

    for (;;)
    {
        status = scanf(" %llu-%llu", &intervals[n].left, &intervals[n].right);

        if (status == 1) { break; }
        if (status != 2) { return EXIT_FAILURE; }

        n++;
    }

    unsigned long long values[1024];
    
    values[0] = intervals[n].left;

    unsigned int m = 1;

    while (scanf(" %llu", &values[m]) == 1) { m++; }

    qsort(intervals, n, sizeof * intervals, interval_compare);

    unsigned int j = 0;

    for (unsigned int i = 1; i < n; i++)
    {
        if (intervals[i].left <= intervals[j].right)
        {
            if (intervals[i].right > intervals[j].right)
            {
                intervals[j].right = intervals[i].right;
            }

            continue;
        }

        j++;
        intervals[j] = intervals[i];
    }

    n = j + 1;

    for (unsigned int i = 0; i < n; i++) {
        printf("%llu-%llu\n", intervals[i].left, intervals[i].right);
    }

    unsigned int count = 0;

    for (unsigned int i = 0; i < m; i++)
    {
        if (bsearch(
            &values[i], 
            intervals, 
            n, 
            sizeof * intervals, 
            interval_ullong_compare))
        {
            printf("%llu\n", values[i]);

            count++;
        }
    }

    printf("%u\n", count);

    return EXIT_SUCCESS;
}
