#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

int my_atoi(const char *str)
{
    while (*str == 32)
    {
        str++;
    }

    int is_negative = 0;
    if (*str == '\0')
    {
        return 0;
    }

    if (*str == '-')
    {
        is_negative = 1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    if (*str > 57 || *str < 48)
        return 0;

    size_t digits = my_strlen(str);
    int res = 0;

    for (int i = digits - 1; i >= 0; i--)
    {
        if (str[i] > 57 || str[i] < 48)
            return 0;
        if (digits - 1 - i == 0)
            res += str[i] - 48;
        else
        {
            size_t ten_pow = 1;
            for (size_t j = 0; j < digits - 1 - i; j++)
            {
                ten_pow *= 10;
            }
            res += (str[i] - 48) * ten_pow;
        }
    }

    if (is_negative)
        return -res;
    else
        return res;
}

int main(void)
{
    return my_atoi("  -156");
}
