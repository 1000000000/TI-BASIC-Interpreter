#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <list>
#include <map>
#include <sstream>

#include "Token.h"

double Tokenizer::unit_evaluate(const std::string& unit) {
	//Evaluates a single unit (variable or number)
	if (unit.size() == 1 && isVar(unit.c_str()[0])) {
		return vars[getVarIndex(unit.c_str()[0])];
	}
	return atof(unit.c_str());
}

unsigned int Tokenizer::getVarIndex(char varName) const {
	return varName - 'A';
}

bool Tokenizer::isVar(char varName) const {
	return varName >= 'A' && varName <= 'Z';
}
