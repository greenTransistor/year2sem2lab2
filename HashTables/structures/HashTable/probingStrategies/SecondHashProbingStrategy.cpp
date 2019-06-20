#include "SecondHashProbingStrategy.h"

SecondHashProbingStrategy::SecondHashProbingStrategy(int hashTableSize) {
	this->hashFunction = HashFunction(hashTableSize);
}

int SecondHashProbingStrategy::getOffset(int attemptNumber) {
	return attemptNumber;
}
