#include "unity_fixture.h"

static int data = -1;

TEST_GROUP(test2);

TEST_SETUP(test2)
{
    data = 0;
}

TEST_TEAR_DOWN(test2)
{
    data = -1;
}

TEST(test2, test1)
{
    TEST_ASSERT_EQUAL_INT(0, data);
}

TEST(test2, test2)
{
    TEST_ASSERT_EQUAL_INT(0, data);
    data = 5;
}

TEST(test2, test3)
{
    data = 7;
    TEST_ASSERT_EQUAL_INT(7, data);
}

