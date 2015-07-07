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

TEST(merge_sort, CopyDataArray)
{
	int a[] = {2, 3, 4};
	int b[] = {0, 0, 0};

	copy_data(0, 0, b, a, sizeof(int));
	TEST_ASSERT_EQUAL_INT(2, b[0]);

	copy_data(0, 2, b, a, sizeof(int));
	TEST_ASSERT_EQUAL_INT(4, b[0]);
}

TEST(merge_sort, merget2dThreeArray)
{
	int a[] = {3, 15, 4};
	int b[] = {0, 0, 0};
	merge(a, 0, 1, 2, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, b[0]);
	TEST_ASSERT_EQUAL_INT(4, b[1]);
	TEST_ASSERT_EQUAL_INT(15, b[2]);
	
}

TEST(merge_sort, merget2dThreeArray2)
{
	int a[] = {3, 15, 4};
	int b[] = {0, 0, 0};
	merge(a, 0, 1, 2, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, b[0]);
	TEST_ASSERT_EQUAL_INT(4, b[1]);
	TEST_ASSERT_EQUAL_INT(15, b[2]);
	
}

TEST(merge_sort, merget2dThreeArray3)
{
	int a[] = {16, 15};
	int b[] = {0, 0};
	merge(a, 0, 0, 1, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(15, b[0]);
	TEST_ASSERT_EQUAL_INT(16, b[1]);
	
}

TEST(merge_sort, merget2dFiveArray)
{
	int a[] = {3, 16, 8, 9, 10};
	int b[] = {0, 0, 0, 0, 0};
	merge(a, 0, 1, 4, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, b[0]);
	TEST_ASSERT_EQUAL_INT(8, b[1]);
	TEST_ASSERT_EQUAL_INT(9, b[2]);
	TEST_ASSERT_EQUAL_INT(10, b[3]);
	TEST_ASSERT_EQUAL_INT(16, b[4]);
	
}

TEST(merge_sort, CopyArrayThreeArray)
{
	int a[] = {3, 16, 8};
	int b[] = {0, 0, 0};
	copy_array(b, a, 0, 2, sizeof(int));

	TEST_ASSERT_EQUAL_INT(3, b[0]);
	TEST_ASSERT_EQUAL_INT(16, b[1]);
	TEST_ASSERT_EQUAL_INT(8, b[2]);
	
}

TEST(merge_sort, CopyArrayFourArray)
{
	int a[] = {3, 16, 8, 10};
	int b[] = {0, 0, 0, 0};
	copy_array(b, a, 2, 3, sizeof(int));

	TEST_ASSERT_EQUAL_INT(0, b[0]);
	TEST_ASSERT_EQUAL_INT(0, b[1]);
	TEST_ASSERT_EQUAL_INT(8, b[2]);
	TEST_ASSERT_EQUAL_INT(10, b[3]);
	
}

TEST(merge_sort, M_split_T2DFourArray)
{
	int a[] = {3, 16, 8, 10};
	int b[] = {0, 0, 0, 0};
	m_split_sort_t2d(a, 0, 3, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, a[0]);
	TEST_ASSERT_EQUAL_INT(8, a[1]);
	TEST_ASSERT_EQUAL_INT(10, a[2]);
	TEST_ASSERT_EQUAL_INT(16, a[3]);
	
}

TEST(merge_sort, M_split_T2DSenvenArray)
{
	int a[] = {50, 16, 8, 10, 20, 40, 30};
	int b[] = {0, 0, 0, 0, 0, 0, 0};
	m_split_sort_t2d(a, 0, 6, b, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(8, a[0]);
	TEST_ASSERT_EQUAL_INT(10, a[1]);
	TEST_ASSERT_EQUAL_INT(16, a[2]);
	TEST_ASSERT_EQUAL_INT(20, a[3]);
	TEST_ASSERT_EQUAL_INT(30, a[4]);
	TEST_ASSERT_EQUAL_INT(40, a[5]);
	TEST_ASSERT_EQUAL_INT(50, a[6]);
	
}

TEST(merge_sort, MergeSortT2DSenvenArray)
{
	int a[] = {5, 9, 8, 1, 4, 3, 6};
	merge_sort_t2d(a, 7, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(4, a[2]);
	TEST_ASSERT_EQUAL_INT(5, a[3]);
	TEST_ASSERT_EQUAL_INT(6, a[4]);
	TEST_ASSERT_EQUAL_INT(8, a[5]);
	TEST_ASSERT_EQUAL_INT(9, a[6]);
	
}

TEST(merge_sort, m_split_sort_d2tThreeArray)
{
	int a[] = {3, 6, 5};
	int b[] = {0, 0, 0};
	m_split_sort_d2t(a, b, 3, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(3, b[0]);
	TEST_ASSERT_EQUAL_INT(5, b[1]);
	TEST_ASSERT_EQUAL_INT(6, b[2]);
	
}

TEST(merge_sort, m_split_sort_d2tFourArray)
{
	int a[] = {3, 6, 5, 1};
	int b[] = {0, 0, 0, 0};
	m_split_sort_d2t(a, b, 4, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, b[0]);
	TEST_ASSERT_EQUAL_INT(3, b[1]);
	TEST_ASSERT_EQUAL_INT(5, b[2]);
	TEST_ASSERT_EQUAL_INT(6, b[3]);
	
}

TEST(merge_sort, MergeSortD2TSenvenArray)
{
	int a[] = {5, 9, 8, 1, 4, 3, 6};
	merge_sort_d2t(a, 7, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(3, a[1]);
	TEST_ASSERT_EQUAL_INT(4, a[2]);
	TEST_ASSERT_EQUAL_INT(5, a[3]);
	TEST_ASSERT_EQUAL_INT(6, a[4]);
	TEST_ASSERT_EQUAL_INT(8, a[5]);
	TEST_ASSERT_EQUAL_INT(9, a[6]);
	
}

TEST(merge_sort, MergeSortD2TAnyArray)
{
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	merge_sort_d2t(a, 9, sizeof(int), &compare);

	TEST_ASSERT_EQUAL_INT(1, a[0]);
	TEST_ASSERT_EQUAL_INT(2, a[1]);
	TEST_ASSERT_EQUAL_INT(3, a[2]);
	TEST_ASSERT_EQUAL_INT(4, a[3]);
	TEST_ASSERT_EQUAL_INT(5, a[4]);
	TEST_ASSERT_EQUAL_INT(6, a[5]);
	TEST_ASSERT_EQUAL_INT(7, a[6]);
	TEST_ASSERT_EQUAL_INT(8, a[7]);
	TEST_ASSERT_EQUAL_INT(9, a[8]);
}
