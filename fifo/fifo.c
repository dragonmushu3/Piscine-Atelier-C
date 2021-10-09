#include "fifo.h"

#include <stdlib.h>

#include "utilities.h"

struct fifo *fifo_init(void)
{
    struct fifo *new = calloc(1, sizeof(struct fifo));
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (fifo->size == 0)
    {
        struct list *new_list = calloc(1, sizeof(struct list));
        new_list->next = NULL;
        new_list->data = elt;
        fifo->head = new_list;
        fifo->tail = new_list;
        fifo->size++;
        return;
    }

    struct list *new_list = calloc(1, sizeof(struct list));
    new_list->data = elt;
    new_list->next = NULL;
    fifo->head->next = new_list;
    fifo->tail = new_list;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    struct list *to_delete = fifo->head;
    fifo->head = fifo->head->next;
    free(to_delete);
    fifo->size--;
}

void fifo_clear(struct fifo *fifo)
{
    rec_remove(fifo->head);
    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    rec_print(fifo->head);
}
