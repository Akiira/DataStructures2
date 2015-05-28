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

		void Append(T const &item);
		void Prepend(T const &item);
		T Get(const int index) const;
		void Remove(const int index);
};

template<class T>
Doubly_LinkedList<T>::Doubly_LinkedList() {
	this->front = nullptr;
	this->end = nullptr;
	this->size = 0;
}

template<class T>
Doubly_LinkedList<T>::~Doubly_LinkedList() {
	while(this->front){
		auto temp = this->front->next;

		delete this->front;

		this->front = temp;
	}
}

template<class T>
void Doubly_LinkedList<T>::Append(T const &item) {

	if( this->size > 0 ) {
		this->end->next = new node<T>(item, this->end, nullptr);
		this->end = this->end->next;
	} else {
		this->front = new node<T>(item);
		this->end = this->front;
	}

	this->size++;
}

template<class T>
void Doubly_LinkedList<T>::Prepend(T const &item) {
	if( this->size > 0 ) {
		auto temp = this->front;
		this->front = new node<T>(item, nullptr, temp);
		this->size++;
	} else {
		Append(item);
	}
}

template<class T>
T Doubly_LinkedList<T>::Get(const int index) const {
	if( this->size == 0 ) {
		throw LinkedListException("todo.");
	} else if( index < 0 || index > this->size - 1 ) {
		throw LinkedListException("Invalid index used in linked list.");
	}

	if( index == 0 ) { //Front element
		return this->front->x;
	} else if( index == this->size - 1 ) { //Last element
		return this->end->x;
	} else {
		int i = index;
		auto temp = this->front;

		while(i) {
			temp = temp->next;
			i--;
		}

		return temp->x;
	}
}

template<class T>
void Doubly_LinkedList<T>::Remove(const int index) {
	if( this->size == 0 ) {
		throw LinkedListException("todo.");//TODO
	} else if( index < 0 || index > this->size - 1 ) {
		throw LinkedListException("Invalid index used in linked list.");
	}

	if( this->size == 1 ) { //One element so we must set front and end to null
		delete this->front;
		this->front = nullptr;
		this->end = nullptr;
	} else if( index == 0 ) { //Special handling of front element
		auto temp = this->front;
		this->front = this->front->next;
		delete temp;
	} else { //General case
		int i = index - 1;
		auto temp = this->front;

		//Going to one before target
		while(i) {
			temp = temp->next;
			i--;
		}

		auto targetNode = temp->next;
		temp->next = targetNode->next;
		delete targetNode;
	}

	this->size--;
}

#endif // !defined(EA_8C992860_B6FA_4199_9115_D83DEBFB6B7A__INCLUDED_)
