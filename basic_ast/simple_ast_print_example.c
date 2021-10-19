#include <stdio.h>

#include "ast.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        puts("Missing argument: ast filename");
        return 1;
    }

    struct node *root = ast_build(argv[1]);
    if (!root)
        return 1;

    ast_print(root);
    return 0;
}
