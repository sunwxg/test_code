#include "unity_fixture.h"
#include "sort.h"

static int compare(void *key1, void *key2)
{
	int *a = (int *)key1;
	int *b = (int *)key2;

	return *a > *b ? 1 : 0;
}

TEST_GROUP(insertion_sort);

TEST_SETUP(insertion_sort)
{
}

TEST_TEAR_DOWN(insertion_sort)
{
}

TEST(insertion_sort, SortTwoArray)
{
	int a[] = {3, 2};
	insert_sort((void *)a, 2, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(2, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);

}

TEST(insertion_sort, SortThreeArray)
{
	int a[] = {3, 5, 2};
	insert_sort((void *)a, 3, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(2, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(5, a[2]);

}

TEST(insertion_sort, SortAnyArray)
{
	int a[] = {3, 5, 2, 10, 9, 7};
	insert_sort((void *)a, 6, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(2, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(5, a[2]);
	TEST_ASSERT_EQUAL_INT(7, a[3]);
	TEST_ASSERT_EQUAL_INT(9, a[4]);
	TEST_ASSERT_EQUAL_INT(10, a[5]);

}

