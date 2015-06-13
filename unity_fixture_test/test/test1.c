#include "unity_fixture.h"

static int data = -1;

TEST_GROUP(mygroup);

TEST_SETUP(mygroup)
{
    data = 0;
}

TEST_TEAR_DOWN(mygroup)
{
    data = -1;
}

TEST(mygroup, test1)
{
    TEST_ASSERT_EQUAL_INT(0, data);
}

TEST(mygroup, test2)
{
    TEST_ASSERT_EQUAL_INT(0, data);
    data = 5;
}

TEST(mygroup, test3)
{
    data = 7;
    TEST_ASSERT_EQUAL_INT(7, data);
}

TEST_GROUP_RUNNER(mygroup)
{
    RUN_TEST_CASE(mygroup, test1);
    RUN_TEST_CASE(mygroup, test2);
    RUN_TEST_CASE(mygroup, test3);
}