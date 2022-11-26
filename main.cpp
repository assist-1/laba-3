#include <iostream>
#include <cstring>
#include "functions.h"
int main(int argc, char ** argv) {
	const char * flags[3] = {"--default", "--tofile", "--fromfile"};

	if(argc == 2) {
		if(!strcmp(argv[1], flags[0])) {
			std::cout << "Please enter the number of segments and then the segments:" << std::endl;
			GetResultFromConsole();
		}
		else {
			std::cerr << "ERROR: invalid flag!" << std::endl;
			exit(1);
		}
	}
	return 0;
}