#include <stdio.h>
#include <stddef.h>

int binary_search_sub(const int vec[], size_t size, int elt, int *not_found)
{
    if (size == 0)
    {
        *not_found = 1;
        return -1;
    }

    size_t min = 0;
    size_t max = size - 1;
    if (max >= min)
    {
        size_t m = (max - min) / 2;
        if (elt == vec[m])
            return m;
        else if (elt > vec[m])
        {
            return m + 1 + binary_search_sub(vec + m + 1, size - m - 1, elt, not_found);
        }
        else
        {
            return binary_search_sub(vec, size - m - 1, elt, not_found);
        }
    }
    return -1;
}

int binary_search(const int vec[], size_t size, int elt)
{
    int not_found = 0;
    int stoping_index = binary_search_sub(vec, size, elt, &not_found);
    if (not_found)
        return -1;
    else
        return stoping_index;
}
