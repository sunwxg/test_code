#include "unity_fixture.h"
#include "stdlib.h"
#include "sort.h"
#include "quick_sort.c"

static int compare(void *key1, void *key2)
{
	int *a = (int *)key1;
	int *b = (int *)key2;

	return *a > *b ? 1 : 0;
}

TEST_GROUP(quick_sort);

TEST_SETUP(quick_sort)
{
}

TEST_TEAR_DOWN(quick_sort)
{
}

TEST(quick_sort, SelectPivot)
{
	int a[] = {10, 6, 9, 4};
	int t = partition(a, sizeof(int), 0, 3, &compare);

	TEST_ASSERT_NOT_EQUAL(-1, t)
	TEST_ASSERT_EQUAL_INT(6, a[0]);

}

TEST(quick_sort, OneSort)
{
	int a[] = {10};
	quick_sort(a, sizeof(int), 0, 0, compare);

	TEST_ASSERT_EQUAL_INT(10, a[0]);
}

TEST(quick_sort, TwoSort)
{
	int a[] = {10, 6};
	quick_sort(a, sizeof(int), 0, 1, compare);

	TEST_ASSERT_EQUAL_INT(6, a[0]);
	TEST_ASSERT_EQUAL_INT(10, a[1]);
}

TEST(quick_sort, ThreeSort)
{
	int a[] = {10, 6, 9};
	quick_sort(a, sizeof(int), 0, 2, compare);

	TEST_ASSERT_EQUAL_INT(6, a[0]);
	TEST_ASSERT_EQUAL_INT(9, a[1]);
	TEST_ASSERT_EQUAL_INT(10, a[2]);
}

TEST(quick_sort, AnySort)
{
	int a[] = {10, 6, 9, 15, 15, 100, 50};
	quick_sort(a, sizeof(int), 0, 6, compare);

	TEST_ASSERT_EQUAL_INT(6, a[0]);
	TEST_ASSERT_EQUAL_INT(9, a[1]);
	TEST_ASSERT_EQUAL_INT(10, a[2]);
	TEST_ASSERT_EQUAL_INT(15, a[3]);
	TEST_ASSERT_EQUAL_INT(15, a[4]);
	TEST_ASSERT_EQUAL_INT(50, a[5]);
	TEST_ASSERT_EQUAL_INT(100, a[6]);
}

