#include "ActiveElementsTracker.h"

#ifndef TEST
	#include <QString>
#endif

#ifndef TEST
	template class ActiveElementsTracker<int, QString>;
#endif

template<typename KeyType, typename DataType>
const int ActiveElementsTracker<KeyType, DataType>::INDEX_IN_EMPTY_BUCKET = -1;

template<typename KeyType, typename DataType>
ActiveElementsTracker<KeyType, DataType>::~ActiveElementsTracker() {
	this->clearActiveElementsQueue(true);
}

template<typename KeyType, typename DataType>
bool ActiveElementsTracker<KeyType, DataType>::activeElementsElementsAvailable() {
	return (!this->activeElementsQueue.isEmpty());
}

template<typename KeyType, typename DataType>
void ActiveElementsTracker<KeyType, DataType>::clearActiveElementsQueue(bool deleteData) {
	return this->activeElementsQueue.clear(deleteData);
}

template<typename KeyType, typename DataType>
std::pair<int, int>* ActiveElementsTracker<KeyType, DataType>::getNextActiveElement() {
	return this->activeElementsQueue.getHeadData();
}

template<typename KeyType, typename DataType>
std::pair<int, int>* ActiveElementsTracker<KeyType, DataType>::popActiveElement() {
	return this->activeElementsQueue.dequeue();
}

template<typename KeyType, typename DataType>
void ActiveElementsTracker<KeyType, DataType>::recordActivity(std::pair<int, int>* element) {
	this->activeElementsQueue.enqueue(element);
}
