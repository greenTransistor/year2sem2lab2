#include "../../../HashTables/structures/HashTable/ChainedHashTable.cpp"

TEST_CASE("ChainedHashTable") {
	int size = 10;
	int* data1 = new int(42);
	int* data2 = new int(1337);

	SECTION("getting indexes") {
		ChainedHashTable<int, int> hashTable(size);

		int minIndex = size;
		int maxIndex = -size;
		int index;

		for (int i = 0; i < size * 2; i++) {
			index = hashTable.getIndex(i);
			if (index < minIndex) {
				minIndex = index;
			}
			if (index > maxIndex) {
				maxIndex = index;
			}
		}

		REQUIRE(minIndex >= 0);
		REQUIRE(maxIndex < size);
	}

	SECTION("inserting to an empty chained hash table") {
		ChainedHashTable<int, int> hashTable(size);

		hashTable.insert(HashTableElement<int, int>(1, data1));

		REQUIRE(hashTable.find(1) == data1);

		hashTable.insert(HashTableElement<int, int>(2, data2));

		REQUIRE(hashTable.find(1) == data1);
		REQUIRE(hashTable.find(2) == data2);
		
		bool noOtherElementsFound = true;

		for (int i = 3; i <= size * 2; i++) {
			if (hashTable.find(i) != nullptr) {
				noOtherElementsFound = false;
				break;
			}
		}

		REQUIRE(noOtherElementsFound);
	}

	std::vector<HashTableElement<int, int> > elements = std::vector<HashTableElement<int, int> >({HashTableElement<int, int>(1, data1), HashTableElement<int, int>(2, data2)});

	SECTION("creating hash table with elements passed to constructor") {

		ChainedHashTable<int, int> hashTable(elements, size);

		REQUIRE(hashTable.find(1) == data1);
		REQUIRE(hashTable.find(2) == data2);
	}

	SECTION("collision") {
		ChainedHashTable<int, int> hashTable(elements, 1);

		REQUIRE(hashTable.find(1) == data1);
		REQUIRE(hashTable.find(2) == data2);
	}

	SECTION("errors") {
		SECTION("removing element from an empty hash table") {
			ChainedHashTable<int, int> hashTable(size);

			REQUIRE_THROWS_AS(hashTable.remove(1), std::logic_error);
		}

		SECTION("removing unexistent element from hash table") {
			ChainedHashTable<int, int> hashTable(elements, size);

			REQUIRE_THROWS_AS(hashTable.remove(3), std::logic_error);
		}

		SECTION("removing unexistent element from hash table of size 1") {
			ChainedHashTable<int, int> hashTable(elements, 1);

			REQUIRE_THROWS_AS(hashTable.remove(3), std::logic_error);
		}
	}

	//After this data1 and data2 should be freed, test with valgrind
	ChainedHashTable<int, int> hashTableForFreeing(elements, 2);
	hashTableForFreeing.free();
}
