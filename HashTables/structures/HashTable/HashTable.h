#pragma once

#include <vector>

#include "HashFunction.h"
#include "HashTableElement.h"
#include "../../trackers/ActiveElementsTracker.h"

template<typename KeyType, typename DataType>
class HashTable : public ActiveElementsTracker<KeyType, DataType> {
protected:
	HashFunction hashFunction;
	int size;

public:
	virtual ~HashTable() {}
	virtual void free() {}

	virtual DataType* find(KeyType key) {return nullptr;}
	int getIndex(KeyType key);
};
