#ifndef __AVL_TREE_H
#define __AVL_TREE_H 1

#include "bi_search_tree.h"

typedef BITREE AVLTREE;

void avltree_init(AVLTREE *b, int (*compare)(void *d1, void *d2));

int avltree_destroy(AVLTREE *b);

int avltree_insert(AVLTREE *b, void *data);

#endif /* __AVL_TREE_H */
