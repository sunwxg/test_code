#include "bitree.h"

void bitree_init(BITREE *b, int (*compare)(void *data1, void *data2))
{
	b->size = 0;
	b->root = NULL;
	b->compare = compare;

	return;
}

int bitree_destroy(BITREE *b)
{
	if (bitree_size(b) > 1)
		return -1;

	if (bitree_size(b) == 1)
		free(b->root);

	memset(b, 0, sizeof(BITREE));
	return 0;
}

static struct bitree_node * insert_root_node(BITREE *b, void *data)
{
	
	struct bitree_node *position = calloc(1, sizeof(struct bitree_node));

	if (position == NULL)
		return NULL;

	position->data = data;
	position->height = 0;

	b->root = position;
	bitree_size(b)++;

	return position;
}

struct bitree_node * 
bitree_insert_left(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *position;

	if (bitree_size(b) == 0)
		return insert_root_node(b, data);

	if (node->left != NULL)
		return NULL;
	
	position = calloc(1, sizeof(struct bitree_node));
	if (position == NULL)
		return NULL;

	position->data = data;
	position->parent = node;
	position->height = 0;
		
	node->left = position;
	bitree_size(b)++;

	return position;
}

struct bitree_node * 
bitree_insert_right(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *position;

	if (bitree_size(b) == 0)
		return insert_root_node(b, data);

	if (node->right != NULL)
		return NULL;
	
	position = calloc(1, sizeof(struct bitree_node));
	if (position == NULL)
		return NULL;

	position->data = data;
	position->parent = node;
	position->height = 0;
		
	node->right = position;
	bitree_size(b)++;

	return position;
}

void * bitree_remove_left(BITREE *b, struct bitree_node *node)
{
	void *data;

	if (node == NULL)
		return NULL;

	if (bitree_size(b) == 0)
		return NULL;
	
	if (node->left == NULL)
		return NULL;

	if (!bitree_is_leaf(node->left))
		return NULL;	

	data = node->left->data;

	free(node->left);
	node->left = NULL;
	bitree_size(b)--;

	return data;
}

void * bitree_remove_right(BITREE *b, struct bitree_node *node)
{
	void *data;

	if (node == NULL)
		return NULL;

	if (bitree_size(b) == 0)
		return NULL;
	
	if (node->right == NULL)
		return NULL;

	if (!bitree_is_leaf(node->right))
		return NULL;	

	data = node->right->data;

	free(node->right);
	node->right = NULL;
	bitree_size(b)--;

	return data;
}

static struct bitree_node *
bitree_preorder(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *finded_node;

	if (node == NULL)
		return NULL;
	
	if (b->compare(node->data, data) == 1)
		return node;

	finded_node = bitree_preorder(b, node->left, data);
	if (finded_node != NULL)
		return finded_node;

	finded_node = bitree_preorder(b, node->right, data);
	if (finded_node != NULL)
		return finded_node;

	return finded_node;
}

struct bitree_node * bitree_find_pre(BITREE *b, void *data)
{
	return bitree_preorder(b, b->root, data);
}

static struct bitree_node *
bitree_inorder(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *finded_node;

	if (node == NULL)
		return NULL;
	
	finded_node = bitree_inorder(b, node->left, data);
	if (finded_node != NULL)
		return finded_node;

	if (b->compare(node->data, data) == 1)
		return node;

	finded_node = bitree_inorder(b, node->right, data);
	if (finded_node != NULL)
		return finded_node;

	return finded_node;
}

struct bitree_node * bitree_find_in(BITREE *b, void *data)
{
	return bitree_inorder(b, b->root, data);
}

static struct bitree_node *
bitree_postorder(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *finded_node;

	if (node == NULL)
		return NULL;
	
	finded_node = bitree_postorder(b, node->left, data);
	if (finded_node != NULL)
		return finded_node;


	finded_node = bitree_postorder(b, node->right, data);
	if (finded_node != NULL)
		return finded_node;

	if (b->compare(node->data, data) == 1)
		return node;

	return finded_node;
}

struct bitree_node * bitree_find_post(BITREE *b, void *data)
{
	return bitree_postorder(b, b->root, data);
}
