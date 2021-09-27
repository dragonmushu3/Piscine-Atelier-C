#include <stddef.h>




void bubble_sort(int array[], size_t size)
{
    int temp = 0;
    for(size_t j = 1; j < size; j++)
    {
        for(size_t i = 1; i < size; i++)
        {
            if (i == 2)
                size--;
            if (array[i] < array[i-1])
            {
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
            }
        }
    }
}


