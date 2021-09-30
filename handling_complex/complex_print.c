#include <stddef.h>
#include <stdio.h>

#include "complex.h"

void print_complex(struct complex a)
{
    printf("complex(%.2f ", a.real);
    if (a.img < 0)
    {
        float new = -a.img;
        printf("- %.2fi)\n", new);
    }
    else
        printf("+ %.2fi)\n", a.img);
}
