#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

size_t count_diff_str(const char *lev, const char *s_big, size_t len)
{
    size_t res = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (lev[i] != s_big[i])
            res++;
    }
    return res;
}

char *my_strcpy(const char *s,size_t len)
{
    char *res = malloc(sizeof(char) * (len + 1));
    for (size_t i = 0; i < len; i++)
    {
        res[i] = s[i];
    }
    res[len] = '\0';
    return res;
}

char *strcpy_no_spaces(const char *s, size_t *len, size_t *spaces)
{
    size_t t_spaces = 0;
    size_t j = 0;
    char *res = malloc(sizeof(char) * (*len + 1));
    for (size_t i = 0; i < *len; i++)
    {
        if (s[i] == 32)
            t_spaces += 1;
        else
        {
            res[j] = s[i];
            j++;
        }
    }
    res = realloc(res, (*len + 1) - t_spaces);
    res[(*len + 1) - t_spaces] = '\0';
    *spaces += t_spaces;
    *len -= t_spaces;
    return res;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    size_t big_len = 0;
    size_t small_len = 0;
    size_t spaces = 0;
    char *small_str = NULL;
    char *big_str = NULL;

    if (len1 <= len2)
    {
        small_len = len1;
        small_str = strcpy_no_spaces(s1, &small_len, &spaces);
        big_len = len2;
        big_str = strcpy_no_spaces(s2, &big_len, &spaces);
    }
    else
    {
        small_len = len2;
        small_str = strcpy_no_spaces(s2, &small_len, &spaces);
        big_len = len1;
        big_str = strcpy_no_spaces(s1, &big_len, &spaces);
    }

    char *lev = malloc(sizeof(char) * (big_len + 1));

    for (size_t i = 0; i < big_len + 1; i++)
    {
        if (i < small_len)
            lev[i] = small_str[i];
        else
            lev[i] = '\0';
    }

    size_t res = count_diff_str(big_str, lev, big_len);
    free(lev);
    free(big_str);
    free(small_str);
    return res + spaces;
}
