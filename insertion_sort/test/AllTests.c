#include "unity_fixture.h"

static void runAllTests(void)
{
    RUN_TEST_GROUP(mygroup);
    RUN_TEST_GROUP(test2);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}

