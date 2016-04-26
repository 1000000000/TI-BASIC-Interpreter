#ifndef _token_h__
#define _token_h__

#include <string>

enum Symbols {
	TS_LEFT_PARENS,
	TS_RIGHT_PARENS,
	TS_FACTORIAL,
	TS_UNIT,
	TS_END,
	NTS_START,
	UNKNOWN
};

class Tokenizer {
	public:
		Tokenizer(double var_vals[]) : vars(var_vals) {}
		unsigned int getVarIndex(char varName) const;
		bool isVar(char varName) const;
		double unit_evaluate(const std::string& unit);
	private:
		double* vars;
};

#endif // ifndef _token_h__
