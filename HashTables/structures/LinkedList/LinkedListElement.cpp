#include "LinkedListElement.h"

#include "../HashTable/HashTableElement.h"

#include <utility>
#include <QString>

template class LinkedListElement<int>;
template class LinkedListElement<std::pair<int, int> >;
template class LinkedListElement<HashTableElement<int, QString>>;

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
