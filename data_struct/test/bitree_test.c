#include "unity_fixture.h"
#include "bitree.h"
#include "bitree.c"

struct dict {
	int key;
	int value;
};

static BITREE b;
static struct bitree_node *d1, *d2;

TEST_GROUP(bitree_test);

TEST_SETUP(bitree_test)
{
	bitree_init(&b);
	d1 = malloc(sizeof(struct bitree_node));
	d2 = malloc(sizeof(struct bitree_node));

}

TEST_TEAR_DOWN(bitree_test)
{
	bitree_destroy(&b);
	free(d1);
	free(d2);
}

TEST(bitree_test, bitree_insert_leftTreeSize)
{
	
}
