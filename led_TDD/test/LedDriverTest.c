#include "unity.h"

int state;

void setUp(void)
{
	state = 0;
}

void tearDown(void)
{
	state = 0;
}

void LedsOffAfterCreate(void)
{
	TEST_ASSERT_MESSAGE(state, "start");
//	TEST_FAIL_MESSAGE("Start Here");
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
