#ifndef __AVL_TREE_H
#define __AVL_TREE_H 1

#include "bi_search_tree.h"
#include "bi_search_tree_internal.h"

typedef BITREE AVLTREE;

void avltree_init(AVLTREE *b, int (*compare)(void *d1, void *d2));

/* avltree_destroy
 * success: return 0
 * fail   : return -1
 */
int avltree_destroy(AVLTREE *b);

/* avltree_insert
 * success: return 0
 * fail   : return -1
 */
int avltree_insert(AVLTREE *b, void *data);

/* avltree_search
 * success: return pointer of data
 * fail   : return NULL
 */
void * avltree_search(AVLTREE *b, void *data);

#endif /* __AVL_TREE_H */
