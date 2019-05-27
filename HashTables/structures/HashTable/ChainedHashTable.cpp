#include "ChainedHashTable.h"

#include <utility>

#include <stdexcept>
#include <QString>

template<typename KeyType, typename DataType>
ChainedHashTable<KeyType, DataType>::ChainedHashTable(int size) {
	this->initWithSize(size);
}

template<typename KeyType, typename DataType>
ChainedHashTable<KeyType, DataType>::ChainedHashTable(std::vector<HashTableElement<KeyType, DataType> > elements, int size) {
	this->initWithSize(size > 0 ? size : elements.size());
	for (HashTableElement<KeyType, DataType>& element : elements) {
		this->insert(element);
	}
}

template<typename KeyType, typename DataType>
ChainedHashTable<KeyType, DataType>::~ChainedHashTable() {
	for (int i = 0; i < this->size; i++) {
		this->buckets[i].free();
	}
	delete[] this->buckets;
}

template<typename KeyType, typename DataType>
void ChainedHashTable<KeyType, DataType>::free() {
	for (int i = 0; i < this->size; i++) {
		if (this->buckets[i].isEmpty()) {
			continue;
		}

		LinkedListElement<HashTableElement<KeyType, DataType> >* currentElement = this->buckets[i].getFirstElement();
		LinkedListElement<HashTableElement<KeyType, DataType> >* head = this->buckets[i].getHead();

		while (currentElement != head) {
			delete currentElement->data->data;
			currentElement = currentElement->next;
		}

		this->buckets[i].free();
	}
}

template<typename KeyType, typename DataType>
DataType* ChainedHashTable<KeyType, DataType>::find(KeyType key) {
	LinkedListElement<HashTableElement<KeyType, DataType> >* element = this->findListElement(key);

	if (element == nullptr) {
		return nullptr;
	} else {
		return element->data->data;
	}
}

template<typename KeyType, typename DataType>
LinkedListElement<HashTableElement<KeyType, DataType> >* ChainedHashTable<KeyType, DataType>::findListElement(KeyType key) {
	int bucketIndex = this->getIndex(key);
	if (this->buckets[bucketIndex].isEmpty()) {
		return nullptr;
	}

	LinkedListElement<HashTableElement<KeyType, DataType> >* currentElement = this->buckets[bucketIndex].getFirstElement();
	LinkedListElement<HashTableElement<KeyType, DataType> >* head = this->buckets[bucketIndex].getHead();
	int currentElementIndex = 0;

	while (currentElement != head) {
		this->recordActivity(new std::pair<int, int>(bucketIndex, currentElementIndex));
		if (currentElement->data->key == key) {
			return currentElement;
		}
		currentElement = currentElement->next;
		currentElementIndex++;
	}

	return nullptr;
}

template<typename KeyType, typename DataType>
void ChainedHashTable<KeyType, DataType>::initWithSize(int size) {
	this->size = size;
	this->buckets = new LinkedList<HashTableElement<KeyType, DataType> >[size];
}

template<typename KeyType, typename DataType>
void ChainedHashTable<KeyType, DataType>::insert(HashTableElement<KeyType, DataType> element) {
	HashTableElement<KeyType, DataType>* elementToInsert = element.clone();
	int bucketIndex = this->getIndex(element.key);

	this->buckets[bucketIndex].insertBegin(elementToInsert);
	this->recordActivity(new std::pair<int, int>(bucketIndex, 0));
}

template<typename KeyType, typename DataType>
void ChainedHashTable<KeyType, DataType>::remove(KeyType key) {
	LinkedListElement<HashTableElement<KeyType, DataType> >* element = this->findListElement(key);

	if (element == nullptr) {
		throw std::logic_error("attempt to remove unxistent element from chained hash table");
	}

	this->buckets[this->getIndex(key)].removeElement(element);
}

template class ChainedHashTable<int, QString>;
