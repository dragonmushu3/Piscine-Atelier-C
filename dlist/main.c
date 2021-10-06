#include "dlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void list_free(struct dlist_item *item)
{
    if (!item)
        return;
    list_free(item->next);
    free(item);
}

int main(void)
{
    struct dlist *list = dlist_init();
    for (size_t i = 1; i <= 100; i++)
        dlist_push_front(list, i);
    struct dlist_item *item1 = list->tail;
    struct dlist_item *item2 = list->head;

    int data1 = item1->data;
    int data2 = item1->next->data;
    printf("first two chains are %d and %d", data1, data2);
    assert(data1 == 1);
    assert(data2 == 2);

    data1 = item2->data;
    data2 = item2->prev->data;
    printf("last two chains are %d and %d", data2, data1);
    assert(data1 == 100);
    assert(data2 == 99);

    list_free(list->tail);
    free(list);

    return 0;
}
