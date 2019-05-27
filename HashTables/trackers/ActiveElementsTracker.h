#pragma once

#include "../structures/HashTable/HashTableElement.h"
#include "../structures/Queue/Queue.h"

template<typename KeyType, typename DataType>
class ActiveElementsTracker {
private:
	Queue<HashTableElement<KeyType, DataType> > activeElementsQueue;

protected:
	void recordActivity(HashTableElement<KeyType, DataType>* element);

public:
	virtual ~ActiveElementsTracker() {};

	bool activeElementsElementsAvailable();
	void clearQueue(bool deleteData = true);
	HashTableElement<KeyType, DataType>* getNextActiveElement();
	HashTableElement<KeyType, DataType>* popActiveElement();
};
