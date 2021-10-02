#include <stdlib.h>
#include <stdio.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    /*link new item to head*/
    item->data = element;
    item->next = NULL;
    item->prev = list->head;
    if (!list->tail)
    {
        list->tail = item;
        list->size += 1;
        return 1;
    }

    /*link old head to new item*/
    list->head->next = item;

    /*replace head with new item*/
    list->head = item;
    list->size += 1;
    return 1;
}

void rec_print_itemht(const struct dlist_item *item)
{
    if (item == NULL)
        return;
    else
    {
        printf("%d",item->data);
        rec_print_itemht(item->prev);
    }
}

void dlist_print(const struct dlist *list)
{
    rec_print_itemht(list->head);
}

int dlist_push_back(struct dlist *list, int element)
{
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    if (!item)
        return 0;
    /*link new item to tail*/
    item->data = element;
    item->next = list->tail;
    item->prev = NULL;
    if (!list->head)
    {
        list->head = item;
        list->size += 1;
        return 1;
    }

    /*link old tail to new item*/
    list->tail->prev = item;

    /*replace tail with new item*/
    list->tail = item;
    list->size += 1;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
