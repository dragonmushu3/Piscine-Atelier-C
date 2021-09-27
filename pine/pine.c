
#include <stdio.h>





int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }
    for (unsigned i = 1; i <= n ; i++)
    {
        for (unsigned k = 1; k <= (n - i); k++)
        {
            putchar(32);
        }
        for (unsigned j = 1; j <= (2 * i)-1; j++)
        {
            putchar('*');
        }
        puts("");
    }
    for (unsigned l = 1; l <= (n / 2); l++)
    {
        for (unsigned m = 1; m <= (n - 1); m++)
        {
            putchar(32);
        }
        putchar('*');
        puts("");
    }
    return 0;
}



