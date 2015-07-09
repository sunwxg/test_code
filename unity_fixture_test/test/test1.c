#include "unity_fixture.h"

static int data = -1;

TEST_GROUP(test1);

TEST_SETUP(test1)
{
    data = 0;
}

TEST_TEAR_DOWN(test1)
{
    data = -1;
}

TEST(test1, test1)
{
    TEST_ASSERT_EQUAL_INT(0, data);
}

TEST(test1, test2)
{
    TEST_ASSERT_EQUAL_INT(5, data);
}

TEST(test1, test3)
{
	TEST_IGNORE();
}

