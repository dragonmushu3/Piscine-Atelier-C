#ifndef CONNECT4_H
#define CONNECT4_H

#include <stddef.h>

void ch_dir( int x, int y, struct pt *c);
int check_dir(struct stat *g, struct pt c, struct w_pair p, char *game[]);
int connect4(char *game[], size_t columns, size_t lines);

#endif /* !CONNECT4_H */
