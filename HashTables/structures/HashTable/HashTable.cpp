#include "HashTable.h"

#ifndef TEST
	#include <QString>

	template class HashTable<int, QString>;
#endif

template<typename KeyType, typename DataType>
int HashTable<KeyType, DataType>::getIndex(KeyType key) {
	return (this->hashFunction.getValue(key) % this->size);
}
