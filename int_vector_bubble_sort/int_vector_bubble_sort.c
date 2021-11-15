#include "int_vector_bubble_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;
    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    for (size_t j = 0; j < vec.size; j++)
    {
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            if (vec.data[i] > vec.data[i + 1])
            {
                vec = swap(vec, i, i + 1);
            }
        }
    }
    return vec;
}
