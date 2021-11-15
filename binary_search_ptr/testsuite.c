#include <criterion/criterion.h>
#include "bsearch.h"

Test (suite1, test1)
{
    int arr[] = {4, 5, 7, 8, 9, 12};
    int *exp = arr + 4;
    int *res = binary_search(arr, arr + 6, 10);
    cr_assert_eq(res, exp);
}

Test (suite1, test2)
{
    int arr[] = {1, 2, 7, 8, 9, 12, 57, 60, 255, 458, 2900, 3124, 4560, 10541};
    int *exp = arr + 10;
    int *res = binary_search(arr, arr + 14, 3000);
    cr_assert_eq(res, exp);
}

Test (suite1, test3)
{
    int arr[] = {4};
    int *exp = arr + 1;
    int *res = binary_search(arr, arr + 1, 10);
    cr_assert_eq(res, exp);
}

Test (suite1, test4)
{
    int arr[] = {5};
    int *exp = arr;
    int *res = binary_search(arr, arr + 1, 5);
    cr_assert_eq(res, exp);
}

Test (suite1, test5)
{
    int arr[] = {3, 7};
    int *exp = arr;
    int *res = binary_search(arr, arr + 2, 6);
    cr_assert_eq(res, exp);
}

Test (suite1, test6)
{
    int arr[] = {3, 7};
    int *exp = arr;
    int *res = binary_search(arr, arr + 2, 3);
    cr_assert_eq(res, exp);
}

Test (suite1, test7)
{
    int arr[] = {3, 7};
    int *exp = arr + 1;
    int *res = binary_search(arr, arr + 2, 7);
    cr_assert_eq(res, exp);
}

Test (suite1, test8)
{
    int arr[] = {3, 7};
    int *exp = arr + 2;
    int *res = binary_search(arr, arr + 2, 10);
    cr_assert_eq(res, exp);
}
