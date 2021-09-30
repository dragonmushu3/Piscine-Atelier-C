#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    int *arr = calloc(n, sizeof(int));
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int u = i + i; u < n; u += i)
                arr[u] = 1;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 0)
            printf("%d\n",i);
    }
}
