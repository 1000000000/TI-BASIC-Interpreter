#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef __TiBasic_h_
#define __TiBasic_h_

class TiBasic {
	public:
		TiBasic(std::vector<std::string> programVector);
		void clrhome();
		void tiGoto(std::string label);
		void disp(std::string output);
		void runLine();
		void run();
		void pause();
	private:
		std::vector<std::string> fileSpace;
		unsigned line;
		std::map<std::string, unsigned> labels;
		int vars[28]; 
};

#endif //__TiBasic_h_
