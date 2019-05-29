#pragma once

#include <vector>

#include "ErasableHashTable.h"

template<typename KeyType, typename DataType>
class UniqueHashTable : public ErasableHashTable<KeyType, DataType> {
private:
	HashTableElement<KeyType, DataType>** buckets;

	void initWithSize(int size);

public:
	UniqueHashTable(int size);
	UniqueHashTable(std::vector<HashTableElement<KeyType, DataType> > elements, int size = 0);
	~UniqueHashTable();
	void free();

	bool canInsert(KeyType key);
	DataType* find(KeyType key);
	void insert(HashTableElement<KeyType, DataType> element);
	void remove(KeyType key);
};
