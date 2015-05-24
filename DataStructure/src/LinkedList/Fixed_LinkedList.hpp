///////////////////////////////////////////////////////////
//  Fixed_LinkedList.h
//  Implementation of the Class Fixed_LinkedList
//  Created on:      19-May-2015 7:28:24 PM
//  Original author: Randall
///////////////////////////////////////////////////////////

#if !defined(EA_D48AA186_673A_4b4b_89C4_3ED2AEB1FFBF__INCLUDED_)
#define EA_D48AA186_673A_4b4b_89C4_3ED2AEB1FFBF__INCLUDED_

#include "Array_LinkedList.h"
#include "LinkedListException.h"
#include <memory>
#include <array>
#include <cstring>


template<class T>
class Fixed_LinkedList : public Array_LinkedList<T>
{
    public:      
        Fixed_LinkedList(const int maxSize);
        virtual ~Fixed_LinkedList();
        
        void Append(T const &item);
		void Prepend(T const &item);
		T Get(const int index) const;
		void Remove(const int index);
        
    private:
        const int maxSize;
        T* values;
};


template<class T>
Fixed_LinkedList<T>::Fixed_LinkedList(const int maxSizeIn) : maxSize{maxSizeIn} {
    this->size = 0;
    this->values = new T[maxSize];
}

template<class T>
Fixed_LinkedList<T>::~Fixed_LinkedList() {
    delete[] this->values;            
}

template<class T>
void Fixed_LinkedList<T>::Append(T const &item) {
    if( this->size < maxSize ) {
        values[this->size] = item;
        this->size++;
    } else {
        throw LinkedListException("Trying to append on full linked list.");
    }
}

template<class T>
void Fixed_LinkedList<T>::Prepend(T const &item) {

    if( this->size >= maxSize ) {
    	throw LinkedListException("Trying to prepend on a full linked list.");
    } else {
    	memmove((void*)values+1, (void*)values, sizeof(T) * this->size);
		values[0] = item;
		this->size++;
    }
}

template<class T>
T Fixed_LinkedList<T>::Get(const int index) const {
    if( index < this->size ) {
        return values[index];
    } else {
        throw LinkedListException("Invalid index used to access linked list.");
    }
}

template<class T>
void Fixed_LinkedList<T>::Remove(const int index) {
    //TODO
	if( this->size > index ) {

	}
}

#endif // !defined(EA_D48AA186_673A_4b4b_89C4_3ED2AEB1FFBF__INCLUDED_)

