#include "string_replace.h"
#include <stdio.h>

//void check(char c, const char *s, const char *p)
//{
//    char *res = string_replace(c, s, p);
//    printf("%s\n", res);
//    free(res);
//}

int main(void)
{
    char *res = string_replace('o', "bobo", "canard");
    free(res);
    return 0;
}
