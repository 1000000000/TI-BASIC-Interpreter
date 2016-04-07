#include "Token.h"

double Tokenizer::evaluate(const std::string& parsee) {
	return 4;
}

unsigned int Tokenizer::getVarIndex(char varName) const {
	return varName - '?';
}

bool Tokenizer::isVar(char varName) const {
	return varName >= '?' && varName <= 'Z';
}
