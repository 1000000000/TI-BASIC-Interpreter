#ifndef _token_h__
#define _token_h__

#include <string>

enum OpOrder {UNKNOWN, UNITS, PARENS, FACTORIAL, EXPONENT, COMBINATORICS, MULTIPLY_DIVIDE, ADD_SUBTRACT};

class Tokenizer {
	public:
		Tokenizer(double var_vals[]) : vars(var_vals) {}
		double evaluate(const std::string& parsee);
		unsigned int getVarIndex(char varName) const;
		bool isVar(char varName) const;
		double operate(char operatorName, double val1);
		double operate(char operatorName, double val1, double val2);
		double unit_evaluate(const std::string& unit);
	private:
		double* vars;
};

#endif // ifndef _token_h__
