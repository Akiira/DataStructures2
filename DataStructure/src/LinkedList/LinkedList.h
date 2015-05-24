///////////////////////////////////////////////////////////
//  LinkedList.h
//  Implementation of the Class LinkedList
//  Created on:      19-May-2015 7:28:23 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_1891E4B1_2421_425e_AA06_F1D83A4E3CD2__INCLUDED_)
#define EA_1891E4B1_2421_425e_AA06_F1D83A4E3CD2__INCLUDED_

template<class T>
class LinkedList
{

public:
	virtual void Append(T const &item) =0;
	virtual void Prepend(T const &item) =0;
	virtual T Get(const int index) const =0;
	virtual void Remove(const int index) =0;

	int Size() const { return size; }

protected:
	unsigned int size;
};
#endif // !defined(EA_1891E4B1_2421_425e_AA06_F1D83A4E3CD2__INCLUDED_)
