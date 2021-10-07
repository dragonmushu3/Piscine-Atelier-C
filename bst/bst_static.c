#include "bst_static.h"

#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *tree = malloc(sizeof(struct bst) * 1);
    tree->capacity = capacity;
    tree->size = 0;
    tree->data = malloc(sizeof(struct value *) * capacity);
    if (!tree->data)
        return NULL;
    for (size_t i = 0; i < capacity; i++)
    {
        tree->data[i] = NULL;
    }

    return tree;
}

size_t my_pow(size_t a, size_t n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    for (size_t i = 1; i < n; i++)
    {
        a *= a;
    }
    return a;
}

void add(struct bst *tree, int value)
{
    size_t needed_capacity = 0;
    for (size_t j = 1; j <= tree->size; j++)
        needed_capacity += my_pow(2, j - 1);

    if (tree->capacity < needed_capacity)
    {
        tree->data = realloc(tree->data, needed_capacity);
        for (size_t k = tree->capacity; k < needed_capacity; k++)
            tree->data[k] = NULL;
        tree->capacity = needed_capacity;
    }
    if (!(tree->data))
        return;

    size_t i = 0;
    while (tree->data[i])
    {
        if (value > tree->data[i]->val)
            i = i * 2 + 2;
        else
            i = i * 2 + 1;
    }
    if (!tree->data[i])
    {
        struct value *new = malloc(sizeof(struct value));
        new->val = value;
        tree->data[i] = new;
        tree->size++;
    }
    else
        return;
}

int search(struct bst *tree, int value)
{
    for (size_t i = 0; i < tree->capacity; i++)
        if (tree->data[i])
        {
            if (tree->data[i]->val == value)
                return i;
        }
    return -1;
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;
    for (size_t i = 0; i < tree->capacity; i++)
    {
        free(tree->data[i]);
    }
    free(tree->data);
    free(tree);
}
