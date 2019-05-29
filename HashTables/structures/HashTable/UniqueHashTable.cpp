#include "UniqueHashTable.h"

#include <utility>

#include <stdexcept>
#ifndef TEST
	#include <QString>

	template class UniqueHashTable<int, QString>;
#endif

template<typename KeyType, typename DataType>
UniqueHashTable<KeyType, DataType>::UniqueHashTable(int size) {
	this->initWithSize(size);
}

template<typename KeyType, typename DataType>
UniqueHashTable<KeyType, DataType>::UniqueHashTable(std::vector<HashTableElement<KeyType, DataType> > elements, int size) {
	this->initWithSize(size > 0 ? size : elements.size());
	for (HashTableElement<KeyType, DataType>& element : elements) {
		this->insert(element);
	}
}

template<typename KeyType, typename DataType>
UniqueHashTable<KeyType, DataType>::~UniqueHashTable() {
	for (int i = 0; i < this->size; i++) {
		if (this->buckets[i] != nullptr) {
			delete this->buckets[i];
		}
	}
	delete[] this->buckets;
}

template<typename KeyType, typename DataType>
void UniqueHashTable<KeyType, DataType>::free() {
	for (int i = 0; i < this->size; i++) {
		if (this->buckets[i] != nullptr) {
			delete this->buckets[i]->data;
			delete this->buckets[i];
			this->buckets[i] = nullptr;
		}
	}
}


template<typename KeyType, typename DataType>
bool UniqueHashTable<KeyType, DataType>::canInsert(KeyType key) {
	return (this->buckets[this->getIndex(key)] == nullptr);
}

template<typename KeyType, typename DataType>
DataType* UniqueHashTable<KeyType, DataType>::find(KeyType key) {
	int bucketIndex = this->getIndex(key);
	HashTableElement<KeyType, DataType>* element = this->buckets[bucketIndex];
	if (element == nullptr) {
		this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_IN_EMPTY_BUCKET));
		return nullptr;
	}

	this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_OF_ONLY_ELEMENT));
	if (element->key == key) {
		return element->data;
	} else {
		return nullptr;
	}
}

template<typename KeyType, typename DataType>
void UniqueHashTable<KeyType, DataType>::initWithSize(int size) {
	this->size = size;
	this->buckets = new HashTableElement<KeyType, DataType>*[size];

	for (int i = 0; i < size; i++) {
		this->buckets[i] = nullptr;
	}
}

template<typename KeyType, typename DataType>
void UniqueHashTable<KeyType, DataType>::insert(HashTableElement<KeyType, DataType> element) {
	int bucketIndex = this->getIndex(element.key);

	if (this->buckets[bucketIndex] != nullptr) {
		throw std::logic_error("attempt to insert into unique hash table causes collision");
	}

	this->buckets[bucketIndex] = element.clone();
	this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_OF_ONLY_ELEMENT));
}

template<typename KeyType, typename DataType>
void UniqueHashTable<KeyType, DataType>::remove(KeyType key) {
	int bucketIndex = this->getIndex(key);
	HashTableElement<KeyType, DataType>* element = this->buckets[bucketIndex];

	if (element == nullptr || element->key != key) {
		throw std::logic_error("attempt to remove unxistent element from unique hash table");
	}

	delete element;
	this->buckets[bucketIndex] = nullptr;
}
