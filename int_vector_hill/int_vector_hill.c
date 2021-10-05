#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    size_t i = 1;
    int res = 0;
    if (vec.size == 1 && vec.data[0] >= 0)
        return 0;
    for (size_t i = 0; i < vec.size; i++)
    {
        if (vec.data[i] < 0)
            return -1;
    }
    while (i < vec.size && vec.data[i] >= vec.data[i - 1])
    {
        if (vec.data[i] > vec.data[i - 1])
            res = i;
        i++;
    }
    while (i < vec.size && vec.data[i] <= vec.data[i - 1])
    {
        i++;
    }
    size_t billy = i - 1;
    size_t bob = vec.size - 1;
    if (!(bob == billy))
        return -1;
    return res;
}

int main(void)
{
    return 0;
}
