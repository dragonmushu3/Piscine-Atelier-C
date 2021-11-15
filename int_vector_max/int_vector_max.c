#include "int_vector_max.h"

#include <stddef.h>

int int_vector_max(const struct int_vector vec)
{
    int max = vec.data[0];
    for (size_t i = 1; i < vec.size; i++)
    {
        if (vec.data[i] > max)
            max = vec.data[i];
    }
    return max;
}
