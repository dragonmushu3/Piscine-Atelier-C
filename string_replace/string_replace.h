#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include <stdlib.h>

size_t my_strlen(char *s);
size_t count_char_occ(char *s, char c);
char *string_replace(char c, const char *str, const char *pattern);

#endif /* !STRING_REPLACE_H */