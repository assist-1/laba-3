#include <fstream>
#include <iostream>
#include <cstring>
#include "lab5.h"
int flag_read = 0;
int flag_write = 0;
int main(int argc, char* argv[])
{
    if (argc == 1) { allright(argv); }
    else if (argc > 5) {
        std::cout << "ERROR! Too many flags" << std::endl;
        return -1;
    }
    else if (argc == 3) {
        if (!strcmp(argv[1], "--tofile")) {
            flag_write = 1;
            allright(argv);
        }
        else if (!strcmp(argv[1], "--fromfile")) {
            flag_read = 1;
            allright(argv);
        }
        else {
            std::cout << "ERROR! Flags are not correct" << std::endl;
            return -1;
        }
    }
    else {
        if (!strcmp(argv[3], "--tofile") && !strcmp(argv[1], "--fromfile")) {
            flag_read = 1;
            flag_write = 1;
            allright(argv);
        }
        else {
            std::cout << "ERROR! Flags are not correct" << std::endl;
            return -1;
        }
    }
    return 0;
}

