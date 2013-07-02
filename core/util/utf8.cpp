
#include "utf8.hpp"
#include <iostream>

namespace {
  int highBitsSet(unsigned char c) {
	for(int i=0; i<4; ++i) {
	  if(((c >> (7-i)) & 1) == 0)
		return i;
	}
	return 4;
  }
}

bool utf8::seemsLegit(const std::string& str) {
  int expectedSymbols = 0;
  for(size_t i=0; i<str.size(); ++i) {
	if(expectedSymbols <= 0)
	  expectedSymbols = highBitsSet(str[i]);
	--expectedSymbols;
  }
  return expectedSymbols <= 0;
}

int	utf8::length() const {
  return string.size();
}

utf8::utf8(const std::string& str) {
  int expectedSymbols = 0;
  
  for(size_t i=0; i<str.size(); ++i) {
	expectedSymbols = std::max(1, highBitsSet(str[i]));
	// std::cout << "expected: " << expectedSymbols << std::endl;

	unsigned currentSymbol = 0;
	for(int k=0; k<expectedSymbols; ++k) {
	  currentSymbol |= (int)(str[i]) << (8 * (expectedSymbols-k-1));
	}

	string.push_back(currentSymbol);
	// std::cout << "pushing: " << currentSymbol << ": " << char(currentSymbol) << std::endl;
  }
}

const int& utf8::operator[] (int index) const {
  return string[index];
}

int& utf8::operator[] (int index) {
  return string[index];
}

std::ostream& operator << (std::ostream& out, const utf8& str) {
  for(size_t i=0; i<str.length(); ++i) {
	if(str[i] < 128)
	  out << char (str[i]);
	else
	  out << " (" << str[i] << ") ";
  }
  return out;
}

