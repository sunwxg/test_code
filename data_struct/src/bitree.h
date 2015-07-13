#ifndef __BITREE_H
#define __BITREE_H 1

#include <string.h>

struct bitree_node {
	void *data;
	struct bitree_node *left;
	struct bitree_node *right;
};

struct bitree {
	int size;
	struct bitree_node *root;
};

#define BITREE struct bitree

void bitree_init(BITREE *b);
int bitree_destroy(BITREE *b);

#define bitree_size(b) ((b)->size)

#endif /* __BITREE_H */
