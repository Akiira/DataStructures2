#include "cute.h"
#include "TestSuite_SingleLinkedList.h"

#include "../Pointer_LinkedList.h"
#include "../Single_LinkedList.hpp"

namespace singl_ll_tests {
	void Append_EmptyList_NoExceptions() {
		Single_LinkedList<char> fll;
		fll.Append('A');
		ASSERT(true);
	}

	void Append_EmptyList_ItemInSlotOne() {
		Single_LinkedList<char> fll;
		fll.Append('A');
		ASSERT(fll.Get(0) == 'A');
	}

	void Append_NotEmptyNotFull_ItemInSlotTwo() {
		Single_LinkedList<char> fll;
		fll.Append('A');
		fll.Append('B');
		ASSERT(fll.Get(1) == 'B');
	}


	void Prepend_EmptyList_NoExceptions() {
		Single_LinkedList<char> fll;
	    fll.Prepend('A');
	    ASSERT(true);
	}

	void Prepend_EmptyList_ItemInSlotOne() {
		Single_LinkedList<char> fll;
	    fll.Prepend('A');
	    ASSERT(fll.Get(0) == 'A');
	}

	void Prepend_NotEmpty_ItemInSlotOne() {
		Single_LinkedList<char> fll;
	    fll.Prepend('B');
	    fll.Prepend('A');
	    ASSERT(fll.Get(0) == 'A');
	}

	void Remove_Empty_EmptyException(){
		Single_LinkedList<char> fll;
		ASSERT_THROWS(fll.Remove(0), LinkedListException);
	}

	void Remove_OneElement_SizeIsZero(){
		Single_LinkedList<char> fll;
		fll.Append('A');
		fll.Remove(0);

		ASSERT(fll.Size() == 0);
	}

	void Remove_FrontRemoved_ElementsShiftedOver(){
		Single_LinkedList<char> fll;

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
		Single_LinkedList<char> fll;
		ASSERT_THROWS(fll.Remove(-1), LinkedListException);

		fll.Append('A');
		ASSERT_THROWS(fll.Remove(-1), LinkedListException);

		fll.Append('B');
		ASSERT_THROWS(fll.Remove(-1), LinkedListException);
	}

}  // namespace singl_ll_tests



cute::suite make_suite_TestSuite_SingleLinkedList(){
	cute::suite s;

	s.push_back(CUTE(singl_ll_tests::Append_EmptyList_NoExceptions));
	s.push_back(CUTE(singl_ll_tests::Append_EmptyList_ItemInSlotOne));
	s.push_back(CUTE(singl_ll_tests::Append_NotEmptyNotFull_ItemInSlotTwo));

	s.push_back(CUTE(singl_ll_tests::Prepend_EmptyList_NoExceptions));
	s.push_back(CUTE(singl_ll_tests::Prepend_EmptyList_ItemInSlotOne));
	s.push_back(CUTE(singl_ll_tests::Prepend_NotEmpty_ItemInSlotOne));

	s.push_back(CUTE(singl_ll_tests::Remove_Empty_EmptyException));
	s.push_back(CUTE(singl_ll_tests::Remove_OneElement_SizeIsZero));
	s.push_back(CUTE(singl_ll_tests::Remove_FrontRemoved_ElementsShiftedOver));
	s.push_back(CUTE(singl_ll_tests::Remove_NegativeIndex_BadIndexEception));

	return s;
}



