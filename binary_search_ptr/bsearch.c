#include <stddef.h>

int *binary_search(int *begin, int *end, int elt)
{
    int size = end - begin;
    if (size <= 0)
    {
        return begin;
    }
    else
    {
        int m = size / 2;
        if (elt == begin[m])
            return begin + m;
        else if (elt > begin[m])
        {
            return binary_search(begin + m + 1, end, elt);
        }
        else
        {
            return binary_search(begin, end - m - 1, elt);
        }
    }
}
