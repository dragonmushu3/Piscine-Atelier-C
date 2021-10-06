#include <criterion/criterion.h>

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
}

Test(suite_2, push_front_2)
{
    struct dlist *list = dlist_init();
    for (size_t i = 1; i <= 100; i++)
        dlist_push_front(list, i);
    struct dlist_item *item1 = list->tail;
    struct dlist_item *item2 = list->head;

    cr_assert_eq(item1->data, 1, "got %d instead of %d",item1->data, 1);
    cr_assert_eq(item1->next->data, 2, "got %d instead of %d",item1->next->data, 2);
    int data1 = item2->data;
    int data2 = item2->prev->data;
    cr_assert_eq(data1, 100, "got %d instead of %d", data1, 100);
    cr_assert_eq(data2, 99, "got %d instead of %d", data2, 99);
}

Test(suite_2, push_back_1)
{
    struct dlist *list = dlist_init();
    for (size_t i = 1; i <= 100; i++)
        dlist_push_back(list, i);
    struct dlist_item *item1 = list->tail;
    struct dlist_item *item2 = list->head;

    cr_assert_eq(item1->data, 1, "got %d instead of %d",item1->data, 1);
    cr_assert_eq(item1->next->data, 2, "got %d instead of %d",item1->next->data, 2);
    int data1 = item2->data;
    int data2 = item2->prev->data;
    cr_assert_eq(data1, 100, "got %d instead of %d", data1, 100);
    cr_assert_eq(data2, 99, "got %d instead of %d", data2, 99);
}

