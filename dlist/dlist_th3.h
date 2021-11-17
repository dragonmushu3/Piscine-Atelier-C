#ifndef DLIST_TH3_H
#define DLIST_TH3_H

#include <stdlib.h>

#include "dlist.h"

void rec_square_itemht(struct dlist_item *item);
void rec_revertth(struct dlist_item *item);
void dlist_map_square(struct dlist *list);
void dlist_reverse(struct dlist *list);

#endif /* !DLIST_TH3_H */