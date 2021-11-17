#ifndef DLIST_TH2_H
#define DLIST_TH2_H

#include <stdlib.h>
#include "dlist.h"

size_t rec_search_dlistth(const struct dlist_item *item, int e, size_t index);
int rec_get(const struct dlist_item *item, size_t index);
struct dlist_item *rec_get_item(struct dlist_item *item, size_t index);
int dlist_get(struct dlist *list, size_t index);
int dlist_find(const struct dlist *list, int element);
int dlist_insert_at(struct dlist *list, int element, size_t index);
int dlist_remove_at(struct dlist *list, size_t index);

#endif /* !DLIST_TH2_H */