#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum node_type
{
    ADD = 0,
    MULTI,
    NUMBER
};

struct node
{
    enum node_type type;
    int value;
    struct node *left_child;
    struct node *right_child;
};

int ast_evaluate(const struct node *root);

struct node *ast_build(const char *filename);

void ast_print(const struct node *root);

void ast_delete(struct node *root);

#endif /* !AST_H */
