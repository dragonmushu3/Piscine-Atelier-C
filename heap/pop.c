#include <assert.h>
#include <stddef.h>

#include "heap.h"

int pop(struct heap *heap)
{
    assert(heap->size > 0);

    size_t max_i = 0;
    size_t curr_i = 0;
    size_t left_i = 2 * curr_i + 1;
    size_t right_i = 2 * curr_i + 2;
    int res = heap->array[curr_i];

    while (left_i < heap->size)
    {
        if (left_i < heap->size && right_i < heap->size)
        {
            /*case where there are two children */
            if (heap->array[left_i] > heap->array[right_i])
            {
                max_i = left_i;
            }
            else
                max_i = right_i;

            heap->array[curr_i] = heap->array[max_i];
            curr_i = max_i;
            left_i = 2 * curr_i + 1;
            right_i = 2 * curr_i + 2;
        }
        else
        {
            /*case where there is only one left child */
            max_i = left_i;
            heap->array[curr_i] = heap->array[max_i];
            curr_i = max_i;
            left_i = 2 * curr_i + 1;
            right_i = 2 * curr_i + 2;
        }
    }
    heap->array[curr_i] = 0;
    heap->size -= 1;

    return res;
}
