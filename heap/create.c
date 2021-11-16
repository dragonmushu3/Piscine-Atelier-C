#include <stdlib.h>
#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(struct heap) * 1);
    heap->capacity = 8;
    heap->size = 0;
    heap->array = malloc(sizeof(int) * heap->capacity);
    if (!heap->array)
        return NULL;
    for (size_t i = 0; i < heap->capacity; i++)
    {
        heap->array[i] = 0;
    }
    return heap;
}
