///////////////////////////////////////////////////////////
//  Resizable_LinkedList.h
//  Implementation of the Class Resizable_LinkedList
//  Created on:      19-May-2015 7:28:25 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_39CCA368_D29D_41ad_8345_0FF9F1C4108B__INCLUDED_)
#define EA_39CCA368_D29D_41ad_8345_0FF9F1C4108B__INCLUDED_

#include "Array_LinkedList.h"

template<class T> //TODO come up with better name
class Resizable_LinkedList : public Array_LinkedList<T>
{

public:
	Resizable_LinkedList();
	virtual ~Resizable_LinkedList();

	virtual void Append(T const &item);
	virtual void Prepend(T const &item);
	virtual const void Get(int index);
	virtual void Remove(int index);

private:
	int CurrentSize;

};
#endif // !defined(EA_39CCA368_D29D_41ad_8345_0FF9F1C4108B__INCLUDED_)
