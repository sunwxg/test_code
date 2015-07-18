#ifndef __BITREE_H
#define __BITREE_H 1

#include <string.h>

struct bitree_node {
	void *data;
	int bf;
	int height;
	struct bitree_node *parent;
	struct bitree_node *left;
	struct bitree_node *right;
};

struct bitree {
	int size;
	struct bitree_node *root;
	int (*compare)(void *data1, void *data2);
};

#define BITREE struct bitree

void bitree_init(BITREE *b, int (*compare)(void *data1, void *data2));

/* bitree_destroy
 * success: return 0
 * fail   : return -1
 */
int bitree_destroy(BITREE *b);

/* bitree_insert_left
 * success: return pointer of node
 * fail   : return NULL
 */
struct bitree_node * 
bitree_insert_left(BITREE *b, struct bitree_node *node, void *data);

/* bitree_insert_right
 * success: return pointer of node
 * fail   : return NULL
 */
struct bitree_node * 
bitree_insert_right(BITREE *b, struct bitree_node *node, void *data);

/* bitree_remove_left
 * success: return pointer of data
 * fail   : return NULL
 */
void * bitree_remove_left(BITREE *b, struct bitree_node *node);

/* bitree_remove_right
 * success: return pointer of data
 * fail   : return NULL
 */
void * bitree_remove_right(BITREE *b, struct bitree_node *node);

/* bitree_find_pre
 * success: return pointer of node
 * fail   : return NULL
 */
struct bitree_node * bitree_find_pre(BITREE *b, void *data);

/* bitree_find_in
 * success: return pointer of node
 * fail   : return NULL
 */
struct bitree_node * bitree_find_in(BITREE *b, void *data);

/* bitree_find_post
 * success: return pointer of node
 * fail   : return NULL
 */
struct bitree_node * bitree_find_post(BITREE *b, void *data);

#define bitree_size(b) ((b)->size)
#define bitree_is_leaf(node) (((node)->left == NULL) && ((node)->right == NULL))

#endif /* __BITREE_H */
