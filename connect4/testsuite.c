#include <criterion/criterion.h>

#include "connect4.h"

Test(suite1, check_dir_2win_diag)
{
    char *game3[10] =
    {
        "X--------",
        "-X-------",
        "--X------",
        "---X-----",
        "---------",
        "-----O---",
        "------O--",
        "-------O-",
        "--------O",
        "---------"
    };

    int res = connect4(game3, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0", res);
}


Test(suite2, real)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "---------",
        "------O--",
        "------O--",
        "-----OO--",
        "-XX---O--",
        "--X----O-",
        "---XOX--X",
        "-XOOOXX--"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 2, "got %d instead of 2",res);
}

Test(suite2, real2)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "---------",
        "------O--",
        "------O--",
        "-----OO--",
        "-XX---X--",
        "--X----O-",
        "---XOX--X",
        "-XOOOXXXX"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 1, "got %d instead of 1",res);
}

Test(suite2, real3)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "----X-O--",
        "---X--O--",
        "--XX--O--",
        "-X-X-OO--",
        "-XXX--X--",
        "--X----O-",
        "---XOX--X",
        "-XOOOXXXX"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}

Test(suite2, x_column_win)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "----X----",
        "----X----",
        "----X----",
        "----X----",
        "---------",
        "---------",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 1, "got %d instead of 1",res);
}

Test(suite2, x_column_win2)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "X--------",
        "X--------",
        "X--------",
        "X--------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 1, "got %d instead of 1",res);
}

Test(suite2, x_column_win3)
{
    char *game[10] =
    {
        "--------X",
        "--------X",
        "--------X",
        "--------X",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 1, "got %d instead of 1",res);
}

Test(suite2, x_column_double_win_diff_columns)
{
    char *game[10] =
    {
        "------X--",
        "------X--",
        "------X--",
        "------X--",
        "---X-----",
        "---X-----",
        "---X-----",
        "---X-----",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}


Test(suite2, x_column_double_win_same_column)
{
    char *game[10] =
    {
        "---------",
        "-------X-",
        "-------X-",
        "-------X-",
        "-------X-",
        "-------X-",
        "-------X-",
        "-------X-",
        "-------X-",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}

Test(suite2, x_column_double_win_same_column_space)
{
    char *game[10] =
    {
        "--X------",
        "--X------",
        "--X------",
        "--X------",
        "---------",
        "--X------",
        "--X------",
        "--X------",
        "--X------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}

Test(suite2, o_column_win)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "----O----",
        "----O----",
        "----O----",
        "----O----",
        "---------",
        "---------",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 2, "got %d instead of 2",res);
}

Test(suite2, o_column_win2)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "O--------",
        "O--------",
        "O--------",
        "O--------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 2, "got %d instead of 2",res);
}

Test(suite2, o_column_win3)
{
    char *game[10] =
    {
        "--------O",
        "--------O",
        "--------O",
        "--------O",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 2, "got %d instead of 2",res);
}

Test(suite2, o_column_double_win_diff_columns)
{
    char *game[10] =
    {
        "------O--",
        "------O--",
        "------O--",
        "------O--",
        "---O-----",
        "---O-----",
        "---O-----",
        "---O-----",
        "---------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}


Test(suite2, o_column_double_win_same_column)
{
    char *game[10] =
    {
        "---------",
        "-------O-",
        "-------O-",
        "-------O-",
        "-------O-",
        "-------O-",
        "-------O-",
        "-------O-",
        "-------O-",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}

Test(suite2, o_column_double_win_same_column_space)
{
    char *game[10] =
    {
        "--O------",
        "--O------",
        "--O------",
        "--O------",
        "---------",
        "--O------",
        "--O------",
        "--O------",
        "--O------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 0, "got %d instead of 0",res);
}

Test(suite2, x_column_5X)
{
    char *game[10] =
    {
        "---------",
        "---------",
        "---------",
        "---------",
        "---------",
        "--X------",
        "--X------",
        "--X------",
        "--X------",
        "---------"
    };

    int res = connect4(game, 9, 10);
    cr_assert_eq(res, 1, "got %d instead of 1",res);
}
