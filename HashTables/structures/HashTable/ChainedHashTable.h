#pragma once

#include <vector>

#include "ErasableHashTable.h"

template<typename KeyType, typename DataType>
class ChainedHashTable : public ErasableHashTable<KeyType, DataType> {
private:
	LinkedList<HashTableElement<KeyType, DataType> >* buckets;

	LinkedListElement<HashTableElement<KeyType, DataType> >* findListElement(KeyType key);
	void initWithSize(int size);

public:
	ChainedHashTable(int size);
	ChainedHashTable(std::vector<HashTableElement<KeyType, DataType> > elements, int size = 0);
	~ChainedHashTable();
	void free();

	DataType* find(KeyType key);
	void insert(HashTableElement<KeyType, DataType> element);
	void remove(KeyType key);
};
