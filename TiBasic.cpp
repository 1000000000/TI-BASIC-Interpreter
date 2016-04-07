#include "TiBasic.h"

#include <limits>
#include <fstream>

TiBasic::TiBasic(char* fileName) : line(0), parser(vars) {
	std::fstream f;
	f.open(fileName);
	std::string curr_line;
	unsigned x = 0;
	while (getline(f, curr_line, ':')) {
		curr_line = ":"+curr_line;
		fileSpace.push_back(curr_line);
		//Set up labels for quicker access later
		if (curr_line.substr(0,5) == ":Lbl " and curr_line.size() > 5) {
			labels[curr_line.substr(5,0-1)] = x;
		}
		++x;
	}
	//Assign all the variables to zero
	for (unsigned x = 0; x < 28; ++x) {
		vars[x] = 0;
	}
}

void TiBasic::run() {
	//This runs the program from the current spot
	while (line < fileSpace.size()) {
		runLine();
	}
	std::cout << "Done\n";
}

void TiBasic::runLine() {
	//This runs a line of TiBasic
	std::string curr_line = fileSpace[line];
	if (curr_line.substr(0,5) == ":Lbl " and curr_line.size() > 5) {
		//Labels do nothing
		++line;
	} else if (curr_line.substr(0,6) == ":Goto " and curr_line.size() > 6) {
		tiGoto(curr_line.substr(6,0-1));
		++line;
	} else if (curr_line == ":ClrHome") {
		clrhome();
		++line;
	} else if (curr_line.substr(0,6) == ":Disp " and curr_line.size() > 6) {
		disp(curr_line.substr(6,0-1));
		++line;
	} else if (curr_line == ":Pause") {
		pause();
		++line;
	} else if (curr_line.substr(0,8) == ":Prompt " and curr_line.size() == 9) {
		prompt(curr_line.c_str()[9]);
		++line;
	} else if (curr_line.substr(0,8) == ":DelVar ") {
		delvar(curr_line.c_str()[9]);
	}
}

void TiBasic::delvar(char varName) {
	//Mimics ti-basic's DelVar function
	var(varName) = 0;
}

void TiBasic::prompt(char varName) {
	//Mimics ti-basic's Prompt function
	//'~'+107 is a theta
	std::string input = "";
	std::cout << varName << "=?";
	std::cin >> input;
	var(varName) = parser.evaluate(input);
}

void TiBasic::pause() const {
	//Mimics ti-basic's Pause function
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

void TiBasic::disp(std::string output) {
	//Mimics ti-basic's Disp function
	bool in_quotes = false;
	std::string chunk = "";
	for (unsigned x = 0; x < output.size(); ++x) {
		char current = output[x];
		if (current == ',' and !in_quotes) {
			//code here
			parser.evaluate(chunk);
		} else {
			if (current == '"') {
				in_quotes = !in_quotes;
			}
			chunk += current;
		}
	}
}

void TiBasic::tiGoto(std::string label) {
	//Mimics ti-basic's Goto function
	line = labels[label];
}

void TiBasic::clrhome() const {
	//Mimics ti-basic's ClrHome function
	std::cout << "\033[2J";
}

double& TiBasic::var(char varName) {
	return vars[parser.getVarIndex(varName)];
}
