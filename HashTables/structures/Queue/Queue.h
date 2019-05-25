#pragma once

#include "../LinkedList/LinkedList.h"

template<typename DataType>
class Queue {
private:
	LinkedList<DataType>* list;

public:
	Queue();
	~Queue();
	void free();

	void clear(bool deleteData = false);
	DataType* dequeue();
	void enqueue(DataType* data);
	DataType* getHeadData();
	bool isEmpty();
};
