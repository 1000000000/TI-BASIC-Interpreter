#ifndef __TiBasic_h_
#define __TiBasic_h_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Token.h"

class TiBasic {
	public:
		TiBasic(char* fileName);
		void clrhome() const;
		void tiGoto(std::string label);
		void disp(std::string output);
		void prompt(char varName);
		void delvar(char varName);
		void runLine();
		void run();
		void pause() const;
	private:
		std::vector<std::string> fileSpace;
		unsigned line;
		std::map<std::string, unsigned> labels;
		double vars[28];
		Tokenizer parser; 

		double& var(char varName);
};

#endif //__TiBasic_h_
