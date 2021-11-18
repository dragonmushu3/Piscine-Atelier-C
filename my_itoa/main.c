#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_itoa.h"

int main(void)
{
    char *number = malloc(2);

    printf("%s\n", my_itoa(0, number));
    assert(strlen(number) == 1);
    free(number);

    char *number2 = malloc(3);

    printf("%s\n", my_itoa(25, number2));
    assert(strlen(number2) == 2);
    free(number2);

    char *number3 = malloc(4);

    printf("%s\n", my_itoa(258, number3));
    assert(strlen(number3) == 3);
    free(number3);

    char *number4 = malloc(5);

    printf("%s\n", my_itoa(-462, number4));
    assert(strlen(number4) == 4);
    free(number4);
}
