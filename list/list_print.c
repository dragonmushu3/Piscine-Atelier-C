#include <stdio.h>

void list_print(struct list *l)
{
    if (!list)
    {
        printf('\n');
        return;
    }
    if (!l->next)
        printf("%d", l->data);
    else
        printf("%d ", l->data);
    list_print(l->next);
}
