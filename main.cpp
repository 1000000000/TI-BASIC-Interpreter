#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TiBasic.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		std::fstream f;
		f.open(argv[1]);
		std::vector<std::string> programVector;
		std::string line;
		while (getline(f, line)) {
			programVector.push_back(line);
		}
		TiBasic program(programVector);
		program.run();
	}
}
