#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *list2 = NULL;
    list2 = malloc(sizeof(struct list));
    memcpy((*list2).data, value, data_size);
    (*list2).next = list;
    return list2;
}

size_t list_length(struct list *list)
{
    if (list == NULL)
        return 0;
    return 1 + list_length(list->next);
}

void list_destroy(struct list *list)
{
    if (list == NULL)
        return;
    list_destroy(list->next);
    free(list->data);
    free(list);
}
