#ifndef DLIST_TH1_H
#define DLIST_TH1_H

#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void);
int dlist_push_front(struct dlist *list, int element);
void rec_print_itemht(const struct dlist_item *item);
void dlist_print(const struct dlist *list);
int dlist_push_back(struct dlist *list, int element);
size_t dlist_size(const struct dlist *list);

#endif /* !DLIST_TH1_H */