#include "int_vector_insert_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        int temp = vec.data[i];
        int j = i - 1;
        while (j >= 0)
        {
            size_t k = j;
            if (vec.data[k] > temp)
                vec = swap(vec, k, k + 1);
            j--;
        }
    }
    return vec;
}
