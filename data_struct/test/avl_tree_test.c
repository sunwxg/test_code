#include "unity_fixture.h"
#include "avl_tree.h"
#include "avl_tree.c"

struct dict {
	int key;
	int value;
};

static int compare(void *d1, void *d2)
{
	struct dict *a, *b;

	a = d1;
	b = d2;

	if (a->key > b->key)
		return 1;
	if (a->key == b->key)
		return 0;
	return -1;
	
}

static AVLTREE b;
static struct dict d1 = {1, 1};
static struct dict d2 = {2, 2};
/*static struct dict d3 = {3, 2};*/
/*static struct dict d4 = {4, 2};*/
/*static struct dict d5 = {5, 2};*/
/*static struct dict d6 = {6, 2};*/
/*static struct dict d7 = {7, 2};*/
/*static struct dict d8 = {8, 2};*/

TEST_GROUP(avl_tree_test);

TEST_SETUP(avl_tree_test)
{
	avltree_init(&b, &compare);
}

TEST_TEAR_DOWN(avl_tree_test)
{
	avltree_destroy(&b);
}

TEST(avl_tree_test, avltreeInsert)
{
	avltree_insert(&b, &d1);
}

TEST(avl_tree_test, avltreeRemove)
{
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d1);
	
	avltree_remove(&b, &d1);
	TEST_ASSERT_EQUAL_INT(1, b.size);
}
