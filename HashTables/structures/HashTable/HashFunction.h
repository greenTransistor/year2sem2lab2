#pragma once

#include <string>

class HashFunction {
private:
	static const uint32_t PRIME = 4294967291; //2^32 - 5

	uint32_t a;
	uint32_t b;

	static uint32_t stringToInt(std::string data);

public:
	HashFunction();
	HashFunction(uint32_t a, uint32_t b);

	uint32_t getValue(uint32_t data);
	uint32_t getValue(std::string data);
};
