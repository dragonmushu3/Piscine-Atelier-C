#include <criterion/criterion.h>

#include "bst.h"

int check_bst(struct bst_node *tree, int exp_data)
{
    if (!tree)
        return 0;
    return tree->data == exp_data;
}

Test(suite1, create)
{
    struct bst_node *res = create_node(5);

    cr_assert_eq(res->data, 5);
    cr_assert(!(res->left));
    cr_assert(!(res->right));
    free_bst(res);
}

Test(suite1, insertion)
{
    struct bst_node *root = create_node(5);

    root = add_node(root, 7);
    root = add_node(root, 4);
    root = add_node(root, 17);
    root = add_node(root, 6);
    root = add_node(root, 6);

    cr_assert(check_bst(root->left, 4));
    cr_assert(check_bst(root->right, 7));
    cr_assert(check_bst(root->right->right, 17));
    cr_assert(check_bst(root->right->left, 6));
    cr_assert(check_bst(root->right->left->left, 6));

    free_bst(root);
}

Test(suite1, find)
{
    struct bst_node *root = create_node(5);

    root = add_node(root, 7);
    root = add_node(root, 4);
    root = add_node(root, 17);
    root = add_node(root, 6);
    root = add_node(root, 6);

    cr_assert(check_bst(root->left, 4));
    cr_assert(check_bst(root->right, 7));
    cr_assert(check_bst(root->right->right, 17));
    cr_assert(check_bst(root->right->left, 6));
    cr_assert(check_bst(root->right->left->left, 6));

    cr_assert(!find(root, 3));
    cr_assert(check_bst(find(root, 7)->right, 17));
    cr_assert(check_bst(find(root, 7)->left, 6));
    cr_assert(check_bst(find(root, 7)->left->left, 6));

    free_bst(root);
}

Test(suite1, deletion)
{
    struct bst_node *root = create_node(5);

    root = add_node(root, 7);
    root = add_node(root, 4);
    root = add_node(root, 17);
    root = add_node(root, 6);
    root = add_node(root, 6);

    root = delete_node(root, 7);
    cr_assert(check_bst(root->right, 6));
    cr_assert(check_bst(root->right->left, 6));

    free_bst(root);
}

Test(suite1, deletion2)
{
    struct bst_node *root = create_node(5);

    root = add_node(root, 20);
    root = add_node(root, 15);
    root = add_node(root, 25);
    root = add_node(root, 13);
    root = add_node(root, 17);
    root = add_node(root, 21);

    root = delete_node(root, 20);

    free_bst(root);
}
