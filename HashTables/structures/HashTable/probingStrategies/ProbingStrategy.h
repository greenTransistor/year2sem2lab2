#pragma once

class ProbingStrategy {
public:
	virtual ~ProbingStrategy() {}
	virtual void free() {}

	virtual int getOffset(int attemptNumber) {return 0;}
};
