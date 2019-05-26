#include "../../HashTables/structures/Queue/Queue.cpp"

TEST_CASE("Queue") {
	Queue<int> queue;

	REQUIRE(queue.isEmpty());

	SECTION("enqueue") {
		int* data1 = new int(1);
		queue.enqueue(data1);

		REQUIRE_FALSE(queue.isEmpty());
		REQUIRE(queue.getHeadData() == data1);

		int* data2 = new int(2);
		queue.enqueue(data2);

		REQUIRE(queue.getHeadData() == data1);
	}
	SECTION("dequeue") {
		SECTION("dequeue only element") {
			int* data = new int(1);
			int* dequeuedData;

			queue.enqueue(data);
			dequeuedData = queue.dequeue();

			REQUIRE(dequeuedData == data);
			REQUIRE(queue.isEmpty());

			delete data;
		}
		SECTION("dequeue two elements") {
			int* data1 = new int(1);
			int* data2 = new int(2);
			int* dequeuedData;

			queue.enqueue(data1);
			queue.enqueue(data2);
			dequeuedData = queue.dequeue();

			REQUIRE(dequeuedData == data1);
			REQUIRE(queue.getHeadData() == data2);

			delete dequeuedData;
			dequeuedData = queue.dequeue();

			REQUIRE(dequeuedData == data2);
			REQUIRE(queue.isEmpty());

			delete dequeuedData;
		}
	}
	SECTION("errors") {
		SECTION("dequeue from empty queue") {
			REQUIRE_THROWS_AS(queue.dequeue(), std::logic_error);
		}
		SECTION("getting head of empty queue") {
			REQUIRE_THROWS_AS(queue.getHeadData(), std::logic_error);
		}
	}
	queue.free();
}
