#include "cute.h"
#include "TestSuite_FixedLinkedList.h"
#include "../Fixed_LinkedList.hpp"


void Append_EmptyList_NoExceptions() {
    Fixed_LinkedList<char> fll(2);
    fll.Append('A');
    ASSERT(true);
}

void Append_EmptyList_ItemInSlotOne() {
    Fixed_LinkedList<char> fll(2);
    fll.Append('A');
    ASSERT(fll.Get(0) == 'A');
}

void Append_NotEmptyNotFull_ItemInSlotTwo() {
    Fixed_LinkedList<char> fll(2);
    fll.Append('A');
    fll.Append('B');
    ASSERT(fll.Get(1) == 'B');
}

void Append_Full_FullException() {
    Fixed_LinkedList<char> fll(2);
    fll.Append('A');
    fll.Append('B');

    ASSERT_THROWS(fll.Append('C'), LinkedListException);
}

void Prepend_EmptyList_NoExceptions() {
    Fixed_LinkedList<char> fll(2);
    fll.Prepend('A');
    ASSERT(true);
}

void Prepend_EmptyList_ItemInSlotOne() {
    Fixed_LinkedList<char> fll(2);
    fll.Prepend('A');
    ASSERT(fll.Get(0) == 'A');
}

void Prepend_NotEmptyNotFull_ItemInSlotOne() {
    Fixed_LinkedList<char> fll(2);
    fll.Prepend('B');
    fll.Prepend('A');
    ASSERT(fll.Get(0) == 'A');
}

void Prepend_Full_FullException() {
    Fixed_LinkedList<char> fll(2);
    fll.Prepend('C');
    fll.Prepend('B');

    ASSERT_THROWS(fll.Prepend('A'), LinkedListException);
}

void Remove_Empty_EmptyException(){
	Fixed_LinkedList<char> fll(2);
	ASSERT_THROWS(fll.Remove(0), LinkedListException);
}

void Remove_OneElement_ElementRemoved(){
	Fixed_LinkedList<char> fll(2);
	fll.Append('A');
	fll.Remove(0);

	ASSERT(fll.Size() == 0);
}

void Remove_FrontRemoved_ElementsShiftedOver(){
	Fixed_LinkedList<char> fll(5);

	fll.Append('A');
	fll.Append('B');
	fll.Append('B');
	fll.Append('C');
	fll.Append('D');

	fll.Remove(2);

	ASSERT(fll.Get(0) == 'A');
	ASSERT(fll.Get(1) == 'B');
	ASSERT(fll.Get(2) == 'C');
	ASSERT(fll.Get(3) == 'D');
}

void Remove_NegativeIndex_BadIndexEception(){
	Fixed_LinkedList<char> fll(2);
	ASSERT_THROWS(fll.Remove(-1), LinkedListException);

	fll.Append('A');
	ASSERT_THROWS(fll.Remove(-1), LinkedListException);

	fll.Append('B');
	ASSERT_THROWS(fll.Remove(-1), LinkedListException);
}



cute::suite make_suite_TestSuite_FixedLinkedList(){
	cute::suite s;

	s.push_back(CUTE(Append_Full_FullException));
	s.push_back(CUTE(Append_EmptyList_ItemInSlotOne));
	s.push_back(CUTE(Append_EmptyList_NoExceptions));
	s.push_back(CUTE(Append_NotEmptyNotFull_ItemInSlotTwo));

	s.push_back(CUTE(Prepend_NotEmptyNotFull_ItemInSlotOne));
	s.push_back(CUTE(Prepend_Full_FullException));
	s.push_back(CUTE(Prepend_EmptyList_ItemInSlotOne));
	s.push_back(CUTE(Prepend_EmptyList_NoExceptions));

	s.push_back(CUTE(Remove_Empty_EmptyException));
	s.push_back(CUTE(Remove_OneElement_ElementRemoved));
	s.push_back(CUTE(Remove_FrontRemoved_ElementsShiftedOver));
	s.push_back(CUTE(Remove_NegativeIndex_BadIndexEception));

	return s;
}



