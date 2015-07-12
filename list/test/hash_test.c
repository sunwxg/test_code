#include "unity_fixture.h"
#include "hash.h"
#include "hash.c"

static int h_key(const void *key)
{
	return 0;
}

static int match(const void *data1, const void *data2)
{
	const int *a = data1;
	const int *b = data2;
	return (*a == *b) ? 1 : 0;
}

static HASH h;

TEST_GROUP(hash_test);

TEST_SETUP(hash_test)
{
	hash_table_init(&h, 10, &h_key, &match);
}

TEST_TEAR_DOWN(hash_test)
{
	hash_table_destory(&h);
}

TEST(hash_test, hash_tableIsEmpty)
{
	TEST_ASSERT_EQUAL_INT(1, hash_isEmpty(&h));
	
	h.size = 1;
	TEST_ASSERT_EQUAL_INT(0, hash_isEmpty(&h));
	h.size = 0;
}

TEST(hash_test, hash_init)
{
	TEST_ASSERT_EQUAL_INT(0, hash_size(&h));
}

TEST(hash_test, hash_insertOneDataSizeEqualOne)
{
	int d1;
	hash_table_insert(&h, (void *)&d1);

	TEST_ASSERT_EQUAL_INT(1, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_insertOneDataValue)
{
	int d1 = 1;
	hash_table_insert(&h, (void *)&d1);

	TEST_ASSERT_EQUAL_INT(1, *(int *)(h.table[0].head->data));

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_insertTwoDataValue)
{
	int d1 = 1;
	int d2 = 2;
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	TEST_ASSERT_EQUAL_INT(2, *(int *)(h.table[0].head->data));
	TEST_ASSERT_EQUAL_INT(1, *(int *)(h.table[0].head->next->data));

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}

TEST(hash_test, hash_insertTwoSameData)
{
	int d1 = 1;
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d1);

	TEST_ASSERT_EQUAL_INT(1, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_removeNonDataHashSize)
{
	int d1 = 2;
	int d2 = 3;
	int temp = 1;
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	hash_table_remove(&h, (void *)&temp);

	TEST_ASSERT_EQUAL_INT(2, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}

TEST(hash_test, hash_removeNonDataReturnValueNULL)
{
	int d1 = 2;
	int d2 = 3;
	int temp = 1;
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	void *result = hash_table_remove(&h, (void *)&temp);

	TEST_ASSERT_EQUAL_PTR(NULL, result);

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}
