#ifndef UTILITIES_H
#define UTILITIES_H

#include "hash_map.h"

size_t my_strlen(char *s);
int eq_strings(const char *str1, const char *str2);
struct pair_list *find_list(struct pair_list *list, const char *key);
struct pair_list *find_precedent(struct pair_list *list, char *key);
char *find_list_char(struct pair_list *list, char *key);

#endif /* !UTILITIES_H */