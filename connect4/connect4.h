#ifndef CONNECT4_H
#define CONNECT4_H

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
    int fail;
};

struct w_pair
{
    int win1;
    int win2;
};

int connect4(char *game[], size_t columns, size_t lines);

#endif /* !CONNECT4_H */
