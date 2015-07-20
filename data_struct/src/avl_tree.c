#include "avl_tree.h"

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

static int max(int a, int b)
{
	return (a >= b) ? a : b;
}

static int node_height(struct bitree_node *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

static void update_height(struct bitree_node *node)
{
	if (node == NULL)
		return;

	node->height = 
		max(node_height(node->left), node_height(node->right)) + 1;
	update_height(node->parent);
	return;
}

static void update_child_height(struct bitree_node *node)
{
	if (node->left != NULL)
		update_height(node->left);
	else if (node->right != NULL)
		update_height(node->right);
	else
		update_height(node);
	return;
}

static struct bitree_node ** parent_link(struct bitree_node *node)
{
	struct bitree_node *node_parent = node->parent;

	if (node_parent == NULL)
		return NULL;
	
	if (node_parent->left == node)
		return &(node_parent->left);

	return &(node_parent->right);
}

/*      A           D
 *     /           / \
 *    D    --->   E   A
 *   / \             / 
 *  E   F           F
 */
static void roate_right(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *A = node;
	struct bitree_node *D = A->left;
	struct bitree_node *F = D->right;
	struct bitree_node **A_parent = parent_link(node);


	if (A_parent == NULL) {
		b->root = D;
	} else {
		(*A_parent) = D;
	}

	D->parent = A->parent;
	D->right = A;

	A->parent = D;
	A->left = F;

	if (F != NULL)
		F->parent = A;

	
	A->height = 0;
	D->height = 0;

	update_child_height(A);
	return;
}

/*    A              D
 *     \            / \
 *	D    --->  A   F
 *     / \          \
 *    E   F          E
 */
static void roate_left(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *A = node;
	struct bitree_node *D = A->right;
	struct bitree_node *E = D->left;
	struct bitree_node **A_parent = parent_link(node);

	if (A_parent == NULL) {
		b->root = D;
	} else {
		(*A_parent) = D;
	}

	D->parent = A->parent;
	D->left = A;

	A->right = E;
	A->parent = D;

	if (E != NULL)
		E->parent = A;
	
	A->height = 0;
	D->height = 0;

	update_child_height(A);
	return;
}

/*    A                A                 E        
 *   / \              / \               / \
 *  B   C    --->    E   C      --->   B   A  
 * / \              / \               / \ / \
 *D   E            B   G             D  F G  C 
 *   / \          / \
 *  F   G        D   F               
 */
static void roate_double_right(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *A = node;
	struct bitree_node *B = A->left;
	struct bitree_node *E = B->right;
	struct bitree_node *F = E->left;
	struct bitree_node *G = E->right;
	struct bitree_node **A_parent = parent_link(node);

	//roate left
	A->left = E;

	B->parent = E;
	B->right = F;

	E->parent = A;
	E->left = B;

	if (F != NULL)
		F->parent = B;

	//roate right
	if (A_parent == NULL) {
		b->root = E;
	} else {
		(*A_parent) = E;
	}

	E->parent = A->parent;
	E->right = A;

	A->parent = E;
	A->left = G;

	if (G != NULL)
		G->parent = A;

	//update height
	A->height = 0;
	B->height = 0;
	E->height = 0;
	
	update_child_height(A);
	update_child_height(B);
	return;
}

/*    A                A                 D        
 *   / \              / \               / \
 *  B   C    --->    B   D      --->   A   C  
 *     / \              / \           / \ / \
 *    D   E            F   C         B  F G  E 
 *   / \                  / \
 *  F   G                G   E               
 */
static void roate_double_left(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *A = node;
	struct bitree_node *C = A->right;
	struct bitree_node *D = C->left;
	struct bitree_node *F = D->left;
	struct bitree_node *G = D->right;
	struct bitree_node **A_parent = parent_link(node);

	//roate right
	A->right = D;

	D->parent = A;
	D->right = C;

	C->parent = D;
	C->left = G;

	if (G != NULL)
		G->parent = C;

	//roate left
	if (A_parent == NULL) {
		b->root = D;
	} else {
		(*A_parent) = D;
	}
	
	D->parent = A->parent;
	D->left = A;

	A->parent = D;
	A->right = F;

	if (F != NULL)
		F->parent = A;

	//update height
	A->height = 0;
	D->height = 0;
	C->height = 0;
	
	update_child_height(A);
	update_child_height(C);
	return;
}

static int node_bf(struct bitree_node *node)
{
	return node_height(node->left) - node_height(node->right);
}

static void balance_tree(AVLTREE *b, struct bitree_node *node)
{
	int bf, child_bf;

	if (node == NULL)
		return;

	bf = node_bf(node);

	if (bf > 1) {

		child_bf = node_bf(node->left);
		if (child_bf >= 0)
			roate_right(b, node);
		else
			roate_double_right(b, node);

	} else if (bf < -1) {

		child_bf = node_bf(node->right);
		if (child_bf <= 0)
			roate_left(b, node);
		else
			roate_double_left(b, node);
	}

	balance_tree(b, node->parent);

	return;
}

static void update_height_balance(AVLTREE *b, struct bitree_node *node)
{
	update_height(node);

	balance_tree(b, node);

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

	update_height_balance(b, node);

	return 0;
}

static void node_no_right(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node **parent = parent_link(node);

	if (parent == NULL)
		b->root = node->left;
	else
		*parent = node->left;

	if (node->left != NULL) {
		node->left->parent = node->parent;
		update_height_balance(b, node->left);
	} else {
		update_height_balance(b, node->parent);
	}

	free_node(b, node);

}

static void node_right_no_left(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node **parent = parent_link(node);

	if (parent == NULL)
		b->root = node->right;
	else
		*parent = node->right;

	node->right->left = node->left;
	node->right->parent = node->parent;

	if (node->left != NULL)
		node->left->parent = node->right;

	update_height_balance(b, node->right);
	free_node(b, node);
}

static void node_right_left(AVLTREE *b, struct bitree_node *node)
{
	struct bitree_node *successor = successor_replace_node(b, node);
	struct bitree_node **parent = parent_link(node);

	if (parent == NULL)
		b->root = successor;
	else
		*parent = successor;

	successor->parent = node->parent;

	update_height_balance(b, successor);
	free_node(b, node);
}

int avltree_remove(AVLTREE *b, void *data)
{
	struct bitree_node *node;
	struct bitree_node **parent_link = &(b->root);

	if (!search_node(b, &parent_link, b->root, data))
		return -1;
	node = *parent_link;

	if (node->right == NULL)
		node_no_right(b, node);
	else {
		if (node->right->left == NULL)
			node_right_no_left(b, node);
		else
			node_right_left(b, node);
	}

	return 0;
}
