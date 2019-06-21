#pragma once

#include "ProbingStrategy.h"
#include "../HashFunction.h"

class SecondHashProbingStrategy : public ProbingStrategy {
private:
	HashFunction hashFunction;

public:
	SecondHashProbingStrategy(int hashTableSize);

	int getOffset(int attemptNumber);
};
