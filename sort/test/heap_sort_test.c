#include "unity_fixture.h"
#include "sort.h"
#include "heap_sort.c"

static int compare(void *key1, void *key2)
{
	int *a = (int *)key1;
	int *b = (int *)key2;

	return *a > *b ? 1 : 0;
}

TEST_GROUP(heap_sort);

TEST_SETUP(heap_sort)
{
}

TEST_TEAR_DOWN(heap_sort)
{
}

TEST(heap_sort, SortTwoArray)
{
	TEST_ASSERT_MESSAGE(0, "start here");
}

TEST_GROUP_RUNNER(heap_sort)
{
	RUN_TEST_CASE(heap_sort, SortTwoArray);
	
}
