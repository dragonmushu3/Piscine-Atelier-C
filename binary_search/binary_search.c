
#include <stddef.h>



int binary_search(const int vec[], size_t size, int elt)
{
    size_t min = 0;
    size_t max = size - 1;
    size_t m = (max - min) / 2;
    while (!(max <= min))
    {
        if (elt == vec[m])
            return m;
        if (elt > vec[m+min])
        {
            min = m+1;
        }
        else
        {
            max = m-1;
        }
        m = (max + min) / 2;
    }
    return -1;
}


