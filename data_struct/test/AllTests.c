// File is generated automatically. Don't edit it.

#include "unity_fixture.h"

TEST_GROUP_RUNNER(bi_search_tree_test)
{
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeInit);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeInsertRight);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeInsertLeft);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeSearch);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeMin);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeRemoveNonChild);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeRemoveLeftChild);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeRemoveRightChild);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeRemoveRightAnyChild);
	RUN_TEST_CASE(bi_search_tree_test,BiSearchTreeRemoveRightAnyChild2);
}

TEST_GROUP_RUNNER(bitree_find_test)
{
	RUN_TEST_CASE(bitree_find_test,bitree_find_preorder);
	RUN_TEST_CASE(bitree_find_test,bitree_find_in);
	RUN_TEST_CASE(bitree_find_test,bitree_find_post);
	RUN_TEST_CASE(bitree_find_test,bitree_find);
}

TEST_GROUP_RUNNER(bitree_test)
{
	RUN_TEST_CASE(bitree_test,bitree_insert_leftTreeSize);
	RUN_TEST_CASE(bitree_test,bitree_insert_leftDataValue);
	RUN_TEST_CASE(bitree_test,bitree_insert_rightTreeSize);
	RUN_TEST_CASE(bitree_test,bitree_insert_rightDataValue);
	RUN_TEST_CASE(bitree_test,bitree_remove_leftNonData);
	RUN_TEST_CASE(bitree_test,bitree_remove_rightNonData);
}

TEST_GROUP_RUNNER(hash_test)
{
	RUN_TEST_CASE(hash_test,hash_tableIsEmpty);
	RUN_TEST_CASE(hash_test,hash_init);
	RUN_TEST_CASE(hash_test,hash_insertOneDataSizeEqualOne);
	RUN_TEST_CASE(hash_test,hash_insertOneDataValue);
	RUN_TEST_CASE(hash_test,hash_insertTwoDataValue);
	RUN_TEST_CASE(hash_test,hash_insertTwoSameData);
	RUN_TEST_CASE(hash_test,hash_removeNonDataHashSize);
	RUN_TEST_CASE(hash_test,hash_removeNonDataReturnValueNULL);
	RUN_TEST_CASE(hash_test,free_fun);
}

TEST_GROUP_RUNNER(list_test)
{
	RUN_TEST_CASE(list_test,list_init);
	RUN_TEST_CASE(list_test,list_addOneElementSizeEqualOne);
	RUN_TEST_CASE(list_test,list_addOneElementNextPointer);
	RUN_TEST_CASE(list_test,list_addOneElementListHead);
	RUN_TEST_CASE(list_test,list_addOneElementListTail);
	RUN_TEST_CASE(list_test,list_RemoveLastOneElementSizeEqualZero);
	RUN_TEST_CASE(list_test,list_RemoveLastOneHeadPointer);
	RUN_TEST_CASE(list_test,list_RemoveLastOneTailPointer);
	RUN_TEST_CASE(list_test,list_RemoveOneReturnData);
	RUN_TEST_CASE(list_test,list_AddTwoElementSize);
	RUN_TEST_CASE(list_test,list_isEmpty);
	RUN_TEST_CASE(list_test,list_RemoveEmptyList);
	RUN_TEST_CASE(list_test,list_next);
	RUN_TEST_CASE(list_test,listAddNextPrePointer);
	RUN_TEST_CASE(list_test,list_rm_elementLastOne);
	RUN_TEST_CASE(list_test,list_rm_elementTailSizeValue);
	RUN_TEST_CASE(list_test,list_rm_elementReturnData);
}

static void runAllTests(void)
{
	RUN_TEST_GROUP(bi_search_tree_test);
	RUN_TEST_GROUP(bitree_find_test);
	RUN_TEST_GROUP(bitree_test);
	RUN_TEST_GROUP(hash_test);
	RUN_TEST_GROUP(list_test);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
