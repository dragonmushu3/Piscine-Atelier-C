#include "utilities.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t rec_count_listth(struct list *item)
{
    if (!item)
        return 0;
    return rec_count_listth(item->next) + 1;
}

void rec_remove(struct list *item)
{
    if (!item)
        return;
    rec_remove(item->next);
    free(item);
}

void rec_print(struct list *item)
{
    if (!item)
        return;
    printf("%d\n", item->data);
    rec_print(item->next);
}
