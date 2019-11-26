#pragma once
#ifndef TESTS_H
#define TESTS_H
#include <assert.h>
#include "LinkedList.hpp"
class TEST_CLASS
{
public:
	TEST_CLASS() {};
	void ForwardIteratorAssignmentOperator_ShouldAssign()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		auto forward_iterator_1 = list.ForwardBegin();
		auto forward_iterator_2 = LinkedList<size_t>::ForwardIterator();
		forward_iterator_2 = forward_iterator_1;

		assert(*forward_iterator_2 == *forward_iterator_1);
	}

	void ForwardIteratorBeginTest_FirstShoulEqualOperatorStar()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		const auto forward_iterator = list.ForwardBegin();

		assert(list.First() == *forward_iterator);
	}

	void BackwardIteratorBeginTest_LastShouldEqualOperatorStar()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		const auto backward_iterator = list.BackwardBegin();

		assert(list.Last() == *backward_iterator);
	}

	void ForwardIteratorEndTest_ForwardIteratorShouldBeDone()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		auto forward_iterator = list.ForwardEnd();

		assert(forward_iterator.Done());
	}

	void BackwardIteratorEndTest_BackwardIteratorShouldBeDone()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		auto backward_iterator = list.BackwardEnd();

		assert(backward_iterator.Done());
	}

	void ForwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues()
	{
		size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
		size_t i = 0;

		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		for (auto forward_iterator = list.ForwardBegin(); forward_iterator != list.ForwardEnd(); ++forward_iterator)
			assert(values[i++] == *forward_iterator);
	}

	void BackwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues()
	{
		size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
		size_t i = 6;

		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		for (auto backward_iterator = list.BackwardBegin(); backward_iterator != list.BackwardEnd(); ++backward_iterator)
			assert(values[i--] == *backward_iterator);
	}

	void ForwardIteratorAssignment_ForwardBeginShouldReturnFirst()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i * 5);
		}

		const auto forward_iterator = list.ForwardBegin();

		assert(list.First() == *forward_iterator);
	}

	void BackwardIteratorAssignment_BackwardBeginShouldReturnLast()
	{
		LinkedList<size_t> list;

		for (size_t i = 0; i < 5; ++i)
		{
			list.Append(i);
		}

		const auto backward_iterator = list.BackwardBegin();

		assert(list.Last() == *backward_iterator);
	}

	void ForwardIteratorReset()
	{
		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		auto forward_iterator = list.ForwardBegin();

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				++forward_iterator;
			}

			forward_iterator.Reset();
		}

		assert(list.First() == *forward_iterator);
	}

	void BackwardIteratorReset_ShouldReset()
	{
		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		auto backward_iterator = list.BackwardBegin();

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				++backward_iterator;
			}

			backward_iterator.Reset();
		}

		assert(list.Last() == *backward_iterator);
	}

	void ForwardIteratorMoveNext_ShouldMoveNext()
	{
		size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
		size_t i = 0;

		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		auto forward_iterator = list.ForwardBegin();

		while (!forward_iterator.Done())
		{
			assert(values[i++] == *forward_iterator++);
		}
	}

	void BackwardIteratorMoveNext_ShouldMoveNext()
	{
		size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
		auto i = 6;

		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);
		list.Append(6);
		list.Append(7);

		auto backward_iterator = list.BackwardBegin();

		while (backward_iterator != list.BackwardEnd())
		{
			assert(values[i--] == *backward_iterator++);
		}
	}

	void PreAndPostFixOperations_ShouldIncrementPreAndPost()
	{
		size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };

		LinkedList<size_t> list;
		list.Append(1);
		list.Append(2);
		list.Append(3);
		list.Append(4);
		list.Append(5);

		auto forward_iterator = list.ForwardBegin();

		const auto current_value = *forward_iterator;
		assert(static_cast<size_t>(1) == current_value);

		const auto value_with_post_increment = *forward_iterator++;
		assert(static_cast<size_t>(1) == value_with_post_increment);

		const auto value_after_post_increment = *forward_iterator;
		assert(static_cast<size_t>(2) == value_after_post_increment);

		const auto value_with_pre_increment = *++forward_iterator;
		assert(static_cast<size_t>(3) == value_with_pre_increment);

		const auto value_after_pre_increment = *forward_iterator;
		assert(static_cast<size_t>(3) == value_after_pre_increment);
	}
};
#endif