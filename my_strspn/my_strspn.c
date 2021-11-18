#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t res = 0;
    while (*s != '\0')
    {
        int found_one = 0;
        size_t i = 0;
        while (accept[i] != '\0')
        {
            if (*s == accept[i])
            {
                res++;
                found_one = 1;
                break;
            }
            i++;
        }
        if (!found_one)
            return res;
        s++;
    }
    return res;
}

int main(void)
{
    return 0;
}
