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


}  // namespace singl_ll_tests



cute::suite make_suite_TestSuite_SingleLinkedList(){
	cute::suite s;

	s.push_back(CUTE(singl_ll_tests::Append_EmptyList_NoExceptions));
	s.push_back(CUTE(singl_ll_tests::Append_EmptyList_ItemInSlotOne));
	s.push_back(CUTE(singl_ll_tests::Append_NotEmptyNotFull_ItemInSlotTwo));

	return s;
}



