#include "unity_fixture.h"
#include "bi_search_tree.h"
#include "bi_search_tree.c"

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

static BI_S_TREE b;
static struct dict d1 = {1, 1};
static struct dict d2 = {2, 2};
static struct dict d3 = {3, 2};
static struct dict d4 = {4, 2};
static struct dict d5 = {5, 2};
static struct dict d6 = {6, 2};
static struct dict d7 = {7, 2};
static struct dict d8 = {8, 2};

TEST_GROUP(bi_search_tree_test);

TEST_SETUP(bi_search_tree_test)
{

	bi_search_tree_init(&b, compare);
}

TEST_TEAR_DOWN(bi_search_tree_test)
{
	bitree_destroy(&b);
}

TEST(bi_search_tree_test, BiSearchTreeInit)
{
	TEST_ASSERT_EQUAL_INT(0, b.size);
}

TEST(bi_search_tree_test, BiSearchTreeInsertRight)
{
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d2);

	TEST_ASSERT_EQUAL_PTR(&d2, b.root->right->data);

	bi_search_tree_remove(&b, &d2);
}

TEST(bi_search_tree_test, BiSearchTreeInsertLeft)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);

	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);

	bi_search_tree_remove(&b, &d1);
}


TEST(bi_search_tree_test, BiSearchTreeSearch)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d3);
	
	TEST_ASSERT_EQUAL_PTR(&d1, bi_search_tree_search(&b, &d1));
	TEST_ASSERT_EQUAL_PTR(&d3, bi_search_tree_search(&b, &d3));

	bi_search_tree_remove(&b, &d3);
	bi_search_tree_remove(&b, &d1);
}

TEST(bi_search_tree_test, BiSearchTreeMin)
{
	struct bitree_node *parent_node;
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);

	TEST_ASSERT_EQUAL_INT(1, ((struct dict *)(min(&b, b.root, &parent_node)->data))->key);
	TEST_ASSERT_EQUAL_PTR(&d2, parent_node->data);
	
	bi_search_tree_remove(&b, &d2);
	bi_search_tree_remove(&b, &d1);
}

TEST(bi_search_tree_test, BiSearchTreeRemoveNonChild)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d2);

	bi_search_tree_remove(&b, &d2);

	TEST_ASSERT_EQUAL_INT(1, b.size);
	TEST_ASSERT_EQUAL_PTR(NULL, b.root->left);
	
}

TEST(bi_search_tree_test, BiSearchTreeRemoveLeftChild)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d4);

	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->left->data);

	bi_search_tree_remove(&b, &d5);

	TEST_ASSERT_EQUAL_INT(2, b.size);
	TEST_ASSERT_EQUAL_PTR(NULL, b.root->right->left);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->data);
	
	bi_search_tree_remove(&b, &d4);
}

TEST(bi_search_tree_test, BiSearchTreeRemoveRightChild)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d6);

	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->right->data);

	bi_search_tree_remove(&b, &d5);

	TEST_ASSERT_EQUAL_INT(2, b.size);
	TEST_ASSERT_EQUAL_PTR(NULL, b.root->right->right);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	
	bi_search_tree_remove(&b, &d6);
}

TEST(bi_search_tree_test, BiSearchTreeRemoveRightAnyChild)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d7);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d8);

	bi_search_tree_remove(&b, &d5);

	TEST_ASSERT_EQUAL_INT(4, b.size);
	TEST_ASSERT_EQUAL_PTR(&d6, b.root->right->data);
	TEST_ASSERT_EQUAL_PTR(&d7, b.root->right->right->data);
	TEST_ASSERT_EQUAL_PTR(&d8, b.root->right->right->right->data);
	
	bi_search_tree_remove(&b, &d6);
	bi_search_tree_remove(&b, &d7);
	bi_search_tree_remove(&b, &d8);
}

TEST(bi_search_tree_test, BiSearchTreeRemoveRightAnyChild2)
{
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d3);

	bi_search_tree_remove(&b, &d2);

	TEST_ASSERT_EQUAL_INT(5, b.size);
	TEST_ASSERT_EQUAL_PTR(NULL, b.root->right->right->left->left->left);
	TEST_ASSERT_EQUAL_PTR(&d4, b.root->right->right->left->left->data);
	
	bi_search_tree_remove(&b, &d3);
	bi_search_tree_remove(&b, &d4);
	bi_search_tree_remove(&b, &d5);
	bi_search_tree_remove(&b, &d6);
}

TEST(bi_search_tree_test, BiSearchTreeRemoveRootNode)
{
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d6);
	bi_search_tree_insert(&b, &d5);
	bi_search_tree_insert(&b, &d4);
	bi_search_tree_insert(&b, &d3);

	bi_search_tree_remove(&b, &d1);

	TEST_ASSERT_EQUAL_INT(5, b.size);
	TEST_ASSERT_EQUAL_PTR(&d2, b.root->data);
	
	bi_search_tree_remove(&b, &d3);
	bi_search_tree_remove(&b, &d4);
	bi_search_tree_remove(&b, &d5);
	bi_search_tree_remove(&b, &d6);
}
