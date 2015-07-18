#include "avl_tree.h"

#define node_height(node) ((node)->height)

void avltree_init(AVLTREE *b, int (*compare)(void *d1, void *d2))
{
	bitree_init(b, compare);
	return;
}

int avltree_destroy(AVLTREE *b)
{
	return bitree_destroy(b);
}

static struct bitree_node *
search_insert(AVLTREE *b, struct bitree_node *node, void *data)
{
	if (b->compare(data, node->data) > 0) {
		if (node->right == NULL)
			return bitree_insert_right(b, node, data); 
		return search_insert(b, node->right, data);
	} else {
		if (node->left == NULL)
			return bitree_insert_left(b, node, data); 
		return search_insert(b, node->left, data);
	}
}

static void update_height(struct bitree_node *node)
{
	if (node->parent != NULL) {
		if (node_height(node->parent) >= (node_height(node) + 1))
			return;
		node_height(node->parent) = node_height(node) + 1;
		update_height(node->parent);
	}
}

static void roate_right(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *node_parent = node->parent;
	struct bitree_node *node_left = node->left;

	if (node_parent == NULL) {
		b->root = node_left;
	} else {
		node_parent->left = node_left;
	}

	node_left->parent = node_parent;

	node->left = node_left->right;
	node_left->right = node;

	node->parent = node_left;

	node->left->parent = node;
	
	node->height = 0;
	node_left->height = 0;

	update_height(node->left);

	return;
}

/*    A              D
 *     \            / \
 *	D          A   F
 *     / \          \
 *    E   F          E
 */
static void roate_left(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *A = node;
	struct bitree_node *D = A->right;
	struct bitree_node *E = D->left;
	struct bitree_node *A_parent = A->parent;

	if (A_parent == NULL) {
		b->root = D;
	} else {
		A_parent->right = D;
	}

	A->right = E;
	A->parent = D;

	D->parent = A_parent;
	D->left = A;

	E->parent = A;
	
	A->height = 0;
	D->height = 0;

	update_height(E);

	return;
}

static void roate_double_right(struct bitree_node *node)
{

	return;
}

static void roate_double_left(struct bitree_node *node)
{

	return;
}

static void balance_tree(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *parent_node = node->parent;
	int bf;

	while (parent_node != NULL) {
		bf = (parent_node->left->height) - (parent_node->right->height);
		if (bf < -1) {
			roate_right(b, parent_node);
		} else if (bf > 1) {
			roate_left(b, parent_node);
		}

	}
	return;
}

int avltree_insert(AVLTREE *b, void *data)
{
	struct bitree_node *node;

	if (bitree_size(b) == 0) {
		node = bitree_insert_left(b, NULL, data);
		return (node == NULL) ? -1 : 0;
	}

	node = search_insert(b, b->root, data);

	update_height(node);

	return 0;
}

int avltree_remove(AVLTREE *b, void *data)
{
	return bi_search_tree_remove(b, data);
}
