#include "TiBasic.h"

int evaluate(std::string) {
	
}

TiBasic::TiBasic(std::vector<std::string> programVector) {
	fileSpace = programVector;
	line = 0;
	//Set up labels for quicker access later
	for (unsigned x = 0; x < fileSpace.size(); ++x) {
		std::string curr_line = fileSpace[x];
		if (curr_line.substr(0,5) == ":Lbl " and curr_line.size() > 5) {
			labels[curr_line.substr(5,0-1)] = x;
		}
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
	std::cout << "Done";
}

void TiBasic::runLine() {
	//This runs a line of TiBasic
	std::string curr_line = fileSpace[line];
	if (curr_line.substr(0,5) == ":Lbl " and curr_line.size() > 5) {
		//Labels do nothing
		++line;
	} else if (curr_line.substr(0,6) == ":Goto " and curr_line.size() > 6) {
		tigoto(curr_line.substr(6,0-1));
		++line;
	} else if (curr_line == ":ClrHome") {
		clrhome();
		++line;
	} else if (curr_line.substr(0,6) == ":Disp " and curr_line.size() > 6) {
		disp(curr_line.substr(6,0-1));
	}
}

void TiBasic::disp(std::string output) {
	//Mimics ti-basic's Disp function
	bool in_quotes = false;
	std::string chunk = "";
	for (unsigned x = 0; x < output.size(); ++x) {
		char current = output[x];
		if (current == ',' and !in_quotes) {
			//code here
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

void TiBasic::clrhome() {
	//Mimics ti-basic's ClrHome function
	std::cout << "\033[2J";
}
