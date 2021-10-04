#include <criterion/criterion.h>

#include "bst.h"

Test(suite1, create)
{
    struct bst_node *res = create_node(5);

    cr_assert_eq(res->data, 5);
    cr_assert(!(res->left));
    cr_assert(!(res->right));
}

Test(suite1, insertion)
{
    struct bst_node *node1 = create_node(5);
    struct bst_node *node2 = create_node(7);

    struct bst_node *exp = node1;
    exp->right = node2;

    struct bst_node *res = add_node(node1, 7);
    cr_assert_eq(res->data, 5);
    cr_assert(!(res->left));
    cr_assert_eq(res->right->data, 7);
}
