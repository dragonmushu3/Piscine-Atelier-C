#include <stddef.h>
#include <stdlib.h>

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = 0;
    size_t len2 = 0;
    size_t len = 0;
    int smoll = 0;
    size_t res = 0;

    for (size_t i = 0; s1[i] != '\0'; i++)
        len1++;
    for (size_t j = 0; s2[j] != '\0'; j++)
        len2++;

    if (len1 <= len2)
    {
        smoll = 1;
        len = len2;
    }
    else
    {
        smoll = 0;
        len = len1;
    }

    char *lev = malloc(sizeof(char) * len);

    if (smoll == 0)
    {
        for (size_t i = 0; i < len2; i++)
            lev[i] = s2[i];
        if (len > len2)
        {
            for (size_t i = len2; i < len; i++)
                lev[i] = 0;
        }
        for (size_t i = 0; i < len1; i++)
        {
            if (lev[i] != s1[i])
                res++;
        }
    }
    else
    {
        for (size_t i = 0; i < len1; i++)
            lev[i] = s1[i];
        if (len > len1)
        {
            for (size_t i = len1; i < len; i++)
                lev[i] = 0;
        }
        for (size_t i = 0; i < len2; i++)
        {
            if (lev[i] != s2[i])
                res++;
        }
    }
    free(lev);
    return res;
}
