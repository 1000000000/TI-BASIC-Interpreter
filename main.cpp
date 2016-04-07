#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TiBasic.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		TiBasic program(argv[1]);
		program.run();
	}
}
