#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

void print_linked_list(struct pair_list *list)
{
    if (!list)
        return;
    printf("%s", list->key);
    putchar(':');
    if (list->next)
        printf(" %s,", list->value);
    printf(" %s", list->value);
    print_linked_list(list->next);
}

void hash_map_dump(struct hash_map *hash)
{
    for (size_t i = 0; i < hash->size; i++)
    {
        print_linked_list(hash->data[i]);
    }
}
