
#include <stddef.h>

int binary_search(const int vec[], size_t size, int elt)
{
    if (size == 0)
        return -1;

    size_t min = 0;
    size_t max = size - 1;
    while (!(max <= min))
    {
        size_t m = (max - min) / 2;
        if (elt == vec[m])
            return m;
        else if (elt > vec[m])
        {
            binary_search(m + 1, size - m, elt);
        }
        else
        {
            binary_search(vec, size - m, elt);
        }
    }
    return -1;
}
