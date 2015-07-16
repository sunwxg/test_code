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
//static struct dict d4 = {4, 2};
//static struct dict d5 = {5, 2};
//static struct dict d6 = {6, 2};
//static struct dict d7 = {7, 2};
//static struct bitree_node *node[7] = {NULL};

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

	//bi_search_tree_remove(&b, &d2);
	free(b.root->right);
	b.size--;
}

TEST(bi_search_tree_test, BiSearchTreeInsertLeft)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);

	TEST_ASSERT_EQUAL_PTR(&d1, b.root->left->data);

	//bi_search_tree_remove(&b, &d1);
	free(b.root->left);
	b.size--;
}


TEST(bi_search_tree_test, BiSearchTreeSearch)
{
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);
	bi_search_tree_insert(&b, &d3);
	
	TEST_ASSERT_EQUAL_PTR(&d1, bi_search_tree_search(&b, &d1));
	TEST_ASSERT_EQUAL_PTR(&d3, bi_search_tree_search(&b, &d3));

	//bi_search_tree_remove(&b, &d3);
	//bi_search_tree_remove(&b, &d1);
	free(b.root->left);
	free(b.root->right);
	b.size = 1;
}

TEST(bi_search_tree_test, BiSearchTreeMin)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d2);
	bi_search_tree_insert(&b, &d1);

	TEST_ASSERT_EQUAL_INT(1, ((struct dict *)(min(&b, b.root)->data))->key);
	
	free(b.root->left->left);
	free(b.root->left);
	b.size = 1;
}

TEST(bi_search_tree_test, BiSearchTreeRemoveNonChild)
{
	bi_search_tree_insert(&b, &d3);
	bi_search_tree_insert(&b, &d2);

	bi_search_tree_remove(&b, &d2);

	TEST_ASSERT_EQUAL_INT(1, b.size);
	TEST_ASSERT_EQUAL_PTR(NULL, b.root->left);
	
}
