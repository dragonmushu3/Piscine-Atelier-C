#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while(*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

size_t count_char_occ(const char *s, char c)
{
    size_t res = 0;
    while(*s != '\0')
    {
        if (*s == c)
        {
            res++;
        }
        s++;
    }
    return res;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    size_t nb_occur = count_char_occ(str, c);
    size_t current_len = my_strlen(str);
    size_t pattern_len = my_strlen(pattern);

    /* one more for null character */
    char *new_str_buffer = calloc(nb_occur * pattern_len + (current_len - nb_occur) + 1, sizeof(char));

    size_t i = 0;
    while (i < current_len)
    {
        if (str[i] == c)
        {
            size_t j = 0;
            while ( j < pattern_len)
            {
                new_str_buffer[i] = pattern[j];
                i++;
                j++;
            }
        }

        new_str_buffer[i] = str[i];
        i++;
    }

    new_str_buffer = '\0';
    return new_str_buffer;
}
