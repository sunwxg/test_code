#include "avl_tree.h"


void avltree_init(AVLTREE *b, int (*compare)(void *d1, void *d2))
{
	bitree_init(b, compare);
	return;
}

int avltree_destroy(AVLTREE *b)
{
	return bitree_destroy(b);
}

int avltree_insert(AVLTREE *b, void *data)
{
	if (bi_search_tree_insert(b, data) == -1)
		return -1;

	return 0;
}

int avltree_remove(AVLTREE *b, void *data)
{
	return bi_search_tree_remove(b, data);
}
