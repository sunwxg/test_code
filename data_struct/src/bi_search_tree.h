#ifndef __BI_SEARCH_TREE_H
#define __BI_SEARCH_TREE_H 1

#include "bitree.h"

#define BI_S_TREE BITREE

void bi_search_tree_init(BI_S_TREE *b, int (*compare)(void *d1, void *d2));

int bi_search_tree_insert(BI_S_TREE *b, void *data);

int bi_search_tree_remove(BI_S_TREE *b, void *data);

void * bi_search_tree_search(BI_S_TREE *b, void *data);

#endif /* __BI_SEARCH_TREE_H */
