#include <stddef.h>
#include <stdio.h>

void sieve(int n)
{
    static int arr[1000] = { 0 };

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            for (int u = i + i; u <= n; u += i)
                arr[u] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
            printf("%d\n", i);
    }
}
