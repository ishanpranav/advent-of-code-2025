// day04a.c
// Copyright (c) 2025 Ishan Pranav
// Licensed under the MIT license.

// Printing Department

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned int i;
    unsigned int j;
} 
Coordinate;

typedef struct
{
    unsigned int first;
    unsigned int last;
    Coordinate items[256 * 256];
} 
CoordinateQueue;

static void coordinate_queue(CoordinateQueue* instance)
{
    instance->first = UINT_MAX;
    instance->last = UINT_MAX;
}

static void coordinate_queue_enqueue(CoordinateQueue* instance, Coordinate item)
{
    if (instance->first == UINT_MAX)
    {
        instance->first = 0;
        instance->last = 0;
        instance->items[0] = item;

        return;
    }

    instance->last = (instance->last + 1) % (256 * 256);
    instance->items[instance->last] = item;
}

static Coordinate coordinate_queue_dequeue(CoordinateQueue* instance)
{
    Coordinate result = instance->items[instance->first];

    if (instance->first == instance->last)
    {
        instance->first = UINT_MAX;
        instance->last = UINT_MAX;
    
        return result;
    }

    instance->first = (instance->first + 1) % (256 * 256);

    return result;
}

static void decrement(
    const char a[256][256], 
    unsigned int d[256][256],
    CoordinateQueue* q,
    unsigned int i,
    unsigned int j)
{
    if (a[i][j] != '@' || d[i][j] == 0) { return; }

    d[i][j]--;

    if (d[i][j] < 4)
    {
        Coordinate u = { .i = i, .j = j };
        
        coordinate_queue_enqueue(q, u);
    }
}

int main(void)
{
    char a[256][256];
    unsigned int d[256][256];

    if (!fgets(&a[1][1], sizeof * a - 1, stdin)) { return 1; }
    
    unsigned int n = 2;
    
    a[1][0] = '.';

    unsigned int m = strlen(a[1]);

    while (isspace(a[1][m - 1])) { m--; }

    a[1][m] = '.';
    m++;

    memset(a[0], '.', m * sizeof ** a);
    
    while (fgets(&a[n][1], sizeof * a - 1, stdin))
    {
        a[n][0] = '.';
        a[n][m - 1] = '.';
        n++;
    }

    memset(a[n], '.', m * sizeof ** a);

    n++;

    Coordinate u;
    CoordinateQueue q;

    coordinate_queue(&q);

    for (u.i = 1; u.i < n - 1; u.i++)
    {
        for (u.j = 1; u.j < m - 1; u.j++)
        {
            if (a[u.i][u.j] != '@') { continue; }

            unsigned int du = 
                (a[u.i - 1][u.j - 1] == '@') +
                (a[u.i - 1][u.j] == '@') +
                (a[u.i - 1][u.j + 1] == '@') +
                (a[u.i][u.j - 1] == '@') +
                (a[u.i][u.j + 1] == '@') +
                (a[u.i + 1][u.j - 1] == '@') +
                (a[u.i + 1][u.j] == '@') +
                (a[u.i + 1][u.j + 1] == '@');

            d[u.i][u.j] = du;

            if (du < 4) { coordinate_queue_enqueue(&q, u); }
        }
    }

    unsigned int count = 0;

    while (q.first != UINT_MAX)
    {
        u = coordinate_queue_dequeue(&q);

        if (a[u.i][u.j] != '@') { continue; }

        a[u.i][u.j] = '.';

        decrement(a, d, &q, u.i - 1, u.j - 1);
        decrement(a, d, &q, u.i - 1, u.j);
        decrement(a, d, &q, u.i - 1, u.j + 1);
        decrement(a, d, &q, u.i, u.j - 1);
        decrement(a, d, &q, u.i, u.j + 1);
        decrement(a, d, &q, u.i + 1, u.j - 1);
        decrement(a, d, &q, u.i + 1, u.j);
        decrement(a, d, &q, u.i + 1, u.j + 1);

        count++;
    }

    printf("%u\n", count);

    return 0;
}
