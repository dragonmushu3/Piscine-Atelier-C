#include <stddef.h>

void str_revert(char str[])
{
    size_t i = 0;
    while (*(str + i) != '\0')
        i++;
    char temp = 'a';
    for (size_t j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
