#include <stdio.h>

void hanoi_aux(unsigned n, char first_rod, char middle_rod, char last_rod)
{
    if (n == 1)
    {
        putchar(first_rod);
        putchar('-');
        putchar('>');
        putchar(last_rod);
        putchar('\n');
        return;
    }
    
    hanoi_aux(n - 1, first_rod, last_rod, middle_rod);
    putchar(first_rod);
    putchar('-');
    putchar('>');
    putchar(last_rod);
    putchar('\n');
    hanoi_aux(n - 1, middle_rod, first_rod, last_rod);
}

void hanoi(unsigned n)
{
    hanoi_aux(n, '1', '2', '3');
}
