#include <stddef.h>
#include <stdio.h>

void rot_x(char *s, int x)
{
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z'))
        {
            printf("%c\n", s[i] + x);
            s[i] = s[i] + x;
        }
    }
}

int main()
{
    char in[] = "ShhhShEisZZZzZ059%";
    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);
    return 0;
}
