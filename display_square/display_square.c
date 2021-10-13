#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;
    if (width % 2 == 0)
        width++;
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }
    int rows = (width + 1) / 2;
    for (int i = 0; i < width; i++)
        putchar('*');
    putchar('\n');
    for (int i = 0; i < rows - 2; i++)
    {
        putchar('*');
        for (int j = 0; j < width - 2; j++)
        {
            putchar(32);
        }
        putchar('*');
        putchar('\n');
    }
    for (int i = 0; i < width; i++)
        putchar('*');
    putchar('\n');
}
