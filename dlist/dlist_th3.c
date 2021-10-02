#include <stdlib.h>

#include "dlist.h"

void rec_square_itemht(struct dlist_item *item)
{
    if (item == NULL)
        return;
    else
    {
        item->data *= item->data;
        rec_square_itemht(item->prev);
    }
}

/*always set index to zero, ast it counts up*/
void rec_revertth(struct dlist_item *item)
{
    if (item == NULL)
        return;
    else
    {
        struct dlist_item *temp = malloc(sizeof(struct dlist_item));
        if (!temp)
            return;
        temp = item->prev;
        item->prev = item->next;
        item->next = temp;
        free(temp);

        rec_revertth(item->next);
    }
}

void dlist_map_square(struct dlist *list)
{
    rec_square_itemht(list->head);
}

void dlist_reverse(struct dlist *list)
{
    if (!list)
        return;
    rec_revertth(list->tail);
}
