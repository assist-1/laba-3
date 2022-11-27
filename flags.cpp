#include <iostream>
#include <cstring>
#include <fstream>
#include "Header.h"
bool tofile=false;
bool fromfile=false;
int main(int argc, char **argv){
    if (argc==1){
        std::cerr << "Nothing was read!"<<std::endl;
        return EXIT_FAILURE;
    }
    if (argc==3 && !strcmp(argv[1],"--tofile"))
    {
        tofile=true;
        func(argv);
    }
    else if (argc==3 && !strcmp(argv[1],"--fromfile"))
    {
        fromfile=true;
        func(argv);
    }
    else if (argc==5 && !strcmp(argv[1],"--fromfile") && !strcmp(argv[3],"--tofile"))
    {
        tofile=true;
        fromfile=true;
        func(argv);
    }
    else{
        std::cerr<<"The flag was entered incorrectly"<<std::endl;
        return EXIT_FAILURE;
    }
}

