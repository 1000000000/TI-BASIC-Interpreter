#include <math.h>
#inlcude <cstdlib>

#include "Token.h"

double Tokenizer::operate(char operatorName, double val1) {
	//Unary operators
}

double Tokenizer::operate(char operatorName, double val1, double val2) {
	//Binary operators
	if (operatorName == '*') {return val1*val2;}
	else if (operatorName == '+') {return val1+val2;}
	else if (operatorName == '/') {return val1/val2;}
	else if (operatorName == '-') {return val1/val2;}
	else if (operatorName == '^') {return pow(val1, val2);}
}

double Tokenizer::unit_evaluate(const std::string& unit) {
	//Evaluates a single unit (variable or number)
	if (unit.size() == 1) {
		if (isVar(unit.c_str()[0])) {
			return vars[getVarIndex(unit.c_str()[0])];
		}
	} else {
		return atof(unit.c_str());
	}
}

double Tokenizer::evaluate(const std::string& parsee) {
	
	return 4;
}

unsigned int Tokenizer::getVarIndex(char varName) const {
	return varName - '?';
}

bool Tokenizer::isVar(char varName) const {
	return varName >= '?' && varName <= 'Z';
}
