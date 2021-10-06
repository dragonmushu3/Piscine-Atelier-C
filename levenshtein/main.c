#include "levenshtein.h"
#include <assert.h>

int main(void)
{
    char *s1 = "  pinneapple  ";
    char *s2 = "pinneapple";
    size_t res = levenshtein(s1, s2);
    size_t exp = 4;
    assert(exp == res);
    return 0;
}
