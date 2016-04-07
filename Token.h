#ifndef _token_h__
#define _token_h__

#include <string>

class Tokenizer {
	public:
		Tokenizer(double vars[]);
		double evaluate(const std::string& parsee) const;
		unsigned int getVarIndex(char varName) const;

};

#endif // ifndef _token_h__
