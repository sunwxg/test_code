#include "unity_fixture.h"

static void runAllTests(void)
{
    RUN_TEST_GROUP(insertion_sort);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}

