#include <criterion/criterion.h>

#include "struct.h"
#include "connect4.h"

Test(suite1, check_dir_1win)
{
    char *game1[4] =
    {
        "XXXX",
        "---O",
        "O-OO",
        "OO-O"
    };

    struct stat s;
    s.lines = 4;
    s.columns = 4;
    s.k = 0;

    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 1;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    check_dir(&s, c, p, game1);
    int res = s.k;
    int exp = 1;

    cr_assert_eq(res, exp, "didn't find a win in game1");
    cr_assert_eq(s.k, 1, "didn't write the right winner for game1!");
}

Test(suite1, check_dir_2win)
{
    char *game2[9] =
    {
        "X---",
        "X---",
        "X---",
        "X---",
        "----",
        "X---",
        "X---",
        "X---",
        "X---",
    };

    struct stat s;
    s.lines = 9;
    s.columns = 4;
    s.k = 0;

    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 1;
    c.y_d = 0;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    int res = check_dir(&s, c, p, game2);
    cr_assert_eq(res, 0, "got %d instead of 0", res);
}

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

    struct stat s;
    s.lines = 10;
    s.columns = 9;
    s.k = 0;

    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 1;
    c.y_d = 1;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    int res = check_dir(&s, c, p, game3);
    cr_assert_eq(res, 0, "got %d instead of 0", res);
}

Test(suite2, diag2)
{
    char *game4[10] =
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
    int res = connect4(game4, 9, 10);
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
