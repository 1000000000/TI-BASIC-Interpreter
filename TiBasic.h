#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Token.h"

#ifndef __TiBasic_h_
#define __TiBasic_h_

class TiBasic {
	public:
		TiBasic(std::vector<std::string> programVector);
		void clrhome() const;
		void tiGoto(std::string label);
		void disp(std::string output) const;
		void prompt(char varName);
		void delvar(char varName);
		void runLine();
		void run();
		void pause() const;
	private:
		std::vector<std::string> fileSpace;
		unsigned line;
		std::map<std::string, unsigned> labels;
		int vars[28];
		Tokenizer parser; 
};

#endif //__TiBasic_h_
