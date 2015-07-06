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

TEST(heap_sort, ShiftUpTwo)
{
	int a[] = {1, 3};
	shift_up(a, 2, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, a[0]);
}

TEST(heap_sort, ShiftUpThree)
{
	int a[] = {3, 1, 4};
	shift_up(a, 3, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(4, a[0]);
}

TEST(heap_sort, ShiftUpAny)
{
	int a[] = {3, 1, 4, 10, 13, 20, 14};

	shift_up(a, 7, sizeof(int), &compare);
	TEST_ASSERT_EQUAL_INT(14, a[0]);
	shift_up(a, 6, sizeof(int), &compare);
	TEST_ASSERT_EQUAL_INT(20, a[0]);
	shift_up(a, 5, sizeof(int), &compare);
	TEST_ASSERT_EQUAL_INT(20, a[0]);
	TEST_ASSERT_EQUAL_INT(13, a[1]);
}

TEST(heap_sort, HeapifyUpTwoArray)
{
	int a[] = {1, 3};
	heapify_up(a, 2, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, a[0]);
	TEST_ASSERT_EQUAL_INT(1, a[1]);
}

TEST(heap_sort, HeapifyUpAnyArray)
{
	int a[] = {3, 1, 4, 10, 13, 20, 14};
	heapify_up(a, 7, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(20, a[0]);
	TEST_ASSERT_EQUAL_INT(10, a[1]);
	TEST_ASSERT_EQUAL_INT(14, a[2]);
	TEST_ASSERT_EQUAL_INT(1, a[3]);
	TEST_ASSERT_EQUAL_INT(4, a[4]);
	TEST_ASSERT_EQUAL_INT(3, a[5]);
	TEST_ASSERT_EQUAL_INT(13, a[6]);
}

TEST(heap_sort, ShiftdownTwoArray)
{
	int a[] = {1, 3};
	shift_down(a, 0, 1, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, a[0]);
	TEST_ASSERT_EQUAL_INT(1, a[1]);
}

TEST(heap_sort, ShiftdownThreeArray)
{
	int a[] = {10, 9, 14};
	shift_down(a, 0, 2, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(14, a[0]);
	TEST_ASSERT_EQUAL_INT(9, a[1]);
	TEST_ASSERT_EQUAL_INT(10, a[2]);
}

TEST(heap_sort, ShiftdownAnyArray)
{
	int a[] = {13, 14, 10, 1, 3, 4};
	shift_down(a, 0, 5, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(14, a[0]);
	TEST_ASSERT_EQUAL_INT(13, a[1]);
	TEST_ASSERT_EQUAL_INT(10, a[2]);
	TEST_ASSERT_EQUAL_INT(1, a[3]);
	TEST_ASSERT_EQUAL_INT(3, a[4]);
	TEST_ASSERT_EQUAL_INT(4, a[5]);
}

TEST(heap_sort, HeapsortDTwoArray)
{
	int a[] = {1, 3};
	heap_sort_d(a, 2, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
}

TEST(heap_sort, HeapsortDAnyArray)
{
	int a[] = {3, 1, 4, 10, 13, 20, 14};
	heap_sort_d(a, 7, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(4, a[2]);
	TEST_ASSERT_EQUAL_INT(10, a[3]);
	TEST_ASSERT_EQUAL_INT(13, a[4]);
	TEST_ASSERT_EQUAL_INT(14, a[5]);
	TEST_ASSERT_EQUAL_INT(20, a[6]);
}

TEST(heap_sort, HeapsortUAnyArray)
{
	int a[] = {3, 1, 4, 10, 13, 20, 14};
	heap_sort_u(a, 7, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(4, a[2]);
	TEST_ASSERT_EQUAL_INT(10, a[3]);
	TEST_ASSERT_EQUAL_INT(13, a[4]);
	TEST_ASSERT_EQUAL_INT(14, a[5]);
	TEST_ASSERT_EQUAL_INT(20, a[6]);
}

