#include <iostream>
#include "Header.h"
#include <cstring>
int arc;
char** arg;
int main(int argc, char** argv) {
	arc = argc;
	arg = argv;
	if (argc >= 4 && argc <=5 && strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2], "--tofile") == 0) Fromtofile();
	else if (argc == 3 && strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2],"--tofile")!=0) Fromfile();
	else if (argc >=2 && argc <=3 && strcmp(argv[1], "--tofile") == 0) Tofile();
	else std::cout << "Error! You entered the flags either incorrectly, or in the wrong sequence, or too little." << std::endl;
	return 0;
}