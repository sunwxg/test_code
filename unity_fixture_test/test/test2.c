#include "unity_fixture.h"
#include "hello.h"

TEST_GROUP(test2);

TEST_SETUP(test2)
{
}

TEST_TEAR_DOWN(test2)
{
}

TEST(test2, test1)
{
    TEST_ASSERT_EQUAL_INT(1, hello());
}

