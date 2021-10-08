#include "stack.h"

#include <stdlib.h>
#include <stddef.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = calloc(1, sizeof(struct stack));
    if (!new)
        return s;
    new->data = e;
    new->next = s;
    return new;
}

struct stack *stack_pop(struct stack *s)
{
    struct stack *temp = s;
    s = s->next;
    free(temp);
    return s;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
