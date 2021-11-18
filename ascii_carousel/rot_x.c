#include <stddef.h>
#include <stdio.h>

int get_right_letter(char c, int x)
{
    if ('A' <= c && c <= 'Z')
    {
        if (x < 0)
        {
            x = -x;
            int i = 0;
            while (i < x)
            {
                if (c == 'A')
                {
                    c = 'Z';
                    i++;
                    continue;
                }
                c = c - 1;
                i++;
            }
            return c;
        }
        else
        {
            int i = 0;
            while (i < x)
            {
                if (c == 'Z')
                {
                    c = 'A';
                    i++;
                    continue;
                }
                c = c + 1;
                i++;
            }
            return c;
        }
    }
    else if ('a' <= c && c <= 'z')
    {
        if (x < 0)
        {
            x = -x;
            int i = 0;
            while (i < x)
            {
                if (c == 'a')
                {
                    c = 'z';
                    i++;
                    continue;
                }
                c = c - 1;
                i++;
            }
            return c;
        }
        else
        {
            int i = 0;
            while (i < x)
            {
                if (c == 'z')
                {
                    c = 'a';
                    i++;
                    continue;
                }
                c = c + 1;
                i++;
            }
            return c;
        }
    }
    return c;
}

void rot_x(char *s, int x)
{
    if (!s)
        return;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z'))
        {
            s[i] = get_right_letter(s[i], x);
        }
    }
}
