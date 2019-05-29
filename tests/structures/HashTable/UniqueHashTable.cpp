#include "../../../HashTables/structures/HashTable/UniqueHashTable.cpp"

TEST_CASE("UniqueHashTable") {
	int size = 10;
	int* data1 = new int(42);
	int* data2 = new int(1337);

	srand(0);

	SECTION("inserting to an empty unique hash table") {
		UniqueHashTable<int, int> hashTable(size);

		hashTable.insert(HashTableElement<int, int>(1, data1));

		bool noOtherElementsFound = true;

		for (int i = 2; i <= size * 10; i++) {
			if (hashTable.find(i) != nullptr) {
				noOtherElementsFound = false;
				break;
			}
		}

		REQUIRE(noOtherElementsFound);
	}

	std::vector<HashTableElement<int, int> > elements = std::vector<HashTableElement<int, int> >({HashTableElement<int, int>(1, data1)});

	SECTION("creating unique hash table with element passed to constructor") {
		UniqueHashTable<int, int> hashTable(elements, size);

		REQUIRE(hashTable.find(1) == data1);
	}

	SECTION("errors") {
		SECTION("collision") {
			UniqueHashTable<int, int> hashTable(elements, 1);

			REQUIRE_FALSE(hashTable.canInsert(1));
			REQUIRE_FALSE(hashTable.canInsert(2));
			REQUIRE_THROWS_AS(hashTable.insert(HashTableElement<int, int>(2, data2)), std::logic_error);
		}

		SECTION("removing element from an empty hash table") {
			UniqueHashTable<int, int> hashTable(size);

			REQUIRE_THROWS_AS(hashTable.remove(1), std::logic_error);
		}

		SECTION("removing unexistent element from hash table") {
			UniqueHashTable<int, int> hashTable(elements, size);

			REQUIRE_THROWS_AS(hashTable.remove(2), std::logic_error);
		}

		SECTION("removing unexistent element from hash table of size 1") {
			UniqueHashTable<int, int> hashTable(elements, 1);

			REQUIRE_THROWS_AS(hashTable.remove(2), std::logic_error);
		}
	}

	delete data2;
	delete data1;
}
