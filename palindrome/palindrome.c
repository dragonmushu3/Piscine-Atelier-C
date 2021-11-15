#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

int my_isalphnum(char c)
{
    return c != 32 && c != 39 && c != ',' && c != '-' && c != '.';
}

int real_len(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        if (my_isalphnum(*s))
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
    size_t true_len = real_len(s);
    size_t i = 0;
    size_t j = len - 1;
    size_t true_index = 0;

    while (true_index < true_len / 2)
    {
        if (my_isalphnum(s[i]))
        {
            if (my_isalphnum(s[j]))
            {
                if (s[i] != s[j])
                    return 0;
                j--;
                i++;
                true_index++;
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    return 1;
}
