#include <stddef.h>

char *my_strcpy(char *dest, const char *source)
{
    size_t i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
