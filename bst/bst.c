#include <stdlib.h>

#include "bst.h"

struct bst_node *create_node(int value)
{
    struct bst_node *new = malloc(sizeof(struct bst_node) * 1);
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);
    if (value > tree->data)
    {
        return add_node(tree->right, value);
    }
    else
    {
        return add_node(tree->left, value);
    }
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;
    if (value > tree->data)
    {
        return find(tree->right, value);
    }
    else if (value < tree->data)
    {
        return find(tree->left, value);
    }
    else
    {
        return tree;
    }
}

struct bst_node *maximum(struct bst_node *tree, struct bst_node *max)
{
    if (!tree)
        return max;
    max = tree;
    return maximum(tree->right, max);
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    value++;
    return tree;
    /*FIX ME*/
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;
    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}
