#pragma once

#include "ProbingStrategy.h"

class LinearProbingStrategy : public ProbingStrategy {
public:
	int getOffset(int attemptNumber);
};
