#pragma once

class LinearProbingStrategy : public ProbingStrategy {
public:
	int getOffset(int attemptNumber);
};
