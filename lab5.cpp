#include <iostream>
#include <cstring>
#include <fstream>
#include "f_add.h"
#include "engine.h"
#include "tests.h"

using namespace std;

int main(int argc, char** argv) {

    runAllTests();
    bool fromFile = false;
    bool toFile = false;
    char* fromFileName = new char[1024];
    char* toFileName = new char[1024];
    if(argc > 1) {
        if (strcmp(argv[1], "--fromFile") == 0) {
            if (argc == 2) {
                cout << "Не хватает параметров" << endl;
                return 1;
            }
            fromFile = true;
            fromFileName = argv[2];
        }
        if (strcmp(argv[1], "--toFile") == 0) {
            if (argc == 2) {
                cout << "Не хватает параметров" << endl;
                return 1;
            }
            toFile = true;
            toFileName = argv[2];
        }
        if(argc > 3) {
            if (strcmp(argv[3], "--fromFile") == 0) {
                if (argc == 4) {
                    cout << "Не хватает параметров" << endl;
                    return 1;
                }
                if (fromFile) {
                    cout << "Два раза --fromFile" << endl;
                    return 1;
                }
                fromFile = true;
                fromFileName = argv[4];
            }
            if (strcmp(argv[3], "--toFile") == 0) {
                if (argc == 4) {
                    cout << "Не хватает параметров" << endl;
                    return 1;
                }
                if (toFile) {
                    cout << "Два раза --toFile" << endl;
                    return 1;
                }
                toFile = true;
                toFileName = argv[4];
            }

        }        
    }
    if (!fromFile) {
        ofstream f1;
        f1.open("tmpFile");
        char* s = new char[1024];
        if (!f1.is_open()) {
            cout << "Проблемы с открытием файла" << endl;
            return 1;
        }
        cout << "Вводите предложения. После окончания текста, введите quit" << endl;
        while (true) {
            cin >> s;
            if (strcmp(s,"quit") == 0) {
                break;
            }
        f1 << s << endl;
        }
        f1.close();
        strcpy(fromFileName, "tmpFile");

    }
    doIt(fromFileName, toFile, toFileName);
    
    return 0;
}
