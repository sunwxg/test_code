#include "unity_fixture.h"
#include "bitree.h"
#include "bitree.c"

struct dict {
	int key;
	int value;
};

static int match(const void *data1, const void *data2)
{
	const struct dict *a = data1;
	const struct dict *b = data2;
	return (a->key == b->key) ? 1 : 0;
}


TEST_GROUP(bitree_test);

TEST_SETUP(bitree_test)
{
}

TEST_TEAR_DOWN(bitree_test)
{
}

TEST(bitree_test, bitreeInit)
{
	TEST_FAIL_MESSAGE("start here");
}
