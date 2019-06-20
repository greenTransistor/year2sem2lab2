#pragma once

#include <vector>

#include "ErasableHashTable.h"
#include "probingStrategies/ProbingStrategy.h"

template<typename KeyType, typename DataType>
class OpenAdressingHashTable : public MutableHashTable<KeyType, DataType> {
private:
	HashTableElement<KeyType, DataType>** buckets;
	int elementsCount;
	ProbingStrategy* probingStrategy;

	void initWithSize(int size);

public:
	OpenAdressingHashTable(ProbingStrategy* probingStrategy, int size);
	OpenAdressingHashTable(ProbingStrategy* probingStrategy, std::vector<HashTableElement<KeyType, DataType> > elements, int size = 0);
	~OpenAdressingHashTable();
	void free();

	bool canInsert(KeyType key);
	DataType* find(KeyType key);
	void insert(HashTableElement<KeyType, DataType> element);
};
