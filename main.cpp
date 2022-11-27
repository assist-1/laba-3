#include <iostream>
#include "func.h"
#include <cstring>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
const *char flags[2] = {"--fromfile","--tofile"}
int main(int argc, char*argv[]){
    if (argc == 1){
        cerr << "The flag no found" << endl;
    }
    else if (argc == 2){
        if (!strcmp(argv[1],flags[1])){
            ToFile();
        }
        else if (!strcmp(argv[1],flags[0])){
            FromFile()
        }
        else {
            cerr << "You entered wrong flag" << endl;
        }
    }
    else if (argc == 3){
        char *namefile = argv[2];
        if (!strcmp(argv[1],flag[1])){
            ToFile(namefile);
        }
        else cerr << "You entered wrong flag" << endl;
    }
    else cerr << "You entered many flags";

}
