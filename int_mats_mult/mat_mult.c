#include <stddef.h>
#include "mat_mult.h"

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    if (!matrices_size)
        return;
    size_t b = matrices_size[1];
    size_t a = matrices_size[0];
    size_t c = matrices_size[2];
    int res = 0;
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            for (size_t k = 0; k < b; k++)
            {
                res += mat1[i][k] * mat2[k][j];
            }
            out[i][j] = res;
            res = 0;
        }
    }
}
