#include "HashTableElement.h"

template<typename KeyType, typename DataType>
HashTableElement<KeyType, DataType>::HashTableElement(KeyType key, DataType* data) {
	this->key = key;
	this->data = data;
}

template<typename KeyType, typename DataType>
HashTableElement<KeyType, DataType>* HashTableElement<KeyType, DataType>::clone() {
	return new HashTableElement<KeyType, DataType>(this->key, this->data);
}
