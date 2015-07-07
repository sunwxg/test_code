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

TEST_GROUP_RUNNER(merge_sort)
{
	RUN_TEST_CASE(merge_sort,CopyDataArray);
	RUN_TEST_CASE(merge_sort,merget2dThreeArray);
	RUN_TEST_CASE(merge_sort,merget2dThreeArray2);
	RUN_TEST_CASE(merge_sort,merget2dThreeArray3);
	RUN_TEST_CASE(merge_sort,merget2dFiveArray);
	RUN_TEST_CASE(merge_sort,CopyArrayThreeArray);
	RUN_TEST_CASE(merge_sort,CopyArrayFourArray);
	RUN_TEST_CASE(merge_sort,M_split_T2DFourArray);
	RUN_TEST_CASE(merge_sort,M_split_T2DSenvenArray);
	RUN_TEST_CASE(merge_sort,MergeSortT2DSenvenArray);
	RUN_TEST_CASE(merge_sort,m_split_sort_d2tThreeArray);
	RUN_TEST_CASE(merge_sort,m_split_sort_d2tFourArray);
	RUN_TEST_CASE(merge_sort,MergeSortD2TSenvenArray);
	RUN_TEST_CASE(merge_sort,MergeSortD2TAnyArray);
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
	RUN_TEST_GROUP(merge_sort);
	RUN_TEST_GROUP(quick_sort);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
