
#include <stddef.h>

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;

    int old_a = a;
    int ref_a = a;
    for (size_t i = 0;, i < b - 1; i++)
    {
        old_a = a;
        a = ref_a * old_a;
    }
    return a;
}
