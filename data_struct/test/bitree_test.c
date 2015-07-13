#include "unity_fixture.h"
#include "bitree.h"
#include "bitree.c"

struct bitree_dict {
	int key;
	int value;
};

static BITREE btree;
static struct bitree_dict b_d1 = {1, 1};
//static struct dict d2 = {21, 2};
//static struct dict temp = {31, 3};

TEST_GROUP(bitree_test);

TEST_SETUP(bitree_test)
{
}

TEST_TEAR_DOWN(bitree_test)
{
}

TEST(bitree_test, bitree_insert_leftTreeSize)
{
	TEST_IGNORE();
	bitree_init(&btree);
	bitree_insert_left(&btree, btree.root, (void *)&b_d1);
	bitree_insert_left(&btree, btree.root, (void *)&b_d1);
	TEST_ASSERT_EQUAL_INT(2, bitree_size(&btree));
	
	//bitree_remove_left(&btree, btree.root);
	//TEST_ASSERT_EQUAL_PTR(&d1, bitree_remove_left(&b, b.root));
	//bitree_destroy(&b);
}

