#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

struct heap
{
    size_t size;
    size_t capacity;
    int *array;
};

#endif
