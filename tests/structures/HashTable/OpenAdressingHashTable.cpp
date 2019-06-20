#include "../../../HashTables/structures/HashTable/probingStrategies/ProbingStrategy.cpp"
#include "../../../HashTables/structures/HashTable/probingStrategies/LinearProbingStrategy.cpp"
#include "../../../HashTables/structures/HashTable/probingStrategies/SecondHashProbingStrategy.cpp"
#include "../../../HashTables/structures/HashTable/OpenAdressingHashTable.cpp"

TEST_CASE("OpenAdressingHashTable") {
	int size = 10;
	int* data1 = new int(42);
	int* data2 = new int(1337);

	srand(0);

	SECTION("inserting to an empty open addressing hash table") {
		OpenAdressingHashTable<int, int> hashTable(new SecondHashProbingStrategy(size), size);

		hashTable.insert(HashTableElement<int, int>(1, data1));

		REQUIRE(hashTable.find(1) == data1);

		hashTable.insert(HashTableElement<int, int>(2, data2));

		REQUIRE(hashTable.find(1) == data1);
		REQUIRE(hashTable.find(2) == data2);
		
		bool noOtherElementsFound = true;

		for (int i = 3; i <= size * 10; i++) {
			if (hashTable.find(i) != nullptr) {
				noOtherElementsFound = false;
				break;
			}
		}

		REQUIRE(noOtherElementsFound);
	}

	std::vector<HashTableElement<int, int> > elements = std::vector<HashTableElement<int, int> >({HashTableElement<int, int>(1, data1), HashTableElement<int, int>(2, data2)});

	SECTION("creating open addressing hash table with elements passed to constructor") {
		OpenAdressingHashTable<int, int> hashTable(new SecondHashProbingStrategy(size), elements, size);

		REQUIRE(hashTable.find(1) == data1);
		REQUIRE(hashTable.find(2) == data2);
	}

	SECTION("filling up open addressing hash table with with linear probing strategy") {
		OpenAdressingHashTable<int, int> hashTable(new LinearProbingStrategy(), size);

		for (int i = 0; i < size; i++) {
			hashTable.insert(HashTableElement<int, int>(1, new int(i)));
		}

		REQUIRE_THROWS_AS(hashTable.insert(HashTableElement<int, int>(1, data1)), std::logic_error);
		REQUIRE_THROWS_AS(hashTable.insert(HashTableElement<int, int>(1, data2)), std::logic_error);

		hashTable.free();
	}

	//After this data1 and data2 should be freed, test with valgrind
	OpenAdressingHashTable<int, int> hashTableForFreeing(new LinearProbingStrategy(), elements, 2);
	hashTableForFreeing.free();
}
