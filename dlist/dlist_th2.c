#include <stdlib.h>

#include "dlist.h"

size_t rec_search_dlistth(const struct dlist_item *item, int e, size_t index)
{
    if (item == NULL)
        return -1;
    if (e == item->data)
        return index;
    else
    {
        return rec_search_dlistth(item->next, e, ++index);
    }
}

int rec_get(const struct dlist_item *item, size_t index)
{
    if (item == NULL)
        return -1;
    if (index == 0)
        return item->data;
    else
    {
        return rec_get(item->next, --index);
    }
}

struct dlist_item *rec_get_item(struct dlist_item *item, size_t index)
{
    if (item == NULL)
        return NULL;
    if (index == 0)
        return item;
    else
    {
        return rec_get_item(item->next, --index);
    }
}

int dlist_get(struct dlist *list, size_t index)
{
    if (!list || index > (list->size - 1))
        return -1;

    struct dlist_item *ptr = list->head;
    size_t curr_index = 0;
    while (ptr)
    {
        if (curr_index == index)
            return ptr->data;
        curr_index++;
        ptr = ptr->prev;
    }
    return -1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (!list)
        return -1;

    struct dlist_item *ptr = list->head;
    size_t curr_index = 0;
    while (ptr)
    {
        if (ptr->data == element)
            return curr_index;
        curr_index++;
        ptr = ptr->prev;
    }
    return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (!list || index > list->size)
        return -1;

    struct dlist_item *ptr = list->head;
    size_t curr_index = 0;

    if (index == list->size)
        return dlist_push_back(list, element);
    if (index == 0)
    {
        return dlist_push_front(list, element);
    }

    while (ptr)
    {
        if (curr_index == index)
        {
            struct dlist_item *new = malloc(sizeof(struct dlist_item));
            if (!new)
                return -1;
            new->data = element;
            new->prev = ptr;
            new->next = ptr->next;
            if (ptr->next)
            {
                ptr->next->prev = new;
            }
            ptr->next = new;
            list->size++;
            return 1;
        }
        curr_index++;
        ptr = ptr->prev;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (!list || index >= list->size)
        return -1;

    struct dlist_item *ptr = list->head;
    size_t curr_index = 0;

    while (ptr)
    {
        if (curr_index == index)
        {
            struct dlist_item *temp = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = temp;
            int data = ptr->data;
            free(ptr);
            return data;
        }
        curr_index++;
        ptr = ptr->prev;
    }
    return -1;
}
