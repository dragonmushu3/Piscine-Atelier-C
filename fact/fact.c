#include <stddef.h>

unsigned long fact(unsigned n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
