///////////////////////////////////////////////////////////
//  Single_LinkedList.h
//  Implementation of the Class Single_LinkedList
//  Created on:      19-May-2015 7:28:23 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_83F147B5_A438_45bc_85CC_6420217608FE__INCLUDED_)
#define EA_83F147B5_A438_45bc_85CC_6420217608FE__INCLUDED_

#include "Pointer_LinkedList.h"

template<class T>
class Single_LinkedList : public Pointer_LinkedList<T>
{

public:
	Single_LinkedList();
	virtual ~Single_LinkedList();

	virtual void Append(T item);
	virtual const void Get(int index);
	virtual void Prepend(T item);
	virtual void Remove(int index);

};
#endif // !defined(EA_83F147B5_A438_45bc_85CC_6420217608FE__INCLUDED_)
