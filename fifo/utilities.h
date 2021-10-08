#ifndef UTILITIES_H
#define UTILITIES_H

#include <stddef.h>

size_t rec_count_listht(struct list *item);
void rec_remove(struct list *item);
void rec_print(struct list *item);

#endif /* !UTILITIES_H */
