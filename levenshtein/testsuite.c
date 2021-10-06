#include <criterion/criterion.h>

#include "levenshtein.h"

Test(suite_1, test1)
{
    char *s1 = "hello";
    char *s2 = "hel";
    size_t res = levenshtein(s1, s2);
    size_t exp = 2;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

Test(suite_2, test2)
{
    char *s1 = "hel";
    char *s2 = "hello";
    size_t res = levenshtein(s1, s2);
    size_t exp = 2;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

Test(suite_3, test3)
{
    char *s1 = "help";
    char *s2 = "hello";
    size_t res = levenshtein(s1, s2);
    size_t exp = 2;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

Test(suite_4, test4)
{
    char *s1 = "canard";
    char *s2 = "bateau";
    size_t res = levenshtein(s1, s2);
    size_t exp = 5;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

Test(suite_5, test5)
{
    char *s1 = "tagada";
    char *s2 = "#';[]^";
    size_t res = levenshtein(s1, s2);
    size_t exp = 6;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

Test(suite_6, test6)
{
    char *s1 = "  pinneapple  ";
    char *s2 = "pinneapple";
    size_t res = levenshtein(s1, s2);
    size_t exp = 4;
    cr_assert_eq(res, exp,"got %zu instead of %zu", res, exp);
}

