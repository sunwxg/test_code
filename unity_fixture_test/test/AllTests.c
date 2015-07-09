// File is generated automatically. Don't edit it.

#include "unity_fixture.h"

TEST_GROUP_RUNNER(test1)
{
	RUN_TEST_CASE(test1,test1);
	RUN_TEST_CASE(test1,test2);
	RUN_TEST_CASE(test1,test3);
}

TEST_GROUP_RUNNER(test2)
{
	RUN_TEST_CASE(test2,test1);
}

static void runAllTests(void)
{
	RUN_TEST_GROUP(test1);
	RUN_TEST_GROUP(test2);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
