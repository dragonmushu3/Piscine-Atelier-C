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

void print_heap(const struct heap *heap)
{
    for (size_t arr_index = 0; arr_index < heap->size; arr_index++)
    {
        /*count element digits*/

        int temp = heap->array[arr_index];
        if (temp < 0)
            temp = -temp;
        int no_digits = 0;

        while (!(temp == 0))
        {
            temp = temp / 10;
            no_digits++;
        }
        /*print each digit*/
        int to_print = heap->array[arr_index];
        if (to_print < 0)
            to_print = -to_print;

        for (int i = 1; i <= no_digits; i++)
        {
            putchar(digit(to_print, i) + 48);
        }

        if (arr_index == heap->size - 1)
            putchar('\n');
        else
            putchar(32);
    }
}
