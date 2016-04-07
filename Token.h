#ifndef _token_h__
#define _token_h__

#include <string>

class Tokenizer {
	public:
		Tokenizer(double var_vals[]) : vars(var_vals) {}
		double evaluate(const std::string& parsee);
		unsigned int getVarIndex(char varName) const;
		bool isVar(char varName) const;

	private:
		double* vars;
};

#endif // ifndef _token_h__
