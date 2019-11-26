#include <iostream>
#include "LinkedList.hpp"
#include "Tests.hpp"

int main()
{
	TEST_CLASS test;
	int testsPassed = 0;
	test.BackwardIteratorAssignment_BackwardBeginShouldReturnLast();
	testsPassed += 1;
	test.BackwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues();
	testsPassed += 1;
	test.BackwardIteratorBeginTest_LastShouldEqualOperatorStar();
	testsPassed += 1;
	test.BackwardIteratorEndTest_BackwardIteratorShouldBeDone();
	testsPassed += 1;
	test.BackwardIteratorMoveNext_ShouldMoveNext();
	testsPassed += 1;
	test.BackwardIteratorReset_ShouldReset();
	testsPassed += 1;
	test.ForwardIteratorAssignment_ForwardBeginShouldReturnFirst();
	testsPassed += 1;
	test.ForwardIteratorAssignmentOperator_ShouldAssign();
	testsPassed += 1;
	test.ForwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues();
	testsPassed += 1;
	test.ForwardIteratorBeginTest_FirstShoulEqualOperatorStar();
	testsPassed += 1;
	test.ForwardIteratorEndTest_ForwardIteratorShouldBeDone();
	testsPassed += 1;
	test.ForwardIteratorMoveNext_ShouldMoveNext();
	testsPassed += 1;
	test.ForwardIteratorReset();
	testsPassed += 1;
	test.PreAndPostFixOperations_ShouldIncrementPreAndPost();
	testsPassed += 1;
	std::cout << testsPassed << " tests passed sucessfully\n";
}