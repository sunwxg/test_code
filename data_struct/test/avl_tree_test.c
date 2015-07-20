#include "unity_fixture.h"
#include "avl_tree.h"
#include "avl_tree.c"
#include <stdlib.h>

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
static struct dict d8 = {8, 2};
static struct dict d14 = {14, 2};
static struct dict d12 = {12, 2};
static struct dict d17 = {17, 2};
static struct dict d18 = {18, 2};
static struct dict d13 = {13, 2};
static struct dict d9 = {9, 2};
static struct dict d10 = {10, 2};

static struct dict d[1000];

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
	bi_search_tree_insert(&b, &d1);
}

TEST(avl_tree_test, avltreeRemove)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	
	avltree_remove(&b, &d1);
	TEST_ASSERT_EQUAL_INT(1, b.size);
}

TEST(avl_tree_test, avltreeAddHeight)
{
	
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d4);

	update_height(b.root->right->right->right);

	TEST_ASSERT_EQUAL_INT(4, b.root->height);
	TEST_ASSERT_EQUAL_INT(3, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->right->height);

	avltree_remove(&b, &d2);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}


TEST(avl_tree_test, avltreeAddRemoveRoot)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d4);

	avltree_remove(&b, &d6);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
	
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->data);
}

TEST(avl_tree_test, avltreeAddRoateRight)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->left->left);

	roate_right(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d3, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->left->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d1);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeAddRoateLeft)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->right->right);

	roate_left(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d5, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->left->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeAddDoubleRoateLeft)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d7);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	update_height(b.root->right->left->left);

	roate_double_left(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeAddDoubleRoateLeft2)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->right->left);

	roate_double_left(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);

	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
}

TEST(avl_tree_test, avltreeAddDoubleRoateRight)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d7);
	update_height(b.root->left->right->right);

	roate_double_right(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeAddDoubleRoateRight2)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->left->right);

	roate_double_right(&b, b.root);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);

	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
}

TEST(avl_tree_test, avltreeBalanceTreeDoubleRight)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d7);
	update_height(b.root->left->right->right);

	balance_tree(&b, b.root->left->right->right);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeBalanceTreeDoubleLeft)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d7);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	update_height(b.root->right->left->left);

	balance_tree(&b, b.root->right->left->left);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeBalanceTreeRight)
{
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->left->left);

	balance_tree(&b, b.root->left->right);

	TEST_ASSERT_EQUAL_PTR(&d3, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->left->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d1);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeBalanceTreeLeft)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d4);
	update_height(b.root->right->right);

	balance_tree(&b, b.root->right->left);

	TEST_ASSERT_EQUAL_PTR(&d5, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->left->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeInsertLeft)
{
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d5);
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d4);

	TEST_ASSERT_EQUAL_PTR(&d5, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->left->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeInsertRight)
{
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d4);

	TEST_ASSERT_EQUAL_PTR(&d3, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->left->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d1);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeInsertDoubleLeft)
{
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d4);
	avltree_insert(&b, &d7);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d5);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeInsertDoubleRight)
{
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d7);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d4);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d5);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d3, b.root->left->right->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->left->data);
	TEST_ASSERT_EQUAL_PTR(&d5, b.root->right->left->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);

	TEST_ASSERT_EQUAL_INT(3, b.root->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(2, b.root->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->right->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->left->height);

	avltree_remove(&b, &d3);
	avltree_remove(&b, &d5);
	avltree_remove(&b, &d4);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d7);
}

TEST(avl_tree_test, avltreeRemoveHeightValue)
{
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d1);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d4);

	avltree_remove(&b, &d3);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->data);
	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->data);

	TEST_ASSERT_EQUAL_INT(2, b.root->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->left->height);
	TEST_ASSERT_EQUAL_INT(1, b.root->right->height);

	avltree_remove(&b, &d1);
	avltree_remove(&b, &d4);
}

TEST(avl_tree_test, avltreeRemoveOneValue)
{
	avltree_insert(&b, &d8);
	avltree_insert(&b, &d5);
	avltree_insert(&b, &d14);
	avltree_insert(&b, &d6);
	avltree_insert(&b, &d3);
	avltree_insert(&b, &d12);
	avltree_insert(&b, &d17);
	avltree_insert(&b, &d2);
	avltree_insert(&b, &d13);
	avltree_insert(&b, &d9);
	avltree_insert(&b, &d18);
	avltree_insert(&b, &d10);

	avltree_remove(&b, &d8);

	avltree_remove(&b, &d5);
	avltree_remove(&b, &d6);
	avltree_remove(&b, &d3);
	avltree_remove(&b, &d2);
	avltree_remove(&b, &d14);
	avltree_remove(&b, &d12);
	avltree_remove(&b, &d17);
	avltree_remove(&b, &d13);
	avltree_remove(&b, &d9);
	avltree_remove(&b, &d10);
	avltree_remove(&b, &d18);
}

TEST(avl_tree_test, avltreeInsert100Data)
{
	int size = 1000;

	for (int i = 1; i <= size; i++) {
		d[i-1].key = i;
		d[i-1].value = i;
		avltree_insert(&b, &d[i-1]);
	}

	for (int i = 1; b.size>3; i++) {
		int k = rand()%size;

		avltree_remove(&b, &d[k]);
	}

	for (int i = 1; i <= size; i++)
		avltree_remove(&b, &d[i-1]);
}
