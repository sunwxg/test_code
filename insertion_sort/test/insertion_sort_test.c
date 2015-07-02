#include "unity_fixture.h"

//static int array[] = {1 , 2};

TEST_GROUP(insertion_sort);

TEST_SETUP(insertion_sort)
{
}

TEST_TEAR_DOWN(insertion_sort)
{
}

TEST(insertion_sort, SortTwoArray)
{
	TEST_ASSERT_MESSAGE("start here");
}

TEST_GROUP_RUNNER(insertion_sort)
{
    RUN_TEST_CASE(insertion_sort, SortTwoArray);
}
