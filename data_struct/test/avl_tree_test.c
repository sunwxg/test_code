#include "unity_fixture.h"
#include "avl_tree.h"
#include "avl_tree.c"
struct dict {
	int key;
	int value;
};

/*static int compare(void *d1, void *d2)*/
/*{*/
	/*struct dict *a, *b;*/

	/*a = d1;*/
	/*b = d2;*/

	/*if (a->key > b->key)*/
		/*return 1;*/
	/*if (a->key == b->key)*/
		/*return 0;*/
	/*return -1;*/
	
/*}*/

/*static BI_S_TREE b;*/
/*static struct dict d1 = {1, 1};*/
/*static struct dict d2 = {2, 2};*/
/*static struct dict d3 = {3, 2};*/
/*static struct dict d4 = {4, 2};*/
/*static struct dict d5 = {5, 2};*/
/*static struct dict d6 = {6, 2};*/
/*static struct dict d7 = {7, 2};*/
/*static struct dict d8 = {8, 2};*/

TEST_GROUP(avl_tree_test);

TEST_SETUP(avl_tree_test)
{

}

TEST_TEAR_DOWN(avl_tree_test)
{
}

TEST(avl_tree_test, avl_tree_test_init)
{
	TEST_IGNORE();
}
