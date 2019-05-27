 #pragma once

template<typename KeyType, typename DataType>
class HashTableElement {
public:
	KeyType key;
	DataType* data;

	HashTableElement(KeyType key, DataType* data);

	HashTableElement* clone();
};
