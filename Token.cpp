#include "Token.h"

Tokenizer::Tokenizer(double vars[]) {}

double Tokenizer::evaluate(const std::string& parsee) const {
	return 4;
}

unsigned int Tokenizer::getVarIndex(char varName) const {
	return varName - '?';
}
