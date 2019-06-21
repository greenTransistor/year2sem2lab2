#include "OpenAdressingHashTable.h"

#include <utility>

#include <stdexcept>
#ifndef TEST
	#include <QString>

	template class OpenAdressingHashTable<int, QString>;
#endif

template<typename KeyType, typename DataType>
OpenAdressingHashTable<KeyType, DataType>::OpenAdressingHashTable(ProbingStrategy* probingStrategy, int size) {
	this->probingStrategy = probingStrategy;
	this->initWithSize(size);
}

template<typename KeyType, typename DataType>
OpenAdressingHashTable<KeyType, DataType>::OpenAdressingHashTable(ProbingStrategy* probingStrategy, std::vector<HashTableElement<KeyType, DataType> > elements, int size) {
	this->probingStrategy = probingStrategy;
	this->initWithSize(size > 0 ? size : elements.size());
	for (HashTableElement<KeyType, DataType>& element : elements) {
		this->insert(element);
	}
}

template<typename KeyType, typename DataType>
OpenAdressingHashTable<KeyType, DataType>::~OpenAdressingHashTable() {
	for (int i = 0; i < this->size; i++) {
		if (this->buckets[i] != nullptr) {
			delete this->buckets[i];
		}
	}
	delete[] this->buckets;
	delete this->probingStrategy;
}

template<typename KeyType, typename DataType>
void OpenAdressingHashTable<KeyType, DataType>::free() {
	for (int i = 0; i < this->size; i++) {
		if (this->buckets[i] != nullptr) {
			delete this->buckets[i]->data;
			delete this->buckets[i];
			this->buckets[i] = nullptr;
		}
	}
}

template<typename KeyType, typename DataType>
bool OpenAdressingHashTable<KeyType, DataType>::canInsert(KeyType key) {
	return (this->elementsCount < this->size);
}

template<typename KeyType, typename DataType>
DataType* OpenAdressingHashTable<KeyType, DataType>::find(KeyType key) {
	int startIndex = this->getIndex(key);
	int bucketIndex = startIndex;
	int attemptNumber = 0;

	while (this->buckets[bucketIndex] != nullptr && this->buckets[bucketIndex]->key != key) {
		this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_OF_ONLY_ELEMENT));
		attemptNumber++;
		bucketIndex = (startIndex + this->probingStrategy->getOffset(attemptNumber)) % this->size;
	}

	if (this->buckets[bucketIndex] == nullptr) {
		this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_IN_EMPTY_BUCKET));
		return nullptr;
	} else {
		this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_OF_ONLY_ELEMENT));
		return this->buckets[bucketIndex]->data;
	}
}

template<typename KeyType, typename DataType>
void OpenAdressingHashTable<KeyType, DataType>::initWithSize(int size) {
	this->size = size;
	this->buckets = new HashTableElement<KeyType, DataType>*[size];
	this->elementsCount = 0;

	for (int i = 0; i < size; i++) {
		this->buckets[i] = nullptr;
	}
}

template<typename KeyType, typename DataType>
void OpenAdressingHashTable<KeyType, DataType>::insert(HashTableElement<KeyType, DataType> element) {
	if (!this->canInsert(element.key)) {
		throw std::logic_error("attempt to insert into fully filled open addressing hash table");
	}

	int startIndex = this->getIndex(element.key);
	int bucketIndex = startIndex;
	int attemptNumber = 0;
	while (this->buckets[bucketIndex] != nullptr) {
		attemptNumber++;
		bucketIndex = (startIndex + this->probingStrategy->getOffset(attemptNumber)) % this->size;
	}

	this->buckets[bucketIndex] = element.clone();
	elementsCount++;
	this->recordActivity(new std::pair<int, int>(bucketIndex, this->INDEX_OF_ONLY_ELEMENT));
}
