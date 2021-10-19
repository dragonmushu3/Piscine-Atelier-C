#include "list.h"

struct list *list_add(struct list *l, int e)
{
    struct list *new = calloc(1, sizeof(struct list));
    new->data = e;
    new->next = NULL;
    l->next = new;
    return new;
}
