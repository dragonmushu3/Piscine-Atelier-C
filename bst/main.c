#include "bst_static.h"

#include <stdio.h>
#include <assert.h>

#include "bst.h"

int main(void)
{
    struct bst_node *root = create_node(5);

    root = add_node(root, 7);
    root = add_node(root, 4);
    root = add_node(root, 17);
    root = add_node(root, 6);
    root = add_node(root, 6);

    root = delete_node(root, 7);

    free_bst(root);

/*    struct bst *tree = init( 10);
**
**    add(tree, 5);
**    add(tree, 2);
**    add(tree, 6);
**    add(tree, 80);
**
**    for (size_t i = 0; i < 10; i++)
**    {
**        if (tree->data[i])
**            printf("%d, ", tree->data[i]->val);
**        else
**            printf("  , ");
**    }
**
**    putchar('\n');
**    bst_free(tree);
*/
    return 0;
}
