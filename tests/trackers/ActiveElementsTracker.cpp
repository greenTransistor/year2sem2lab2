#include "../../HashTables/trackers/ActiveElementsTracker.cpp"

TEST_CASE("ActiveElementsTracker") {
	int size = 10;
	int* data1 = new int(42);
	int* data2 = new int(1337);
	std::pair<int, int>* activeElement;

	ChainedHashTable<int, int> hashTable(size);

	REQUIRE_FALSE(hashTable.activeElementsElementsAvailable());

	SECTION("inserting") {
		hashTable.insert(HashTableElement<int, int>(1, data1));
		activeElement = hashTable.getNextActiveElement();

		REQUIRE(activeElement->first == hashTable.getIndex(1));
		REQUIRE(activeElement->second == 0);
		REQUIRE(hashTable.popActiveElement() == activeElement);
		REQUIRE_FALSE(hashTable.activeElementsElementsAvailable());

		delete activeElement;
	}

	SECTION("lookup") {
		hashTable.insert(HashTableElement<int, int>(1, data1));
		activeElement = hashTable.popActiveElement();
		hashTable.find(1);

		REQUIRE(hashTable.getNextActiveElement()->first == activeElement->first);
		REQUIRE(hashTable.getNextActiveElement()->second == activeElement->second);

		delete activeElement;
	}

	SECTION("lookup with collisions") {
		ChainedHashTable<int, int> trivialHashTable(1);

		//2x1 active elements
		trivialHashTable.insert(HashTableElement<int, int>(1, data1));
		trivialHashTable.insert(HashTableElement<int, int>(2, data2));

		//1+2 or 2+1 active elements
		trivialHashTable.find(1);
		trivialHashTable.find(2);

		//2 active elements
		trivialHashTable.find(3);

		for (int i = 0; i < 6; i++) {
			delete trivialHashTable.popActiveElement();
		}

		REQUIRE(trivialHashTable.activeElementsElementsAvailable());

		delete trivialHashTable.popActiveElement();

		REQUIRE_FALSE(hashTable.activeElementsElementsAvailable());
	}

	SECTION("clearing") {
		hashTable.insert(HashTableElement<int, int>(1, data1));
		hashTable.clearActiveElementsQueue();

		REQUIRE_FALSE(hashTable.activeElementsElementsAvailable());
	}

	SECTION("errors") {
		REQUIRE_THROWS_AS(hashTable.getNextActiveElement(), std::logic_error);
		REQUIRE_THROWS_AS(hashTable.popActiveElement(), std::logic_error);
	}

	delete data2;
	delete data1;
}
