#pragma once

#include <vector>

#include "MutableHashTable.h"

template<typename KeyType, typename DataType>
class ErasableHashTable : public MutableHashTable<KeyType, DataType> {
public:
	virtual ~ErasableHashTable() {}
	virtual void free() {}

	virtual void remove(KeyType key) {}
};
