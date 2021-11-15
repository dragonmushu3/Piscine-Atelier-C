#include <stddef.h>

int vmax(const int *ptr, size_t size)
{
    int max = *ptr;
    int vice_max = *ptr;

    for (size_t i = 0; i < size; i++)
    {
        if (ptr[i] > max)
        {
            int temp = max;
            max = ptr[i];
            vice_max = temp;
        }
    }
    return vice_max;
}
