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





int main(void)
{
    char bob[] = "BoBsIes";
    char george[] = "GeoRgIes";
    my_strlowcase(bob);
    my_strlowcase(george);
    puts(bob);
    puts(george);

    return 0;
}
