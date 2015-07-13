#include "bitree.h"

void bitree_init(BITREE *b)
{
	b->size = 0;
	b->root = NULL;

	return;
}

int bitree_destroy(BITREE *b)
{
	if (bitree_size(b) != 0)
		return -1;
	memset(b, 0, sizeof(BITREE));
	return 0;
}
