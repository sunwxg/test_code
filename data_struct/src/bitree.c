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
	//free(b->root);
	memset(b, 0, sizeof(BITREE));
	return 0;
}

int bitree_insert_left(BITREE *b, struct bitree_node *node, void *data)
{
	struct bitree_node *position;

	if (bitree_size(b) == 0) {
		position = calloc(1, sizeof(struct bitree_node));
		if (position == NULL)
			return -1;

		memset(position, 0, sizeof(struct bitree_node));
		position->data = data;

		b->root = position;
		bitree_size(b)++;
		return 0;
	}

	if (node->left != NULL)
		return -1;
	
	position = calloc(1, sizeof(struct bitree_node));
	if (position == NULL)
		return -1;

	memset(position, 0, sizeof(struct bitree_node));
	position->data = data;
		
	node->left = position;
	bitree_size(b)++;

	return 0;
}


void * bitree_remove_left(BITREE *b, struct bitree_node *node)
{
	void *data;
	struct bitree_node *node_left;

	if (bitree_size(b) == 0)
		return NULL;
	
	node_left = node->left;
	if (!bitree_is_leaf(node->left))
		return NULL;	

	data = node->left->data;
	printf("node_left p=%p\n", node_left);
	free(node_left);
	bitree_size(b)--;

	return data;
}
