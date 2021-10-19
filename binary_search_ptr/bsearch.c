#include <stddef.h>

int *binary_search(int *begin, int *end, int elt)
{
    int diff = 0;
    int inter = 0;
    int *m = NULL;
    int *rec(int *begin, int *end, int elt)
    {
        if (end - begin == 0)
            return end;
        else
        {
            inter = end - begin;
            diff = inter / 2;
            m = begin + diff;
            if (elt == *m)
                return m;
            else if (elt > *m)
            {
                begin = m + 1;
                return binary_search(begin, end, elt);
            }
            else
            {
                end = m;
                return binary_search(begin, end, elt);
            }
        }
    }
    return rec(begin, end, elt);
}
