///////////////////////////////////////////////////////////
//  Doubly_LinkedList.h
//  Implementation of the Class Doubly_LinkedList
//  Created on:      19-May-2015 7:28:24 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_8C992860_B6FA_4199_9115_D83DEBFB6B7A__INCLUDED_)
#define EA_8C992860_B6FA_4199_9115_D83DEBFB6B7A__INCLUDED_

#include "Pointer_LinkedList.h"

template<class T>
class Doubly_LinkedList : public Pointer_LinkedList<T>
{

public:
	Doubly_LinkedList();
	virtual ~Doubly_LinkedList();

	virtual void Append(T const &item);
	virtual void Prepend(T const &item);
	virtual const void Get(int index);
	virtual void Remove(int index);

};
#endif // !defined(EA_8C992860_B6FA_4199_9115_D83DEBFB6B7A__INCLUDED_)
