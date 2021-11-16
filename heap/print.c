#include <stdio.h>

#include "heap.h"

unsigned int digit(int l, int k)
{
    if ((l <= 0) || (k <= 0))
        return 0;
    unsigned int quotient = 1;
    for (int i = 1; i <= k; i++)
        quotient *= 10;
    if (k >= 2)
    {
        unsigned int number1 = l % quotient;
        unsigned int number2 = l % (quotient / 10);
        return (number1 - number2) / (quotient / 10);
    }
    return l % quotient;
}

int count_digits(int n)
{
    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;

    int no_digits = 0;
    while (!(n == 0))
    {
        n = n / 10;
        no_digits++;
    }
    return no_digits;
}

void print_heap_ind(const struct heap *heap, size_t index, size_t max_index)
{
    /*count element digits*/
    int no_digits = count_digits(heap->array[index]);

    /*print each digit*/
    int to_print = heap->array[index];
    if (to_print < 0)
    {
        to_print = -to_print;
        putchar('-');
    }

    for (int i = no_digits; i >= 1; i--)
    {
        putchar(digit(to_print, i) + 48);
    }

    if (index == max_index)
        putchar('\n');
    else
        putchar(32);

    if (2 * index + 1 < heap->size)
        print_heap_ind(heap, 2 * index + 1, max_index);

    if (2 * index + 2 < heap->size)
        print_heap_ind(heap, 2 * index + 2, max_index);
}

void print_heap(const struct heap *heap)
{
    size_t max_index = 0;
    while (2 * max_index + 2 < heap->size)
        max_index = 2 * max_index + 2;
    print_heap_ind(heap, 0, max_index);
}
