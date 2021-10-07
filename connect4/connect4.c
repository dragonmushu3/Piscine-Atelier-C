#include "connect4.h"

void ch_dir(int x, int y, struct pt *c)
{
    c->x_d = x;
    c->y_d = y;
}

void handle_w(struct stat *g, struct w_pair p)
{
    if (p.win1 >= 4 || p.win2 >= 4)
    {
        if (p.win1 > p.win2)
        {
            if (g->k == 0)
                g->k = 1;
            else
                g->fail = 1;
        }
        else
        {
            if (g->k == 0)
                g->k = 2;
            else
                g->fail = 1;
        }
    }
}

void check_dir(struct stat *g, struct pt c, struct w_pair p, char *game[])
{
    handle_w(g, p);
    if (c.x < g->lines && c.y < g->columns)
    {
        if (game[c.x][c.y] == 'X')
            p.win1++;
        else
            p.win1 = 0;
        if (game[c.x][c.y] == 'O')
            p.win2++;
        else
            p.win2 = 0;
        c.x += c.x_d;
        c.y += c.y_d;
        check_dir(g, c, p, game);
    }
    else
        return;
}

void traverse_lines(struct stat *s, char *game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 1;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    for (size_t i = 0; i < s->lines; i++)
    {
        c.x = i;
        check_dir(s, c, p, game);
    }
}

void traverse_columns(struct stat *s, char *game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 1;
    c.y_d = 0;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    for (size_t i = 0; i < s->lines; i++)
    {
        c.y = i;
        check_dir(s, c, p, game);
    }
}

void traverse_diags_south_east(struct stat *s, char *game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 1;
    c.y_d = 1;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    size_t passes = s->columns + s->lines - 1;

    for (size_t pass = 1; pass <= passes; pass++)
    {
        if (1 <= pass && pass <= s->columns)
        {
            c.x = 0;
            c.y = pass - 1;
        }
        else
        {
            c.x = pass - s->lines;
            c.y = 0;
        }
        check_dir(s, c, p, game);
    }
}

void traverse_diags_south_west(struct stat *s, char *game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 1;
    c.y_d = -1;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    size_t passes = s->columns + s->lines - 1;

    for (size_t pass = 1; pass <= passes; pass++)
    {
        if (1 <= pass && pass <= s->columns)
        {
            c.x = 0;
            c.y = pass - 1;
        }
        else
        {
            c.x = pass - s->lines;
            c.y = s->columns - 1;
        }
        check_dir(s, c, p, game);
    }
}

int connect4(char *game[], size_t columns, size_t lines)
{
    struct stat s;
    s.lines = lines;
    s.columns = columns;
    s.k = 0;
    s.fail = 0;

    traverse_lines(&s, game);
    traverse_columns(&s, game);
    traverse_diags_south_east(&s, game);
    traverse_diags_south_west(&s, game);
    if (s.fail)
        return 0;
    return s.k;
}
