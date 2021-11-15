#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *ptr = (char *)source;
    char *ptr2 = (char *)dest;
    for (size_t i = 0; i < num; i++)
    {
        ptr[i] = ptr2[i];
    }
    return dest;
}
