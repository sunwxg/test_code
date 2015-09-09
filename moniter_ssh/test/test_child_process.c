#include "unity_fixture.h"
#include "child_process.c"


TEST_GROUP(child_process);

TEST_SETUP(child_process)
{
}

TEST_TEAR_DOWN(child_process)
{
}

TEST(child_process, child_process)
{
	child_process();
}

