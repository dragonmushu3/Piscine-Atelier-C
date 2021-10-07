#include <stddef.h>

struct stat
{
    size_t lines;
    size_t columns;
    int no_lakes;
};

struct pt
{
    size_t x;
    size_t y;
    int x_d;
    int y_d;
};

void ch_coords_append(int x, int y, struct pt *c)
{
    c->x += x;
    c->y += y;
}

void fill_lake(struct pt c, char **map, struct stat *m)
{
    if (c.x < m->lines && c.y < m->columns)
    {
        if (map[c.x][c.y] == '.')
        {
            map[c.x][c.y] = '#';

            ch_coords_append(-1, 0, &c);
            fill_lake(c, map, m);
            ch_coords_append(2, 0, &c);
            fill_lake(c, map, m);
            ch_coords_append(-1, 1, &c);
            fill_lake(c, map, m);
            ch_coords_append(0, -2, &c);
            fill_lake(c, map, m);
        }
    }
}

void check_dir(struct stat *m, struct pt c, char **map)
{
    if (c.x < m->lines && c.y < m->columns)
    {
        if (map[c.x][c.y] == '.')
        {
            fill_lake(c, map, m);
            m->no_lakes += 1;
        }
        c.x += c.x_d;
        c.y += c.y_d;
        check_dir(m, c, map);
    }
}

void traverse_lines(struct stat *m, char **map)
{
    struct pt c;
    c.x = 0;
    c.y = 0;
    c.x_d = 0;
    c.y_d = 1;

    for (size_t i = 0; i < m->lines; i++)
    {
        c.x = i;
        check_dir(m, c, map);
    }
}

int lakes(char **map, int width, int height)
{
    struct stat m;
    m.no_lakes = 0;
    m.lines = height;
    m.columns = width;

    traverse_lines(&m, map);
    int res = m.no_lakes;
    return res;
}
