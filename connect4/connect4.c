#include <stddef.h>

struct pt
{
    size_t x;
    size_t y;
    int x_d;
    int y_d;
};

struct stat
{
    size_t lines;
    size_t columns;
    int k;
    char *t[];
};

struct w_pair
{
    int win1;
    int win2;
    int *wins;
};


void ch_dir( int x, int y, struct pt *c)
{
    c->x_d = x;
    c->y_d = y;
}

int check_dir(struct stat *g, struct pt c, struct w_pair p, char *game[])
{
    if (p.win1 == 4 || p.win2 == 4)
    {
        *p.wins += 1;
        if (p.win1 > p.win2)
        {
            if (g->k == 1)
                return 0;
            g->k = 1;
            return 1;
        }
        else
        {
            if (g->k ==2)
                return 0;
            g->k = 2;
            return 1;
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

int connect4(char *game[], size_t columns, size_t lines)
{
    int meme = 0;
    struct stat s;
    s.lines = lines;
    s.columns = columns;
    s.k = 0;

    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 0;

    struct w_pair p;
    p.win1 = 0;
    p.win2 = 0;
    p.wins = &meme;

    for (size_t i = 0; i < s.lines; i++)
    {
        c.x = i;
        c.y = 0;
        ch_dir( 1, 0, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( 1, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( 0, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( -1, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
    }

    for (size_t i = 0; i < s.lines && i < s.columns; i++)
    {
        c.x = i;
        c.y = i;
        ch_dir( 1, 0, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( 1, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( 0, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
        ch_dir( -1, 1, &c);
        if (check_dir(&s, c, p, game) == 0)
            return 0;
    }
    return s.k;
}
