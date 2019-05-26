#include "../../HashTables/structures/LinkedList/LinkedList.cpp"
#include "../../HashTables/structures/LinkedList/LinkedListElement.cpp"

TEST_CASE("LinkedList") {
	LinkedList<int> list;

	REQUIRE(list.isEmpty());

	SECTION("inserting") {
		int* data1 = new int(1);
		LinkedListElement<int>* element1 = list.insertBegin(data1);

		REQUIRE(element1->data == data1);
		REQUIRE(list.getFirstElement() == element1);
		REQUIRE(list.getLastElement() == element1);
		REQUIRE(element1->prev == list.getHead());
		REQUIRE(element1->next == list.getHead());

		SECTION("inserting to beginning") {
			LinkedListElement<int>* element2 = list.insertBegin(new int(2));

			REQUIRE(element2 != element1);
			REQUIRE(list.getFirstElement() == element2);
			REQUIRE(list.getLastElement() == element1);
		}

		SECTION("inserting to end") {
			LinkedListElement<int>* element2 = list.insertEnd(new int(2));

			REQUIRE(element2 != element1);
			REQUIRE(list.getLastElement() == element2);
			REQUIRE(list.getFirstElement() == element1);
		}
	}
	SECTION("removing") {
		SECTION("removing only element as first") {
			int* data = new int(1);
			int* removedElementData;

			list.insertBegin(data);
			removedElementData = list.removeFirstElement();

			REQUIRE(removedElementData == data);
			REQUIRE(list.isEmpty());

			delete data;
		}
		SECTION("removing only element as last") {
			int* data = new int(1);
			int* removedElementData;

			list.insertBegin(data);
			removedElementData = list.removeLastElement();

			REQUIRE(removedElementData == data);
			REQUIRE(list.isEmpty());

			delete data;
		}
		SECTION("removing first of two elements") {
			LinkedListElement<int>* element1 = list.insertBegin(new int(1));
			LinkedListElement<int>* element2 = list.insertEnd(new int(2));

			list.removeFirstElement(true);

			REQUIRE_FALSE(list.isEmpty());
			REQUIRE(list.getFirstElement() == element2);
			REQUIRE(list.getLastElement() == element2);
		}
		SECTION("removing middle of three elements") {
			LinkedListElement<int>* element1 = list.insertEnd(new int(1));
			LinkedListElement<int>* element2 = list.insertEnd(new int(2));
			LinkedListElement<int>* element3 = list.insertEnd(new int(3));

			list.removeElement(element2, true);

			REQUIRE_FALSE(list.isEmpty());
			REQUIRE(list.getFirstElement() == element1);
			REQUIRE(list.getLastElement() == element3);
		}
	}
	SECTION("errors") {
		SECTION("removing element from empty list") {
			REQUIRE_THROWS_AS(list.removeFirstElement(), std::logic_error);
		}
		SECTION("getting first element of an empty list") {
			REQUIRE_THROWS_AS(list.getFirstElement(), std::logic_error);
		}
		SECTION("getting last element of an empty list") {
			REQUIRE_THROWS_AS(list.getLastElement(), std::logic_error);
		}
	}
	list.free();
}
