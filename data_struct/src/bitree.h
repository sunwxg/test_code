#ifndef __BITREE_H
#define __BITREE_H 1

#include <string.h>

struct bitree_node {
	void *data;
	struct bitree_node *left;
	struct bitree_node *right;
};

struct bitree_ {
	int size;
	struct bitree_node *root;
};

#define BITREE struct bitree_

void bitree_init(BITREE *b);

/* bitree_destroy
 * success: return 0
 * fail:    return -1
 */
int bitree_destroy(BITREE *b);

/* bitree_insert_left
 * success: return node pointer
 * fail:    return NULL
 */
struct bitree_node * 
bitree_insert_left(BITREE *b, struct bitree_node *node, void *data);

/* bitree_insert_right
 * success: return node pointer
 * fail:    return NULL
 */
struct bitree_node * 
bitree_insert_right(BITREE *b, struct bitree_node *node, void *data);

/* bitree_remove_left
 * success: return * data of node
 * fail:    return NULL
 */
void * bitree_remove_left(BITREE *b, struct bitree_node *node);

/* bitree_remove_right
 * success: return * data of node
 * fail:    return NULL
 */
void * bitree_remove_right(BITREE *b, struct bitree_node *node);

/* bitree_find
 * success: return node pointer
 * fail:    return NULL
 */
struct bitree_node * bitree_find(BITREE *b, void *data, int (*compare)(void *data1, void *data2));


#define bitree_size(b) ((b)->size)
#define bitree_is_leaf(node) (((node)->left == NULL) && ((node)->right == NULL))
#define node_left(node) ((node)->left)
#define node_right(node) ((node)->right)

#endif /* __BITREE_H */
