#include "bst_static.h"

#include <stdio.h>
#include <assert.h>

#include "bst.h"

int main(void)
{
    struct bst *tree = init( 10);

    for (size_t i = 10; i < 20; i++)
    {
        add(tree, i);
        add(tree, i - 1);
    }

    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i])
            printf("%d, ", tree->data[i]->val);
        else
            printf("  , ");
    }

    putchar('\n');
    bst_free(tree);

    return 0;
}
