#include "HashFunction.h"

#include <cstdlib>

uint32_t HashFunction::stringToInt(std::string data) {
	uint32_t result = 0;
	uint32_t xorMask;

	for (size_t i = 0; i < data.size(); i++) {
		xorMask = ((result & 0xFF000000) >> 24) * 0x01010101;
		result = (((result << 8) & 0xFFFFFFFF) + data[i]) ^ xorMask;
	}

	return result;
}

HashFunction::HashFunction() {
	this->a = (rand() % (HashFunction::PRIME - 1) + 1);
	this->b = (rand() % HashFunction::PRIME);
}

HashFunction::HashFunction(uint32_t a, uint32_t b) {
	this->a = a;
	this->b = b;
}

uint32_t HashFunction::getValue(uint32_t data) {
	uint64_t a = this->a;
	uint64_t b = this->b;
	return ((uint32_t)((((uint64_t)(data)) * a + b) % HashFunction::PRIME));
}

uint32_t HashFunction::getValue(std::string data) {
	return this->getValue(HashFunction::stringToInt(data));
}
