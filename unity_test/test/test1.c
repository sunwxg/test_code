#include "unity.h"
#include <setjmp.h>
#include <stdio.h>


void setUp(void)
{
}

void tearDown(void)
{
}

void test_IgnoredTest(void)
{
    TEST_IGNORE_MESSAGE("This Test Was Ignored On Purpose");
}

void test_AnotherIgnoredTest(void)
{
    TEST_IGNORE_MESSAGE("These Can Be Useful For Leaving Yourself Notes On What You Need To Do Yet");
}

void test_ThisFunctionHasNotBeenTested_NeedsToBeImplemented(void)
{
    TEST_IGNORE(); //Like This
}

char MessageBuffer[50];

void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


int main(void)
{
  UnityBegin("test/test1.c");

  RUN_TEST(test_IgnoredTest, 13);
  RUN_TEST(test_AnotherIgnoredTest, 18);
  RUN_TEST(test_ThisFunctionHasNotBeenTested_NeedsToBeImplemented, 23);

  UnityEnd();
  return 0;
}
