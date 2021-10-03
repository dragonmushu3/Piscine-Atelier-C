#ifndef STRUCT_H
#define STRUCT_H

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
};

#endif
