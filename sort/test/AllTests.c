#include "unity_fixture.h"

TEST_GROUP_RUNNER(heap_sort)
{
	RUN_TEST_CASE(heap_sort,ShiftUpTwo);
	RUN_TEST_CASE(heap_sort,ShiftUpThree);
	RUN_TEST_CASE(heap_sort,ShiftUpAny);
	RUN_TEST_CASE(heap_sort,HeapifyUpTwoArray);
	RUN_TEST_CASE(heap_sort,HeapifyUpAnyArray);
	RUN_TEST_CASE(heap_sort,ShiftdownTwoArray);
	RUN_TEST_CASE(heap_sort,ShiftdownThreeArray);
	RUN_TEST_CASE(heap_sort,ShiftdownAnyArray);
	RUN_TEST_CASE(heap_sort,HeapsortDTwoArray);
	RUN_TEST_CASE(heap_sort,HeapsortDAnyArray);
	RUN_TEST_CASE(heap_sort,HeapsortUAnyArray);
}

TEST_GROUP_RUNNER(insertion_sort)
{
	RUN_TEST_CASE(insertion_sort,SortTwoArray);
	RUN_TEST_CASE(insertion_sort,SortThreeArray);
	RUN_TEST_CASE(insertion_sort,SortAnyArray);
}

TEST_GROUP_RUNNER(quick_sort)
{
	RUN_TEST_CASE(quick_sort,SelectPivot);
	RUN_TEST_CASE(quick_sort,OneSort);
	RUN_TEST_CASE(quick_sort,TwoSort);
	RUN_TEST_CASE(quick_sort,ThreeSort);
	RUN_TEST_CASE(quick_sort,AnySort);
}

static void runAllTests(void)
{
	RUN_TEST_GROUP(heap_sort);
	RUN_TEST_GROUP(insertion_sort);
	RUN_TEST_GROUP(quick_sort);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
