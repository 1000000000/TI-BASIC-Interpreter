#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <list>
#include <map>
#include <sstream>

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
	else return NAN;
}

double Tokenizer::unit_evaluate(const std::string& unit) {
	//Evaluates a single unit (variable or number)
	if (unit.size() == 1 && isVar(unit.c_str()[0])) {
		return vars[getVarIndex(unit.c_str()[0])];
	}
	return atof(unit.c_str());
}

/*
 * Parses the next unit or operation and returns its type.
 */
OpOrder Tokenizer::parseOp(std::stringstream& str) {
	char c = str.peek();
	if (c == '.' || isdigit(c)) {
		double temp;
		str >> temp;
		return UNITS;
	} else if (isupper(c)) {
		str.ignore();
		return UNITS;
	} else if (c == '(') {
		str.ignore();
		return PARENS;
	} else if (c == '!') {
		str.ignore();
		return FACTORIAL;
	} else if (c == '^') {
		str.ignore();
		return EXPONENT;
	} else if (c == ' ') {
		char substr[6];
		str.read(substr, 5);
		if (strcmp(substr, " nPr ") == 0 || strcmp(substr, " nCr ") == 0) {
			return COMBINATORICS;
		}
	} else if (c == '*' || c == '/') {
		str.ignore();
		return MULTIPLY_DIVIDE;
	} else if (c == '+' || c == '-') {
		str.ignore();
		return ADD_SUBTRACT;
	} else {
		str.ignore();
		return UNKNOWN;
	}
}


double Tokenizer::evaluate(const std::string& parsee) {
	std::stringstream str(parsee);
	std::map<OpOrder,std::list<unsigned> > ops;
	for (unsigned i = 0; i < parsee.size(); ++i) {
		
		if (parsee[i] == '(') {
			unsigned numOpen = 0, numClose = 0;
			while (
	return 4;
}

unsigned int Tokenizer::getVarIndex(char varName) const {
	return varName - '?';
}

bool Tokenizer::isVar(char varName) const {
	return varName >= '?' && varName <= 'Z';
}
