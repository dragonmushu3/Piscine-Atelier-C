#include <stddef.h>


size_t my_strlen(const char *s)
{
    if (!s)
        return 0;
    size_t i = 0;
    while(*(s + i) != '\0')
        i++;
    return i;
}
