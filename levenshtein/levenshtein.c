#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len++;
    }
    return len;
}

int min_of_three(int n, int m, int l)
{
    if (m < n)
        n = m;
    if (l < n)
        n = l;
    return n;
}

size_t levenshtein(const char *s1, const char *s2)
{
    if (*s1 == '\0')
        return my_strlen(s2);
    if (*s2 == '\0')
        return my_strlen(s1);

    if (*s1 == *s2)
        return levenshtein(s1 + 1, s2 + 1);

    return 1
        + min_of_three(levenshtein(s1, s2 + 1), levenshtein(s1 + 1, s2),
                       levenshtein(s1 + 1, s2 + 1));
}
