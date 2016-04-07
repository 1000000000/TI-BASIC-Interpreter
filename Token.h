#ifndef _token_h__
#define _token_h__

#include <string>

class Tokenizer {
	public:
		Tokenizer();
		double evaluate(std::string parsee) const;

};

#endif // ifndef _token_h__
