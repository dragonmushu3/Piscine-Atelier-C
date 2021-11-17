#include <criterion/criterion.h>
#include <stdlib.h>

#include "dlist.h"

Test(suite_1, push_front_1)
{
    struct dlist *list = dlist_init();
    struct dlist_item *item1 = list->head;
    struct dlist_item *item2 = list->tail;
    size_t size = list->size;

    cr_assert_eq(item1, NULL);
    cr_assert_eq(item2, NULL);
    cr_assert_eq(size, 0);

    struct dlist_item *item = list->tail;
    while (item)
    {
        struct dlist_item *temp = item->next;
        free(item);
        item = temp;
    }
    free(list);
}

Test(suite_2, push_front_2)
{
    struct dlist *list = dlist_init();
    for (size_t i = 1; i <= 100; i++)
        dlist_push_front(list, i);
    struct dlist_item *item1 = list->tail;
    struct dlist_item *item2 = list->head;

    cr_assert_eq(item1->data, 1, "got %d instead of %d", item1->data, 1);
    cr_assert_eq(item1->next->data, 2, "got %d instead of %d",
                 item1->next->data, 2);
    int data1 = item2->data;
    int data2 = item2->prev->data;
    cr_assert_eq(data1, 100, "got %d instead of %d", data1, 100);
    cr_assert_eq(data2, 99, "got %d instead of %d", data2, 99);

    struct dlist_item *item = list->tail;
    while (item)
    {
        struct dlist_item *temp = item->next;
        free(item);
        item = temp;
    }
    free(list);
}

Test(suite_3, get)
{
    struct dlist *list = dlist_init();
    dlist_push_back(list, 5);
    dlist_push_back(list, 4);
    dlist_push_back(list, 8);

    cr_assert_eq(5, dlist_get(list, 0));
    cr_assert_eq(4, dlist_get(list, 1));
    cr_assert_eq(8, dlist_get(list, 2));
    cr_assert_eq(-1, dlist_get(list, 3));
    cr_assert_eq(-1, dlist_get(NULL, 0));

    struct dlist_item *item = list->tail;
    while (item)
    {
        struct dlist_item *temp = item->next;
        free(item);
        item = temp;
    }
    free(list);
}

Test(suite_3, insert_at)
{
    struct dlist *list = dlist_init();
    dlist_push_back(list, 5);
    dlist_push_back(list, 4);
    dlist_push_back(list, 8);

    dlist_insert_at(list, 23, 0);
    int element_at_index = dlist_get(list, 0);
    cr_assert_eq(23, element_at_index, "got %d instead of %d", element_at_index, 23);

    dlist_insert_at(list, 25, list->size);
    element_at_index = dlist_get(list, list->size - 1);
    cr_assert_eq(25, element_at_index, "got %d instead of %d", element_at_index, 25);

    dlist_insert_at(list, 6, 1);
    element_at_index = dlist_get(list, 1);
    cr_assert_eq(6, element_at_index, "got %d instead of %d", element_at_index, 6);

    dlist_insert_at(list, 11, 5);
    cr_assert_eq(11, dlist_get(list, 5));

    int res_1 = dlist_insert_at(NULL, 20, 5);
    cr_assert_eq(-1, res_1);

    int res_2 = dlist_insert_at(list, 20, list->size + 1);
    cr_assert_eq(-1, res_2);

    struct dlist_item *item = list->tail;
    while (item)
    {
        struct dlist_item *temp = item->next;
        free(item);
        item = temp;
    }
    free(list);
}
