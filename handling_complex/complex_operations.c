#include <stddef.h>
#include "complex.h"

struct complex neg_complex(struct complex a)
{
    a.real = -a.real;
    a.img = -a.img;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex c =
    {
        .real = 0,
        .img = 0
    };
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    float dev1 = a.real * b.real;
    float dev2 = a.real * b.img;
    float dev3 = a.img * b.real;
    float dev4 = a.img * b.img;
    struct complex banana;
    banana.real = dev1 - dev4;
    banana.img = dev2 + dev3;
    return banana;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float term1 = a.real * b.real + a.img * b.img;
    float term2 = a.img * b.real - a.real * b.img;
    float term3 = b.real * b.real + b.img * b.img;
    struct complex banana;
    banana.real = term1 / term3;
    banana.img = term2 / term3;
    return banana;
}
