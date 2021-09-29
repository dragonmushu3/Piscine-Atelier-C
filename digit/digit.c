#include <stddef.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    unsigned int quotient = 1;
    for (int i = 1; i <= k; i++)
        quotient *= 10;
    if (k >= 2)
    {
        unsigned int number1 = n % quotient;
        unsigned int number2 = n % (quotient / 10);
        return (number1 - number2) / (quotient / 10);
    }
    return n % quotient;
}
