#include "unity_fixture.h"
#include "sort.h"
#include "merge_sort.c"

static int compare(void *key1, void *key2)
{
	int *a = (int *)key1;
	int *b = (int *)key2;

	return *a > *b ? 1 : 0;
}

TEST_GROUP(merge_sort);

TEST_SETUP(merge_sort)
{
}

TEST_TEAR_DOWN(merge_sort)
{
}

TEST(merge_sort, SortTwoArray)
{
	int a[] = {2 ,3, 4};
	merge_sort(a, 3, sizeof(int), &compare);

	TEST_FAIL_MESSAGE("start here");
}

