#include <assert.h>
#include <stdio.h>

#include "connect4.h"

int main(void)
{
    char *game[10] = { "---------", "---------", "---------", "------O--",
                       "------O--", "-----OO--", "-XX---O--", "--X----O-",
                       "---XOX--X", "-XOOOXX--" };

    int res = connect4(game, 9, 10);
    printf("got %d instead of 2", res);
    assert(res == 2);
}
