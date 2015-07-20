#include "bi_search_tree.h"

void bi_search_tree_init(BI_S_TREE *b, int (*compare)(void *d1, void *d2))
{
	bitree_init(b, compare);
}

int bi_search_tree_destroy(BI_S_TREE *b)
{
	return bitree_destroy(b);
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

int search_node(BI_S_TREE *b, struct bitree_node ***parent_link,
	struct bitree_node *node, void *data)
{
	int result;
	
	if (node == NULL)
		return 0;

	result = b->compare(data, node->data);

	if (result == 0)
		return 1;

	if (result > 0 ) {
		*parent_link = &(node->right);
		return search_node(b, parent_link, node->right, data);
	}
	
	//result < 0
	*parent_link = &(node->left);
	return search_node(b, parent_link, node->left, data);
}


struct bitree_node * min(BI_S_TREE *b, struct bitree_node *node,
		struct bitree_node **parent_node)
{
	if (node->left == NULL)
		return node;

	*parent_node = node;
	return min(b, node->left, &(*parent_node));
}

void free_node(BI_S_TREE *b, struct bitree_node *node)
{
	memset(node, 0, sizeof(struct bitree_node));
	free(node);
	bitree_size(b)--;
	return;
}

struct bitree_node * 
successor_replace_node(BI_S_TREE *b, struct bitree_node *node)
{
	struct bitree_node *successor, *parent_successor;

	successor = min(b, node->right, &parent_successor);

	parent_successor->left = successor->right;
	if (successor->right != NULL)
		successor->right->parent = successor->parent;

	successor->left = node->left;
	successor->right = node->right;

	if (node->left != NULL)
		node->left->parent = successor;
	if (node->right != NULL)
		node->right->parent = successor;

	return successor;
}

int bi_search_tree_remove(BI_S_TREE *b, void *data)
{
	struct bitree_node *node;
	struct bitree_node **parent_link = &(b->root);

	if (!search_node(b, &parent_link, b->root, data))
		return -1;
	node = *parent_link;

	if (node->right == NULL) {
		*parent_link = node->left;
		if (*parent_link != NULL)
			(*parent_link)->parent = node->parent;
		free_node(b, node);
		return 0;
	}

	if (node->right != NULL) {
		if (node->right->left == NULL) {
			*parent_link = node->right;
			(*parent_link)->left = node->left;
			(*parent_link)->parent = node->parent;
			free_node(b, node);
			return 0;
		}

		*parent_link = successor_replace_node(b, node);
		(*parent_link)->parent = node->parent;

		free_node(b, node);
	}
	return 0;
}

void * bi_search_tree_search(BI_S_TREE *b, void *data)
{
	struct bitree_node **parent_link = &(b->root);

	if (!search_node(b, &parent_link, b->root, data))
		return NULL;

	return (*parent_link)->data;
}
