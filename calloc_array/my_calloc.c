#include <stdio.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
        return NULL;
    int *ptr = malloc(sizeof(int) * size);
    if (!ptr)
        return NULL;
    for (size_t i = 0; i < size; i++)
        *(ptr + i) = init;
    return ptr;
}
