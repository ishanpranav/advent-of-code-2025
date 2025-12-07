// day05b.c
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

int main(void)
{
    Interval intervals[256];
    unsigned int n = 0;

    while (scanf(" %llu-%llu", &intervals[n].left, &intervals[n].right) == 2)
    {
        n++;
    }

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

    unsigned long long count = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        count += intervals[i].right - intervals[i].left + 1;
    }

    printf("%llu\n", count);

    return EXIT_SUCCESS;
}
