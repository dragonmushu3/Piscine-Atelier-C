#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s !='\0')
    {
        res++;
        s++;
    }
    return res;
}

int palindrome(const char *s)
{
    if (!s)
        return 0;

    size_t len = my_strlen(s);
    size_t i = 0;
    while (i < len / 2)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
        i++;
    }
    return 1;
}
