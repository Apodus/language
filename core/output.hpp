
#pragma once

#include <string>
#include <vector>
#include "verb.hpp"

void outputSinglePuzzle(int, const std::string&, const std::string&, const std::string&);
int  outputSingleGrade(const Verb&, const std::string&, const std::string&, const std::string&);
void outputFindWord(const std::vector<Verb>&, const std::string&);
