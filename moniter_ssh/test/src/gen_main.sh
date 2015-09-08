#!/bin/bash

if [ -z "$FILTER" ]; then
	FILTER='.'
fi

cd test

echo "// File is generated automatically. Don't edit it."
echo ""
echo "#include \"unity_fixture.h\""
echo ""

test_group=$(grep ^TEST_GROUP\( *.c |cut -d '(' -f 2 |cut -d ')' -f 1 |grep "$FILTER")
test_case=$(grep ^TEST\( *.c |sed s/\ // |cut -d ':' -f 2)

for i in $test_group;
do
	echo "TEST_GROUP_RUNNER($i)"
	echo "{"
	test_case=$(grep ^TEST\($i *.c |sed s/\ // |cut -d ':' -f 2 |sed s/TEST/RUN_TEST_CASE/)
	for k in $test_case;
	do
		echo "	"$k";"
	done
	echo "}"
	echo ""
done

echo "static void runAllTests(void)"
echo "{"

for i in $test_group;
do
	echo "	RUN_TEST_GROUP("$i");";
done

echo "}"
echo ""

echo "int main(int argc, const char* argv[])"
echo "{"
echo "    return UnityMain(argc, argv, runAllTests);"
echo "}"

cd ..
