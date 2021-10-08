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
    size_t base = a;
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    for (size_t i = 1; i < n; i++)
    {
        a *= base;
    }
    return a;
}

struct value **my_realloc(struct value **data, size_t cap, size_t old)
{
    struct value **new = malloc(sizeof(struct value *) * cap);
    if (!new)
        return NULL;
    for (size_t i = 0; i < cap; i++)
    {
        new[i] = NULL;
    }
    for (size_t j = 0; j < old; j++)
    {
        new[j] = data[j];
    }
    free(data);
    return new;
}

void add(struct bst *tree, int value)
{
    if (!(tree->data))
        return;

    size_t i = 0;

    while (tree->data[i])
    {
        if (value > tree->data[i]->val)
        {
            i = i * 2 + 2;
            if (i > tree->capacity - 1)
            {
                tree->data = my_realloc(tree->data, i + 1, tree->capacity);
                tree->capacity = i + 1;
            }
        }
        else
        {
            i = i * 2 + 1;
            if (i > tree->capacity - 1)
            {
                tree->data = my_realloc(tree->data, i + 1, tree->capacity);
                tree->capacity = i + 1;
            }
        }
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
