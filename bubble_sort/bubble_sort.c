#include <stddef.h>

void bubble_sort(int array[], size_t size)
{
    int temp = 0;
    for (size_t j = 0; j < size; j++)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
