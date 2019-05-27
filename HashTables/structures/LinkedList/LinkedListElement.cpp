#include "LinkedListElement.h"

#include "../HashTable/HashTableElement.h"

#include <utility>
#ifndef TEST
	#include <QString>
#endif

template class LinkedListElement<int>;
template class LinkedListElement<std::pair<int, int> >;
#ifndef TEST
	template class LinkedListElement<HashTableElement<int, QString>>;
#endif

template<typename DataType>
LinkedListElement<DataType>::LinkedListElement(DataType* data, LinkedListElement<DataType>* prev, LinkedListElement<DataType>* next) {
	this->data = data;
	this->prev = (prev != nullptr ? prev : this);
	this->next = (next != nullptr ? next : this);
}

template<typename DataType>
LinkedListElement<DataType>::~LinkedListElement() {
	this->prev->next = this->next;
	this->next->prev = this->prev;
}

template<typename DataType>
LinkedListElement<DataType>* LinkedListElement<DataType>::insertAfter(DataType* data) {
	LinkedListElement<DataType>* newElement = new LinkedListElement<DataType>(data, this, this->next);

	this->next->prev = newElement;
	this->next = newElement;

	return newElement;
}

template<typename DataType>
LinkedListElement<DataType>* LinkedListElement<DataType>::insertBefore(DataType* data) {
	LinkedListElement<DataType>* newElement = new LinkedListElement<DataType>(data, this->prev, this);

	this->prev->next = newElement;
	this->prev = newElement;

	return newElement;
}
