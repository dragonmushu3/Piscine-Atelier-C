#include <stdio.h>
#include <stdlib.h>

unsigned int digit(int l, int k)
{
    if ((l <= 0) || (k <= 0))
        return 0;
    unsigned int quotient = 1;
    for (int i = 1; i <= k; i++)
        quotient *= 10;
    if (k >= 2)
    {
        unsigned int number1 = l % quotient;
        unsigned int number2 = l % (quotient / 10);
        return (number1 - number2) / (quotient / 10);
    }
    return l % quotient;
}

int count_digits(int n)
{
    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;

    int no_digits = 0;
    while (!(n == 0))
    {
        n = n / 10;
        no_digits++;
    }
    return no_digits;
}

char *my_itoa(int value, char *s)
{
    char *res = s;

    if (value < 0)
    {
        value = -value;
        s[0] = '-';
        s++;
    }

    int no_digits = count_digits(value);

    for (int i = 0; i < no_digits; i++)
    {
        s[i] = digit(value, no_digits - i) + 48;
    }

    return res;
}
