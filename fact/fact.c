#include <stddef.h>

unsigned long fact(unsigned n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
