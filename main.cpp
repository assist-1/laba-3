#include <iostream>
#include <cstring>
#include "functions.h"

int main(int argc, char ** argv) {
	const char * flags[5] = {"--help", "--default", "--tofile", "--fromfile", "DefaultFile.txt"};
	if(argc == 1) {
		std::cerr << "ERROR: flag not found!"                          << std::endl;
		std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
		exit(1);
	}
	else if(argc == 2) {
		if(!strcmp(argv[1], flags[0])) {
			Help();
		}
		else if(!strcmp(argv[1], flags[1])) {
			std::cout << "Please enter the number of segments and then the segments:" << std::endl;
			GetResultFromConsole();
		}
		else if(!strcmp(argv[1], flags[2])) {
			std::cout << "Please enter the number of segments and then the segments:" << std::endl;
			GetResultFromConsole(flags[4], 0);
		}
		else if (!strcmp(argv[1], flags[3])) {
			std::cerr << "ERROR: You must enter the file name for flag '--fromfile'!" << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-"            << std::endl;
			exit(1);
		}
		else {
			std::cerr << "ERROR: invalid input!"                           << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
			exit(1);
		}
	}
	else if(argc == 3) {
		if(!strcmp(argv[1], flags[2])) {
			std::cout << "Please enter the number of segments and then the segments:" << std::endl;
			GetResultFromConsole(argv[2], 1);
		}
		else if(!strcmp(argv[1], flags[3])) {
			GetResultFromFile(argv[2]);
		}
		else if(!strcmp(argv[1], flags[0]) || !strcmp(argv[1], flags[1])) {
			std::cerr << "ERROR: this flag doesn't need another argument!" << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
			exit(1);
		}
		else {
			std::cerr << "ERROR: invalid input!"                           << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
			exit(1);
		}
	}
	else if(argc == 4) {
		if(!strcmp(argv[1], flags[3]) && !strcmp(argv[3], flags[2])) {
			GetResultFromFile(argv[2], flags[4], 0);
		}
		else {
			std::cerr << "ERROR: invalid input!"                           << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
			exit(1);
		}
	}
	else if(argc == 5) {
		if(!strcmp(argv[1], flags[3]) && !strcmp(argv[3], flags[2])) {
			GetResultFromFile(argv[2], argv[4], 1);
		}
		else {
			std::cerr << "ERROR: invalid input!" << std::endl;
			std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
			exit(1);
		}
	}
	else {
	std::cerr << "ERROR: invalid input!" << std::endl;
	std::cerr << "-You can enter '--help' for instruction output-" << std::endl;
	exit(1);
	}
	return 0;
}