#include "LinkedList.h"

#include <stdexcept>

template class LinkedList<int>;

template<typename DataType>
LinkedList<DataType>::LinkedList() {
	this->head = new LinkedListElement<DataType>();
}

template<typename DataType>
LinkedList<DataType>::~LinkedList() {
	this->clear();
	delete this->head;
}

template<typename DataType>
void LinkedList<DataType>::free() {
	this->clear(true);
}


template<typename DataType>
void LinkedList<DataType>::clear(bool deleteData) {
	if (this->isEmpty()) {
		return;
	}

	LinkedListElement<DataType>* currentElement = this->getFirstElement();
	LinkedListElement<DataType>* nextElement;

	while (currentElement != this->head) {
		nextElement = currentElement->next;
		this->removeElement(currentElement, deleteData);
		currentElement = nextElement;
	}
}

template<typename DataType>
DataType* LinkedList<DataType>::removeElement(LinkedListElement<DataType>* element, bool deleteData) {
	if (this->isEmpty()) {
		throw std::logic_error("attempt to remove element from an empty list");
	}

	DataType* data = element->data;

	delete element;

	if (deleteData) {
		if (data != nullptr) {
			delete data;
		}
		return nullptr;
	} else {
		return data;
	}
}

template<typename DataType>
LinkedListElement<DataType>* LinkedList<DataType>::getFirstElement() {
	if (this->isEmpty()) {
		throw std::logic_error("attempt to get first element of an empty list");
	}

	return this->head->next;
}

template<typename DataType>
LinkedListElement<DataType>* LinkedList<DataType>::getHead() {
	return this->head;
}

template<typename DataType>
LinkedListElement<DataType>* LinkedList<DataType>::getLastElement() {
	if (this->isEmpty()) {
		throw std::logic_error("attempt to get last element of an empty list");
	}

	return this->head->prev;
}

template<typename DataType>
LinkedListElement<DataType>* LinkedList<DataType>::insertBegin(DataType* data) {
	return this->head->insertAfter(data);
}

template<typename DataType>
LinkedListElement<DataType>* LinkedList<DataType>::insertEnd(DataType* data) {
	return this->head->insertBefore(data);
}

template<typename DataType>
bool LinkedList<DataType>::isEmpty() {
	return (this->head->next == this->head);
}

template<typename DataType>
DataType* LinkedList<DataType>::removeFirstElement(bool deleteData) {
	return this->removeElement(this->getFirstElement(), deleteData);
}

template<typename DataType>
DataType* LinkedList<DataType>::removeLastElement(bool deleteData) {
	return this->removeElement(this->getLastElement(), deleteData);
}
