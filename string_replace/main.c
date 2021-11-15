#include "string_replace.h"
#include <stdio.h>

void check(char c, const char *s, const char *p)
{
    char *res = string_replace(c, s, p);
    if (!res)
    {
        printf("Got NULL back!\n");
        return;
    }
    printf("%s\n", res);
    free(res);
}

int main(void)
{
    check('o', "bobo", "banana");
    check('o', "bobo", "i");
    check('o', "bobo", "oo");
    check('o', "bobo", "");
    check('o', "bobo", NULL);
    check('o', NULL, NULL);
    return 0;
}
