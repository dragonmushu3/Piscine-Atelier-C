#include "bst.h"

#include <stdlib.h>
#include <stdio.h>

void pretty_print(struct bst_node *tree, size_t spaces)
{
    if (!tree)
        return;
    pretty_print(tree->left, spaces + 2);
    for (size_t i = 0; i < spaces; i++)
        putchar(32);
    putchar(tree->data);
    pretty_print(tree->right, spaces + 2);
}

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
         tree->right = add_node(tree->right, value);
    else
         tree->left = add_node(tree->left, value);

    return tree;
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

int maximum(struct bst_node *tree, int max)
{
    if (!tree)
        return max;
    max = tree->data;
    return maximum(tree->right, max);
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value > tree->data)
        tree->right = delete_node(tree->right, value);
    else if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else
    {
        if (tree->right && tree->left)
        {
            tree->data = maximum(tree->left, 0);
            tree->left = delete_node(tree->left, tree->data);
            return tree;
        }
        if (!tree->right)
        {
            free(tree);
            return tree->left;
        }
        else
        {
            free(tree);
            return tree->right;
        }
    }
    return tree;
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;
    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}
