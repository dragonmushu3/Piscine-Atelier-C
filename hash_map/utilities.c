#include "hash_map.h"

size_t my_strlen(char *s)
{
    size_t i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int eq_strings(const char *str1, const char *str2)
{
    size_t size1 = my_strlen(str1);
    size_t size2 = my_strlen(str2);
    if (size1 != size2)
        return 0;
    else
    {
        for (size_t i = 0; i < size1; i++)
        {
            if (str1[i] != str2[i])
                return 0;
        }
    }
    return 1;
}

struct pair_list *find_list(struct pair_list *list, const char *key)
{
    if (!list)
        return NULL;
    size_t size1 = my_strlen(key);
    size_t size2 = my_strlen(list->key);
    if (size1 != size2)
        return NULL;
    else
    {
        for (size_t i = 0; i < size1; i++)
        {
            if (key[i] != list->key[i])
                return find_list(list->next, key);
            else
                continue;
        }
        return list;
    }
}

struct pair_list *find_precedent(struct pair_list *list, char *key)
{
    if (!list)
        return NULL;
    if (eq_strings(list->next->key, key))
        return list;
    return find_precedent(list->next);
}

char *find_list_char(struct pair_list *list, char *key)
{
    if (!list)
        return NULL;
    if (eq_strings(list->key, key))
        return list->value;
    return find_list(list->next);
}
