#include "unity_fixture.h"


TEST_GROUP(LedDriverTest);

TEST_SETUP(LedDriverTest)
{
}

TEST_TEAR_DOWN(LedDriverTest)
{
}

TEST(LedDriverTest, LedsOffAfterCreate)
{
    TEST_FAIL_MESSAGE("start here");
}

TEST_GROUP_RUNNER(LedDriverTest)
{
    RUN_TEST_CASE(LedDriverTest, LedsOffAfterCreate);
}
