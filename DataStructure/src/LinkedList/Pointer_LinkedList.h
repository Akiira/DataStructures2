///////////////////////////////////////////////////////////
//  Pointer_LinkedList.h
//  Implementation of the Class Pointer_LinkedList
//  Created on:      19-May-2015 7:28:23 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_)
#define EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_

#include "LinkedList.h"

//Testing
#include <iostream>

template<class T>
struct node {
public:
    T x;
    node<T>* next;
    node<T>* last;

    node(T const &item) : node(item, nullptr, nullptr) { }
    node(T const &item, node<T>* next) : node(item, nullptr, next) { }
    node(T const &item, node<T>* last, node<T>* next) {
    	x = item;
    	this->last = last;
    	this->next = next;
    }

    node<T>* Next() const { return next; }
    node<T>* Last() const { return last; }
};

template<class T>
class Pointer_LinkedList : public LinkedList<T>
{
    
protected:
	node<T>* front;
	node<T>* end;

};
#endif // !defined(EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_)
