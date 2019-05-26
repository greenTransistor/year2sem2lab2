#pragma once

#include <vector>

#include "HashFunction.h"
#include "HashTableElement.h"

template<typename KeyType, typename DataType>
class HashTable {
protected:
	HashFunction hashFunction;
	int size;

public:
	virtual ~HashTable() {}
	virtual void free() {}

	virtual DataType* find(KeyType key) {return nullptr;}
	int getIndex(KeyType key);
};
