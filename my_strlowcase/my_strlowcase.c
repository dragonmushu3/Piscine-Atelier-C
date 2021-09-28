#include <stdio.h>
#include <stddef.h>

void my_strlowcase(char *str)
{
    while (*str != '\0')
    {
        if ( *str <= 'Z' && *str >= 'A')
            *str = *str + ('a'-'A');
        str++;
    }
}




