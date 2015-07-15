#include "bi_search_tree.h"

void bi_search_tree_init(BI_S_TREE *b, int (*compare)(void *d1, void *d2))
{
	bitree_init(b, compare);
}

static int insert_left(BITREE *b, struct bitree_node *node, void *data)
{
	if (bitree_insert_left(b, node, data) == NULL)
		return -1;
	return 0;
}

static int insert_right(BITREE *b, struct bitree_node *node, void *data)
{
	if (bitree_insert_right(b, node, data) == NULL)
		return -1;
	return 0;
}

static int search_insert(BI_S_TREE *b, struct bitree_node *node, void *data)
{
	if (b->compare(data, node->data) > 0) {
		if (node->right == NULL)
			return insert_right(b, node, data); 
		return search_insert(b, node->right, data);
	} else {
		if (node->left == NULL)
			return insert_left(b, node, data); 
		return search_insert(b, node->left, data);
	}
}

int bi_search_tree_insert(BI_S_TREE *b, void *data)
{
	if (bitree_size(b) == 0)
		return insert_left(b, NULL, data);
	
	return search_insert(b, b->root, data);
}

static struct bitree_node * search_node(BI_S_TREE *b, 
	struct bitree_node *pre_node, struct bitree_node *node, void *data)
{
	int result;
	
	if (node == NULL)
		return NULL;

	result = b->compare(data, node->data);

	if (result == 0)
		return pre_node;

	if (result > 0 )
		return search_node(b, node, node->right, data);
	
	return search_node(b, node, node->left, data);
}

int bi_search_tree_remove(BI_S_TREE *b, void *data)
{
	struct bitree_node *node = search_node(b, NULL, b->root, data);
	
	if (node == NULL)
		return -1;

	if ((node->left != NULL) && (b->compare(data, node->left->data) ==0)) {
		bitree_remove_left(b, node);
		return 0;
	}

	bitree_remove_right(b, node);
	return 0;
}

void * bi_search_tree_search(BI_S_TREE *b, void *data)
{
	struct bitree_node *node = search_node(b, NULL, b->root, data);
	
	if (node == NULL)
		return NULL;

	if ((node->left != NULL) && (b->compare(data, node->left->data) ==0))
		return node->left->data;

	return node->right->data;
}
