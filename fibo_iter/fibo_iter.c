#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    unsigned long u0 = 0;
    unsigned long u1 = 1;
    unsigned long res = 0;
    
    for (unsigned long i = 0; i < n; i++)
    {
        res = u0 + u1;
        u0 = u1;
        u1 = res;
    }
    return res;
}
