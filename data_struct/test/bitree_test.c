#include "unity_fixture.h"
#include "bitree.h"
#include "bitree.c"

struct dict {
	int key;
	int value;
};

int compare(void *d1, void *d2)
{
	struct dict *a, *b;

	a = d1;
	b = d2;

	return (a->key == b->key) ? 1 : 0;
}

static BITREE btree;
static struct dict d1 = {1, 1};
static struct dict d2 = {21, 2};
//static struct dict temp = {31, 3};

TEST_GROUP(bitree_test);

TEST_SETUP(bitree_test)
{
	bitree_init(&btree, &compare);
}

TEST_TEAR_DOWN(bitree_test)
{
	bitree_destroy(&btree);
}

TEST(bitree_test, bitree_insert_leftTreeSize)
{
	bitree_insert_left(&btree, btree.root, (void *)&d1);
	bitree_insert_left(&btree, btree.root, (void *)&d2);

	TEST_ASSERT_EQUAL_INT(2, bitree_size(&btree));
	
	bitree_remove_left(&btree, btree.root);
}

TEST(bitree_test, bitree_insert_leftDataValue)
{
	bitree_insert_left(&btree, btree.root, (void *)&d1);
	bitree_insert_left(&btree, btree.root, (void *)&d2);

	TEST_ASSERT_EQUAL_INT(1, ((struct dict *)btree.root->data)->value);
	TEST_ASSERT_EQUAL_INT(2, ((struct dict *)(btree.root->left->data))->value);

	bitree_remove_left(&btree, btree.root);
}

TEST(bitree_test, bitree_insert_rightTreeSize)
{
	bitree_insert_right(&btree, btree.root, (void *)&d1);
	bitree_insert_right(&btree, btree.root, (void *)&d2);

	TEST_ASSERT_EQUAL_INT(2, bitree_size(&btree));
	
	bitree_remove_right(&btree, btree.root);
}

TEST(bitree_test, bitree_insert_rightDataValue)
{
	bitree_insert_right(&btree, btree.root, (void *)&d1);
	bitree_insert_right(&btree, btree.root, (void *)&d2);

	TEST_ASSERT_EQUAL_INT(1, ((struct dict *)btree.root->data)->value);
	TEST_ASSERT_EQUAL_INT(2, ((struct dict *)(btree.root->right->data))->value);

	bitree_remove_right(&btree, btree.root);
}

TEST(bitree_test, bitree_remove_leftNonData)
{
	TEST_ASSERT_EQUAL_PTR(NULL, bitree_remove_left(&btree, btree.root));	
}

TEST(bitree_test, bitree_remove_rightNonData)
{
	TEST_ASSERT_EQUAL_PTR(NULL, bitree_remove_right(&btree, btree.root));	
}

