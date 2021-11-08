#include <stdio.h>
#include <stdlib.h>

int my_abs(int n)
{
    return n * -1 * (n < 0) + n * (n >= 0);
}
