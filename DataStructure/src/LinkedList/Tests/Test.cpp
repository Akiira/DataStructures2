#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "TestSuite_FixedLinkedList.h"
#include "TestSuite_SingleLinkedList.h"

#include <exception>
#include <iostream>

using namespace std;

void runSuite(int argc, char const *argv[]){
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<>  > lis(xmlfile.out);
	cute::suite s=make_suite_TestSuite_FixedLinkedList();
	cute::makeRunner(lis,argc,argv)(s, "TestSuite_FixedLinkedList");

	cute::suite s2=make_suite_TestSuite_SingleLinkedList();
	cute::makeRunner(lis,argc,argv)(s2, "TestSuite_SingleLinkedList");
}

int main(int argc, char const *argv[]){
	runSuite(argc,argv);
}



