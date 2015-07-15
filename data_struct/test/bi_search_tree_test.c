#include "unity_fixture.h"
#include "bi_search_tree.h"

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
//static struct dict d1 = {1, 1};
//static struct dict d2 = {2, 2};
//static struct dict d3 = {3, 2};
//static struct dict d4 = {4, 2};
//static struct dict d5 = {5, 2};
//static struct dict d6 = {6, 2};
//static struct dict d7 = {7, 2};
//static struct bitree_node *node[7] = {NULL};

TEST_GROUP(bi_search_tree_test);

TEST_SETUP(bi_search_tree_test)
{

	bitree_init(&btree, compare);
}

TEST_TEAR_DOWN(bi_search_tree_test)
{
	bitree_destroy(&btree);
}

TEST(bi_search_tree_test, BiSearchTreeInit)
{
	TEST_FAIL_MESSAGE("start heare");
}
