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

struct bitree_node * 
bitree_insert_left(BITREE *b, struct bitree_node *node, void *data);

struct bitree_node * 
bitree_insert_right(BITREE *b, struct bitree_node *node, void *data);

void * bitree_remove_left(BITREE *b, struct bitree_node *node);

void * bitree_remove_right(BITREE *b, struct bitree_node *node);

struct bitree_node * bitree_find_pre(BITREE *b, void *data,
		int (*compare)(void *data1, void *data2));

struct bitree_node * bitree_find_in(BITREE *b, void *data,
		int (*compare)(void *data1, void *data2));

struct bitree_node * bitree_find_post(BITREE *b, void *data,
		int (*compare)(void *data1, void *data2));

#define bitree_size(b) ((b)->size)
#define bitree_is_leaf(node) (((node)->left == NULL) && ((node)->right == NULL))

#endif /* __BITREE_H */
