#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"
#include "dlist_th1.h"
#include "dlist_th2.h"
#include "dlist_th3.h"

void free_dlist(struct dlist *list)
{
    struct dlist_item *item = list->tail;
    while (item)
    {
        struct dlist_item *temp = item->next;
        free(item);
        item = temp;
    }
    free(list);
}

int main(void)
{
    struct dlist *list = dlist_init();
    dlist_push_back(list, 5);
    dlist_push_back(list, 4);
    dlist_push_back(list, 8);

    dlist_insert_at(list, 23, 0);

    int res = dlist_remove_at(list, 1);

    printf("removed %d\n", res);

    dlist_print(list);

    free_dlist(list);


    return 0;
}
