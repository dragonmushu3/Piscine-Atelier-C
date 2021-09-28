
#include <stddef.h>



int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    unsigned int digit(int l, int k)
    {
        if ((l <= 0) || (k <= 0))
            return 0;
        unsigned int quotient = 1;
        for (int i = 1; i <= k; i++)
            quotient *= 10;
        if (k >=2 )
        {
            unsigned int number1 = l % quotient;
            unsigned int number2 = l % (quotient / 10);
            return (number1 - number2) / (quotient / 10);
        }
        return l % quotient;
    }
    int temp = n;
    int no_digits = 0;
    while(!(temp == 0))
    {
        temp = temp / 10;
        no_digits++;
    }


    for( int i = 1; i <= no_digits / 2; i++)
    {
        int pineapple = no_digits - i + 1;
        int apple = i;
        unsigned int a = digit(n,pineapple);
        unsigned int b = digit(n,apple);

        if (a != b)
            return 0;
    }
    return 1;
}




