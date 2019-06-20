#pragma once

class SecondHashProbingStrategy : public ProbingStrategy {
private:
	HashFunction hashFunction;

public:
	SecondHashProbingStrategy(int hashTableSize);

	int getOffset(int attemptNumber);
};
