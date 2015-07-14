#include "unity_fixture.h"
#include "bitree.h"

struct dict {
	int key;
	int value;
};

static int compare(void *d1, void *d2)
{
	struct dict *a, *b;

	a = d1;
	b = d2;

	return (a->key == b->key) ? 1 : 0;
}

static BITREE btree;
static struct dict d1 = {1, 1};
static struct dict d2 = {2, 2};
static struct dict d3 = {3, 2};
static struct dict d4 = {4, 2};
static struct dict d5 = {5, 2};
static struct dict d6 = {6, 2};
static struct dict d7 = {7, 2};
static struct bitree_node *node[7] = {NULL};

TEST_GROUP(bitree_find_test);

TEST_SETUP(bitree_find_test)
{

	bitree_init(&btree);
	node[0] = bitree_insert_left(&btree, node[0], (void *)&d1);
	node[1] = bitree_insert_left(&btree, node[0], (void *)&d2);
	node[2] = bitree_insert_right(&btree, node[0], (void *)&d3);
	node[3] = bitree_insert_left(&btree, node[1], (void *)&d4);
	node[4] = bitree_insert_right(&btree, node[1], (void *)&d5);
	node[5] = bitree_insert_left(&btree, node[2], (void *)&d6);
	node[6] = bitree_insert_right(&btree, node[2], (void *)&d7);

}

TEST_TEAR_DOWN(bitree_find_test)
{
	bitree_remove_left(&btree, node[2]);
	bitree_remove_right(&btree, node[2]);
	bitree_remove_left(&btree, node[1]);
	bitree_remove_right(&btree, node[1]);
	bitree_remove_left(&btree, node[0]);
	bitree_remove_right(&btree, node[0]);

	bitree_destroy(&btree);
}

TEST(bitree_find_test, bitree_find_preorder)
{
	struct dict temp = {6, 10};
	TEST_ASSERT_EQUAL_PTR(node[5], bitree_find(&btree, (void *)&temp, &compare));
}	
