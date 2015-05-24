///////////////////////////////////////////////////////////
//  Pointer_LinkedList.h
//  Implementation of the Class Pointer_LinkedList
//  Created on:      19-May-2015 7:28:23 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_)
#define EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_

#include "LinkedList.h"

struct node {
    int x;
};

template<class T>
class Pointer_LinkedList : public LinkedList<T>
{
    
private:
	node* Front;
	node* End;

};
#endif // !defined(EA_1EDF8CE0_9497_4c76_9281_6D4347B57A6B__INCLUDED_)
