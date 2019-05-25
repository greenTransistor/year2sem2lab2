#include "Queue.h"

template class Queue<int>;

template<typename DataType>
Queue<DataType>::Queue() {
	this->list = new LinkedList<DataType>();
}

template<typename DataType>
Queue<DataType>::~Queue() {
	delete this->list;
}

template<typename DataType>
void Queue<DataType>::free() {
	this->clear(true);
}


template<typename DataType>
void Queue<DataType>::clear(bool deleteData) {
	this->list->clear(deleteData);
}

template<typename DataType>
DataType* Queue<DataType>::dequeue() {
	return this->list->removeFirstElement();
}

template<typename DataType>
void Queue<DataType>::enqueue(DataType* data) {
	this->list->insertEnd(data);
}

template<typename DataType>
DataType* Queue<DataType>::getHeadData() {
	return this->list->getFirstElement()->data;
}

template<typename DataType>
bool Queue<DataType>::isEmpty() {
	return this->list->isEmpty();
}
