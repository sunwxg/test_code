#include "unity_fixture.h"
#include "hash.h"
#include "hash.c"

struct dict {
	int key;
	int value;
};

static int h_key(const void *data)
{
	const struct dict *d = data;
	return d->key;
}

static int match(const void *data1, const void *data2)
{
	const struct dict *a = data1;
	const struct dict *b = data2;
	return (a->key == b->key) ? 1 : 0;
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
	struct dict d1 = {1, 1};
	hash_table_insert(&h, (void *)&d1);

	TEST_ASSERT_EQUAL_INT(1, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_insertOneDataValue)
{
	struct dict d1 = {1, 1};
	hash_table_insert(&h, (void *)&d1);

	int value = ((struct dict *)(h.table[1].head->data))->value;
	TEST_ASSERT_EQUAL_INT(1, value);

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_insertTwoDataValue)
{
	struct dict d1 = {1, 1};
	struct dict d2 = {11, 2};
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	int value1 = ((struct dict *)(h.table[1].head->data))->value;
	int value2 = ((struct dict *)(h.table[1].head->next->data))->value;
	TEST_ASSERT_EQUAL_INT(2, value1);
	TEST_ASSERT_EQUAL_INT(1, value2);

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}

TEST(hash_test, hash_insertTwoSameData)
{
	struct dict d1 = {1, 1};
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d1);

	TEST_ASSERT_EQUAL_INT(1, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
}

TEST(hash_test, hash_removeNonDataHashSize)
{
	struct dict d1 = {1, 1};
	struct dict d2 = {11, 2};
	struct dict temp = {31, 3};
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	hash_table_remove(&h, (void *)&temp);

	TEST_ASSERT_EQUAL_INT(2, hash_size(&h));

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}

TEST(hash_test, hash_removeNonDataReturnValueNULL)
{
	struct dict d1 = {1, 1};
	struct dict d2 = {21, 2};
	struct dict temp = {31, 3};
	hash_table_insert(&h, (void *)&d1);
	hash_table_insert(&h, (void *)&d2);

	void *result = hash_table_remove(&h, (void *)&temp);

	TEST_ASSERT_EQUAL_PTR(NULL, result);

	hash_table_remove(&h, (void *)&d1);
	hash_table_remove(&h, (void *)&d2);
}

