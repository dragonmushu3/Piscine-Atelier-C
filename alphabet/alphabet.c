#include <stdio.h>

int main(void)
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        putchar(i);
        if (i != 'z')
            putchar(32);
    }
    putchar('\n');
    return 0;
}
