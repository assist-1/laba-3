#include <iostream>
#include <cstring>
#include <fstream>
#include "f_add.h"
#include "dop.h"

using namespace std;

void doIt(char* fromFileName, bool toFile, char* toFileName) {
    ifstream f;
    f.open(fromFileName);
    if (!f) {
        cout << "Could not open file - " << fromFileName << endl;
        return void();
    }
    int n = 100;
    int k = 100;
    char ch;
    char* s = new char[n];
    s[0] = '\0';
    char** arr = new char*[k];
    arr[0] = NULL;
    while(f.get(ch)) {
        if (ch == '\n') {
            ch = ' ';
        }
        s = addchar(s, ch, &n);
        if (ch == '.') {
            arr = addstring(arr, s, &k);
            n = 100;
            s = new char[n];
            s[0] = '\0';
        }
    }
    for (int i = 0; i < mystrlen(arr); i++) {
        if (arr[i][0] == ' ') {
            arr[i] ++;
        }
    }
    sort(arr);
    char* longest = reverse_words(arr[mystrlen(arr)-1]);
    ofstream fn("Nine.txt");
    fn << longest;
    fn.close();
    if (toFile) {
        to_file(arr, toFileName);
        } else {
            print(arr);
            }

}