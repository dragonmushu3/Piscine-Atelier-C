#include "hash_map.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "utilities.h"

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *m = malloc(sizeof(struct hash_map) * 1);
    if (!m)
        return NULL;

    m->data = malloc(sizeof(struct pair_list) * size);
    for (size_t i = 0; i < size; i++)
        m->data[i] = NULL;
    m->size = size;
    return m;
}

void free_linked_list(struct pair_list *list)
{
    if (!list)
        return;
    free_linked_list(list->next);
    free(list->value);
    free(list);
}

void hash_map_free(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        free_linked_list(hash_map->data[i]);
    }
    free(hash_map);
}

struct pair_list *list_prepend(const char *key, char *value)
{
    struct pair_list *pair_list2 = NULL;
    pair_list2 = malloc(sizeof(struct pair_list));
    if (!pair_list2)
        return NULL;
    pair_list2->value = value;
    pair_list2->key = key;
    return pair_list2;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    int h_new = hash(key) % hash_map->size;
    struct pair_list *to_update = find_list(hash_map->data[h_new], key);
    if (to_update)
    {
        size_t val_size = my_strlen(value);
        char *update = to_update->value;
        for (size_t i = 0; i < val_size; i++)
            update[i] = value[i];
        *updated = true;
    }
    else
    {
        hash_map->data[h_new] = list_prepend(hash_map->data[h_new]);
    }

    if
        !(hash_map->data[h_new]) return false;
}

const char *hash_map_get(const struct hash_map *hash, const char *key)
{
    for (size_t i = 0; i < hash->size; i++)
    {
        char *res = find_list_char(hash->data[i], key) if (res) return res;
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash, const char *key)
{
    for (size_t i = 0; i < hash->size; i++)
    {
        struct pair_list *prec = find_precedent(hash->data[i], key);
        if (prec)
        {
            struct pair_list *temp = prec->next;
            prec->next = prec->next->next;
            free(temp);
            return true;
        }
    }
    return false;
}
