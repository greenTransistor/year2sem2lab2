#pragma once

#include "LinkedListElement.h"

template<typename DataType>
class LinkedList {
private:
	LinkedListElement<DataType>* head;

public:
	LinkedList();
	~LinkedList();
	void free();

	void clear(bool deleteData = false);
	LinkedListElement<DataType>* getFirstElement();
	LinkedListElement<DataType>* getHead();
	LinkedListElement<DataType>* getLastElement();
	LinkedListElement<DataType>* insertBegin(DataType* data);
	LinkedListElement<DataType>* insertEnd(DataType* data);
	bool isEmpty();
	DataType* removeElement(LinkedListElement<DataType>* element, bool deleteData = false);
	DataType* removeFirstElement(bool deleteData = false);
	DataType* removeLastElement(bool deleteData = false);
};
