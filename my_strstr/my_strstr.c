#include <stdio.h>

int my_strlen(const char *str)
{
    int res = 0;
    while (*str != '\0')
    {
        str++;
        res++;
    }
    return res;
}

int compare_needle(const char *ptr, const char *needle)
{
    int ok_chars = 0;
    for (int i = 0; ptr[i] != '\0' && i < my_strlen(needle); i++)
    {
        if (ptr[i] == needle[i])
            ok_chars += 1;
    }

    if (ok_chars == my_strlen(needle))
        return 1;
    else
        return 0;
}

int my_strstr(const char *haystack, const char *needle)
{
    if (!needle || my_strlen(needle) == 0)
        return 0;

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        if (compare_needle(haystack + i, needle))
            return i;
    }

    return -1;
}
