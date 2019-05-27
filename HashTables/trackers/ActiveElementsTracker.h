#pragma once

#include <utility>

#include "../structures/HashTable/HashTableElement.h"
#include "../structures/Queue/Queue.h"

template<typename KeyType, typename DataType>
class ActiveElementsTracker {
private:
	Queue<std::pair<int, int> > activeElementsQueue;

protected:
	void recordActivity(std::pair<int, int>* element);

public:
	virtual ~ActiveElementsTracker() {};

	bool activeElementsElementsAvailable();
	void clearQueue(bool deleteData = true);
	std::pair<int, int>* getNextActiveElement();
	std::pair<int, int>* popActiveElement();
};
