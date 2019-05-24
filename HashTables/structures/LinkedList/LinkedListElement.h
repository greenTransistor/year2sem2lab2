#pragma once

template<typename DataType>
class LinkedListElement {
public:
	LinkedListElement<DataType>* prev;
	LinkedListElement<DataType>* next;
	DataType* data;

	LinkedListElement(DataType* data = nullptr, LinkedListElement<DataType>* prev = nullptr, LinkedListElement<DataType>* next = nullptr);
	~LinkedListElement();
	LinkedListElement<DataType>* insertAfter(DataType* data);
	LinkedListElement<DataType>* insertBefore(DataType* data);
};
