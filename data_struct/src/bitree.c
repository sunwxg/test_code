#include "bitree.h"

void bitree_init(BITREE *b)
{
	b->size = 0;
	b->root = NULL;

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
struct dict;

static struct bitree_node *
bitree_preorder(BITREE *b, struct bitree_node *node, void *data,
		int (*compare)(void *d1, void *d2))
{
	struct bitree_node *temp;

	if (node == NULL)
		return NULL;
	
//	printf("node is %d\n", *(int *)(node->data));
	if (compare(node->data, data) == 1)
		return node;

	temp = bitree_preorder(b, node->left, data, compare);
	if (temp != NULL)
		return temp;

	temp = bitree_preorder(b, node->right, data, compare);

	return temp;
}

struct bitree_node * bitree_find_pre(BITREE *b, void *data,
		int (*compare)(void *data1, void *data2))
{
	return bitree_preorder(b, b->root, data, compare);
}

static struct bitree_node *
bitree_inorder(BITREE *b, struct bitree_node *node, void *data,
		int (*compare)(void *d1, void *d2))
{
	struct bitree_node *temp;

	if (node == NULL)
		return NULL;
	
	temp = bitree_inorder(b, node->left, data, compare);
	if (temp != NULL)
		return temp;

//	printf("node is %d\n", *(int *)(node->data));
	if (compare(node->data, data) == 1)
		return node;

	temp = bitree_inorder(b, node->right, data, compare);

	return temp;
}

struct bitree_node * bitree_find_in(BITREE *b, void *data,
		int (*compare)(void *data1, void *data2))
{
	return bitree_inorder(b, b->root, data, compare);
}
