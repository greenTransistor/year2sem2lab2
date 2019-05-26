#pragma once

#include <vector>

#include "HashTable.h"

template<typename KeyType, typename DataType>
class MutableHashTable : public HashTable<KeyType, DataType> {
public:
	virtual ~MutableHashTable() {}
	virtual void free() {}

	virtual void insert(HashTableElement<KeyType, DataType> element) {}
};
