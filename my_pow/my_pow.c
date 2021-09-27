
#include <stddef.h>



int my_pow(int a, int b)
{
    int res = a;
    for(int i = 1; i <= (b / 2); i++)
    {
        printf("%d iterations!\n",i);
        if ( i % 2 == 0)
        {
            res = res * res;
        }
        res = res * a;
    }
    return res;
}


