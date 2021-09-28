#include <stddef.h>

void plus_equal(int *a, int*b)
{
    *a = *a + *b;
}

void minus_equal(int *a, int*b)
{
    *a = *a - *b;
}

void mult_equal(int *a, int *b)
{
    *a = *a * *b;
}

int div_equal(int *a, int*b)
{
    if ((!a) || (*b == 0))
        return 0;
    int res = (*a % *b);
    *a = *a / *b;
    return res;
}


