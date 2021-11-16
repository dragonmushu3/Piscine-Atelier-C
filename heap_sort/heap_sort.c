#include <stddef.h>

void actual_heapify(int *array, size_t index, size_t size)
{
    size_t left_child_ind = 2 * index + 1;
    size_t right_child_ind = 2 * index + 2;
    size_t max_ind = 0;

    if (left_child_ind < size && array[left_child_ind] > array[index])
    {
        max_ind = left_child_ind;
    }
    else
        max_ind = index;

    if (right_child_ind < size && array[right_child_ind] > array[max_ind])
    {
        max_ind = right_child_ind;
    }

    if (max_ind != index)
    {
        size_t temp = array[index];
        array[index] = array[max_ind];
        array[max_ind] = temp;
        actual_heapify(array, max_ind, size);
    }
}
/*this is actually build heap*/
void heapify(int *array, size_t size)
{
    if (size == 1 || size == 0)
    {
        return;
    }
    for (size_t i = size / 2 - 1; i != 0; i--)
    {
        actual_heapify(array, i, size);
    }
    actual_heapify(array, 0, size);
}

void heap_sort(int *array, size_t size)
{
    if (size == 1 || size == 0)
        return;

    heapify(array, size);
    for (size_t i = size - 1; i != 0; i--)
    {
        size_t temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        actual_heapify(array, 0, i);
    }
}
