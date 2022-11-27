#include <iostream>
#include "func.h"
#include <cstring>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
const char* flags[2] = {"--fromfile","--tofile"};
int main(int argc, char*argv[]){
    if (argc == 1){
        cerr << "The flag no found" << endl;
    }
    else if (argc == 2){
        if (!strcmp(argv[1],flags[1])){
            cerr << "You don't entered name_file" << endl;
            ToUsage();
        }
        else if (!strcmp(argv[1],flags[0])){
            cerr << "You don't entered name_file" << endl;
            FromUsage();
        }
        else {
            cerr << "You entered wrong flag" << endl;
            CommonUsage();
        }
    }
    else if (argc == 3){
        char *namefile = argv[2];
        if (!strcmp(argv[1],flags[1]))     ToFile(namefile);
        else if (((!strcmp(argv[1],flags[0])) && (!strcmp(argv[2],flags[1]))) ||
                ((!strcmp(argv[1],flags[1])) && (!strcmp(argv[2],flags[0])))){
                cerr << "Need to entered name for both files" << endl;;
                FromToUsage();
                }
        else if (!strcmp(argv[1],flags[0]))     FromFile(namefile);
        else cerr << "You entered wrong flag" << endl;
    }
    else if (argc == 5){
        char *in_file = argv[2];
        char *to_file = argv[4];
        if ((!strcmp(argv[1],flags[0])) && (!strcmp(argv[3], flags[1]))) {
            FromAndToFile(in_file,to_file);
        }
        else {
        cerr << "Entered Error" << endl;
        FromToUsage();
        }
    }
    else {
        cerr << "You entered wrong count of flags" << endl;
        CommonUsage();



}
}
