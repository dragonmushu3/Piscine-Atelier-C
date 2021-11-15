#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while( *s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

int my_atoi(const char *str)
{
    size_t digits = my_strlen(str);
    int res = 0;

    for (int i = digits - 1; i >= 0; i--)
    {
        if (digits - 1 - i == 0)
            res += str[i] - 48;
        else
        {
            size_t ten_pow = 1;
            for (size_t j = 0; j < digits - 1 - i; j ++)
            {
                ten_pow *= 10;
            }
            res += (str[i] - 48) * ten_pow;
        }
    }
    return res;
}
