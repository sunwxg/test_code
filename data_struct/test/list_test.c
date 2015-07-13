#include "unity_fixture.h"
#include "list.h"
#include "list.c"

static LIST list;
static int *d1, *d2;

TEST_GROUP(list_test);

TEST_SETUP(list_test)
{
	list_init(&list);
	d1 = calloc(1, sizeof(int));
	d2 = calloc(1, sizeof(int));
	*d1 = 10;
	*d2 = 20;
}

TEST_TEAR_DOWN(list_test)
{
	free(d1);
	free(d2);
}

TEST(list_test, list_init)
{
	TEST_ASSERT_EQUAL_INT(0, list_size(&list));
}

TEST(list_test, list_addOneElementSizeEqualOne)
{
	list_add_next(&list, d1);

	TEST_ASSERT_EQUAL_INT(1, list_size(&list));

	list_rm_next(&list);
}

TEST(list_test, list_addOneElementNextPointer)
{
	list_add_next(&list, d1);

	TEST_ASSERT_EQUAL_PTR(list_head(&list)->next, NULL);
	
	list_rm_next(&list);
}

TEST(list_test, list_addOneElementListHead)
{
	list_add_next(&list, d1);

	TEST_ASSERT_EQUAL_PTR(d1, list_head(&list)->data);
	
	list_rm_next(&list);
}

TEST(list_test, list_addOneElementListTail)
{
	list_add_next(&list, d1);

	TEST_ASSERT_EQUAL_PTR(d1, list_tail(&list)->data);
	
	list_rm_next(&list);
}

TEST(list_test, list_RemoveLastOneElementSizeEqualZero)
{
	list_add_next(&list, d1);

	list_rm_next(&list);
	TEST_ASSERT_EQUAL_INT(0, list_size(&list));
}

TEST(list_test, list_RemoveLastOneHeadPointer)
{
	list_add_next(&list, d1);
	list_rm_next(&list);

	TEST_ASSERT_EQUAL_PTR(NULL, list_head(&list));
	
}

TEST(list_test, list_RemoveLastOneTailPointer)
{
	list_add_next(&list, d1);
	list_rm_next(&list);

	TEST_ASSERT_EQUAL_PTR(NULL, list_tail(&list));
	
}

TEST(list_test, list_RemoveOneReturnData)
{
	list_add_next(&list, d1);

	int *d3 = list_rm_next(&list);
	TEST_ASSERT_EQUAL_PTR(d3, d1);
	
}

TEST(list_test, list_AddTwoElementSize)
{
	list_add_next(&list, d1);
	list_add_next(&list, d2);

	TEST_ASSERT_EQUAL_INT(2, list_size(&list));
	
	list_rm_next(&list);
	list_rm_next(&list);
}

TEST(list_test, list_isEmpty)
{

	TEST_ASSERT_EQUAL_INT(1, list_isEmpty(&list));

	list_add_next(&list, d1);
	TEST_ASSERT_EQUAL_INT(0, list_isEmpty(&list));

	list_rm_next(&list);
}

TEST(list_test, list_RemoveEmptyList)
{
	TEST_ASSERT_EQUAL_PTR(NULL,list_rm_next(&list));
}

TEST(list_test, list_next)
{
	list_add_next(&list, d1);
	list_add_next(&list, d2);

	TEST_ASSERT_EQUAL_PTR(d1, list_next(&list)->data);
	
	list_rm_next(&list);
	list_rm_next(&list);
}

TEST(list_test, listAddNextPrePointer)
{
	list_add_next(&list, d1);
	list_add_next(&list, d2);

	TEST_ASSERT_EQUAL_PTR(d2, list_head(&list)->next->pre->data);

	list_rm_next(&list);
	list_rm_next(&list);
}

TEST(list_test, list_rm_elementLastOne)
{
	list_add_next(&list, d1);

	list_rm_element(&list, list_head(&list));

	TEST_ASSERT_EQUAL_INT(0, list_size(&list));

}

TEST(list_test, list_rm_elementTailSizeValue)
{
	list_add_next(&list, d1);
	list_add_next(&list, d2);
	list_add_next(&list, d2);

	list_rm_element(&list, list_tail(&list));

	TEST_ASSERT_EQUAL_INT(2, list_size(&list));

	list_rm_next(&list);
	list_rm_next(&list);
}

TEST(list_test, list_rm_elementReturnData)
{
	list_add_next(&list, d1);
	list_add_next(&list, d2);
	list_add_next(&list, d1);

	void *temp = list_rm_element(&list, list_head(&list)->next);

	TEST_ASSERT_EQUAL_PTR(d2, temp);

	list_rm_next(&list);
	list_rm_next(&list);
}
