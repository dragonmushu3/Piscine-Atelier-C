#include <stdlib.h>
#include "heap.h"

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity + 1);
        heap->capacity += 1;
    }

    heap->array[heap->size] = val;

    size_t parent_index = (heap->size - 1) / 2;
    size_t child_index = heap->size;

    while (heap->array[child_index] > heap->array[parent_index])
    {
        int temp = heap->array[parent_index];
        heap->array[parent_index] = heap->array[child_index];
        heap->array[child_index] = temp;

        child_index = parent_index;
        if (child_index == 0)
            break;
        parent_index = (parent_index - 1) / 2;
    }
    heap->size += 1;
}
