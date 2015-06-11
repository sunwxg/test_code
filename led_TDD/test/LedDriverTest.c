#include "unity.h"
#include <setjmp.h>
#include <stdio.h>


void setUp(void)
{
}

void tearDown(void)
{
}

void LedsOffAfterCreate(void)
{
	TEST_FAIL_MESSAGE("Start Here");
}


void resetTest(void)
{
  tearDown();
  setUp();
}

int main(int argc, char * argv[])
{
	UnityBegin("test/LedDriverTest.c");

	RUN_TEST(LedsOffAfterCreate);
	
	UnityEnd();
	return 0;
}
