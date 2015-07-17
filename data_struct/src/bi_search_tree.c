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

static int search_node(BI_S_TREE *b, struct bitree_node ***parent_link,
	struct bitree_node *node, void *data)
{
	int result;
	
	if (node == NULL)
		return 0;

	result = b->compare(data, node->data);

	if (result == 0) {
		return 1;
	}

	if (result > 0 ) {
		*parent_link = &(node->right);
		return search_node(b, parent_link, node->right, data);
	}
	
	*parent_link = &(node->left);
	return search_node(b, parent_link, node->left, data);
}


static struct bitree_node * min(BI_S_TREE *b, struct bitree_node *node, struct bitree_node **parent_node)
{
	if (node->left == NULL)
		return node;
	*parent_node = node;
	return min(b, node->left, &(*parent_node));
}

static void free_node(BI_S_TREE *b, struct bitree_node *node)
{
	free(node);
	bitree_size(b)--;
	return;
}

static void successor_replace_node(BI_S_TREE *b, struct bitree_node **parent_node)
{
	struct bitree_node *successor, *parent_successor;
	struct bitree_node *node = *parent_node;
	
	if (node->right == NULL) {
		*parent_node = node->left;
		free_node(b, node);
		return;
	}

	if (node->right != NULL) {
		if (node->right->left == NULL) {
			*parent_node = node->right;
			free_node(b, node);
			return;
		}

		successor = min(b, node->right, &parent_successor);

		parent_successor->left = NULL;

		successor->left = node->left;
		successor->right = node->right;

		*parent_node = successor;

		free_node(b, node);
		return;
	}
}

int bi_search_tree_remove(BI_S_TREE *b, void *data)
{
	struct bitree_node **parent_link = &(b->root);

	if (!search_node(b, &parent_link, b->root, data))
		return -1;

	successor_replace_node(b, parent_link);

	return 0;
}

void * bi_search_tree_search(BI_S_TREE *b, void *data)
{
	struct bitree_node **parent_link = &(b->root);

	if (!search_node(b, &parent_link, b->root, data))
		return NULL;

	return (*parent_link)->data;
}