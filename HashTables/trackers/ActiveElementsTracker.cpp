#include "ActiveElementsTracker.h"

#include <QString>

template class ActiveElementsTracker<int, QString>;

template<typename KeyType, typename DataType>
bool ActiveElementsTracker<KeyType, DataType>::activeElementsElementsAvailable() {
	return (!this->activeElementsQueue.isEmpty());
}

template<typename KeyType, typename DataType>
HashTableElement<KeyType, DataType>* ActiveElementsTracker<KeyType, DataType>::getNextActiveElement() {
	return this->activeElementsQueue.getHeadData();
}

template<typename KeyType, typename DataType>
HashTableElement<KeyType, DataType>* ActiveElementsTracker<KeyType, DataType>::popActiveElement() {
	return this->activeElementsQueue.dequeue();
}

template<typename KeyType, typename DataType>
void ActiveElementsTracker<KeyType, DataType>::recordActivity(HashTableElement<KeyType, DataType>* element) {
	this->activeElementsQueue.enqueue(element);
}
