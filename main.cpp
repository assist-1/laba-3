#include <iostream>
#include <cstdio>
#include <cstring>
#include "functions.h"
using std::cout;
using std::endl;
using std::cerr;
const char* flag[2] = { "--tofile", "--fromfile" };
int main(int argc, char** argv) {
    if (argc == 1) {
        cerr << "Error: there are no flags" << endl;
    }
    else if (argc == 2) {
        cerr << "Error: not much segments" << endl;
    }
    else if (argc == 3) {
        char* name = argv[2];
        if (!(strcmp(argv[1], flag[0]))) {
            readfromcin();
            readtofile(name);
            task();
        }
        else if (!strcmp(argv[1], flag[1])) {
            readfromfile(name);
            task();
        }
        else cerr << "Wrong flags" << endl;
    }
    else if (argc == 4) {
        if (!strcmp(argv[1], flag[0])) {
            if (!strcmp(argv[3], flag[1])) {
                char* name = argv[2];
                readfromcin();
                readtofile(name);
                readfromfile(name);
                task();
            }
            else {
                cerr << "Wrong flags" << endl;
            }
        }
        else {
            cerr << "Wrong flags" << endl;
        }
    }
    else if (argc == 5) {
        if ((!strcmp(argv[1], flag[1]))) {
            if ((!strcmp(argv[3], flag[0]))) {
                char* name1 = argv[2];
                char* name2 = argv[4];
                readfromfile(name1);
                readtofile(name2);
                task();
            }
            else {
                cerr << "Wrong flags" << endl;
            }
        }
        else {
            cerr << "Wrong flags" << endl;
        }
    }
    else {
        cerr << "Wrong flags" << endl;
    }
}
