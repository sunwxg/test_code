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
static struct dict d3 = {3, 2};
static struct dict d4 = {4, 2};
static struct dict d5 = {5, 2};
static struct dict d6 = {6, 2};
static struct dict d7 = {7, 2};
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

TEST(avl_tree_test, avltreeAddHeight)
{
	
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d4);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);

	avltree_remove(&b, &d2);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}


TEST(avl_tree_test, avltreeAddRemoveRoot)
{
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d4);

	avltree_remove(&b, &d6);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
	
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->data);
}

TEST(avl_tree_test, avltreeAddRoateRight)
{
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d4);

	roate_right(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d3, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->left->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->left->height);

	avltree_remove(&b, &d1);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeAddRoateLeft)
{
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d5);
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d4);

	roate_left(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d5, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->left->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->right->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeAddDoubleRoateLeft)
{
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d4);
	avltree_insert(&b, &d7);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d5);

	roate_double_left(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeAddDoubleRoateRight)
{
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d4);
	avltree_insert(&b, &d5);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d7);

	roate_double_right(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(0, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}
