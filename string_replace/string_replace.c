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
    size_t total_buffer_size = nb_occur * pattern_len + (current_len - nb_occur);
    char *new_str_buffer = calloc(total_buffer_size + 1, sizeof(char));

    size_t str_i = 0;
    size_t buffer_j = 0;
    while (str_i < current_len)
    {
        if (str[str_i] == c)
        {
            size_t k = 0;
            while ( k < pattern_len)
            {
                new_str_buffer[buffer_j] = pattern[k];
                k++;
                buffer_j++;
            }
            str_i++;
        }
        else
        {
            new_str_buffer[buffer_j] = str[str_i];
            str_i++;
            buffer_j++;
        }
    }

    new_str_buffer[total_buffer_size] = '\0';
    return new_str_buffer;
}
