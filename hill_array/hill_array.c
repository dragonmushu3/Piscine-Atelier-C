#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (!tab)
        return -1;
    size_t i = 1;
    int res = 0;
    if (len == 1)
        return 0;
    while (i < len && tab[i] >= tab[i - 1])
    {
        if (tab[i] > tab[i - 1])
            res = i;
        i++;
    }
    while (i < len && tab[i] <= tab[i - 1])
    {
        i++;
    }
    size_t billy = i - 1;
    size_t bob = len - 1;
    if (!(bob == billy))
        return -1;
    return res;
}
