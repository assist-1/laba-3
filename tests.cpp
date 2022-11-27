#include <iostream>
#include <fstream>
#include <cstring>
#include "engine.h"

using namespace std;

bool cmpFiles(char* fileName1, char* fileName2) {
    bool cmp = true;
    ifstream f1(fileName1);
    ifstream f2(fileName2);
    char ch1;
    char ch2;
    while (f1.get(ch1)) {
        
        if (!f2.get(ch2)) {
            cmp = false;
            break;
        }
        if (ch1 != ch2) {
            cmp = false;
            break;
        }
    }
    if (f2.get(ch2)) {
        cmp = false;
    }
    f1.close();
    f2.close();

    return cmp;
}

bool runTest(char* sourceFile, char* rightResultFile) {
    char* tmpFileName = new char[100];
    strcpy(tmpFileName, "tmp_file");
    doIt(sourceFile, true, tmpFileName);
    if (cmpFiles(tmpFileName, rightResultFile)) {
        return true;
    }
    return false;
}

void runAllTests() {
    char* source = new char[1024];
    char* dest = new char[1024];
    strcpy(source, "input1");
    strcpy(dest, "output1");
    if (runTest(source, dest)) {
        cout << "Test 1 passed" << endl;
    } else {
        cout << "Test 1 failed" << endl;
    }
    strcpy(source, "input2");
    strcpy(dest, "output2");
    if (runTest(source, dest)) {
        cout << "Test 2 passed" << endl;
    } else {
        cout << "Test 2 failed" << endl;
    }
    strcpy(source, "input3");
    strcpy(dest, "output3");
    if (runTest(source, dest)) {
        cout << "Test 3 passed" << endl;
    } else {
        cout << "Test 3 failed" << endl;
    }
}