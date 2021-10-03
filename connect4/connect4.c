#include <stddef.h>

#include "struct.h"

void ch_dir( int x, int y, struct pt *c)
{
    c->x_d = x;
    c->y_d = y;
}

int check_dir(struct stat *g, struct pt c, struct w_pair p, char *game[])
{
    if (p.win1 == 4 || p.win2 == 4)
    {
        if (p.win1 > p.win2)
        {
            if (g->k == 1)
                return 0;
            g->k = 1;
            p.win1 = 0;
        }
        else
        {
            if (g->k == 2)
                return 0;
            g->k = 2;
            p.win2 = 0;
        }
    }
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
        return check_dir(g, c, p, game);
    }
    else
        return 0;
}

int traverse_first_column(struct stat *s, char * game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 0;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    for (size_t i = 0; i < s->lines; i++)
    {
        c.x = i;
        c.y = 0;
        ch_dir(1, 0, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(1, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(0, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(-1, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
    }
    return 1;
}

int traverse_first_diag(struct stat *s, char *game[])
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 0;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;

    for (size_t i = 0; i < s->lines && i < s->columns; i++)
    {
        c.x = i;
        c.y = i;
        ch_dir(1, 0, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(1, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(0, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
        ch_dir(-1, 1, &c);
        if (check_dir(s, c, p, game) == 0)
            return 0;
    }
    return 1;
}

int connect4(char *game[], size_t columns, size_t lines)
{
    struct stat s;
    s.lines = lines;
    s.columns = columns;
    s.k = 0;

    if (traverse_first_column(&s, game) == 0)
        return 0;

    if (traverse_first_diag(&s, game) == 0)
        return 0;

    return s.k;
}
