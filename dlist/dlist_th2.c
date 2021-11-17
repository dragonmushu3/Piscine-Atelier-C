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
    if (index > list->size || (!list))
        return -1;
    if (index == list->size)
        return dlist_push_front(list, element);
    else
    {
        if (index > 0)
        {
            struct dlist_item *ptr_index = rec_get_item(list->tail, index);
            struct dlist_item *ptr_size = rec_get_item(list->tail, index - 1);
            struct dlist_item *new = malloc(sizeof(struct dlist_item));
            if (!new)
                return -1;
            new->data = element;
            new->next = ptr_size;
            new->prev = ptr_index;
            list->size += 1;
        }
        else if (index == 0)
        {
            return dlist_push_back(list, element);
        }
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= list->size || (!list))
        return -1;
    int res = -1;
    if (index > 0 && index < list->size - 1)
    {
        struct dlist_item *ptr_back = rec_get_item(list->tail, index - 1);
        struct dlist_item *ptr_front = rec_get_item(list->tail, index + 1);
        ptr_back->next = ptr_front;
        ptr_front->prev = ptr_back;
        struct dlist_item *to_del = rec_get_item(list->tail, index);
        res = to_del->data;
        free(to_del);
    }
    else if (index == 0)
    {
        struct dlist_item *ptr_front = rec_get_item(list->tail, index + 1);
        ptr_front->prev = NULL;
        struct dlist_item *to_del = rec_get_item(list->tail, index);
        res = to_del->data;
        free(to_del);
    }
    else if (index == list->size - 1)
    {
        struct dlist_item *ptr_back = rec_get_item(list->tail, index - 1);
        ptr_back->next = NULL;
        struct dlist_item *to_del = rec_get_item(list->tail, index);
        res = to_del->data;
        free(to_del);
    }
    return res;
}
