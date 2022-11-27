#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int mystrlen(char** arr) {
    int i = 0;
    while (arr[i] != NULL) {
        i++;
    }
    return i;
}
char** mystrcpy(char** arrnew, char** arr) {
    int i =0;
    while (arr[i] != NULL) {
        arrnew[i] = arr[i];
        i++;
    }
    arrnew[i] = NULL;
    return arrnew;

}

char* addchar(char* s, char ch, int* n) {
    if (strlen(s) == *n - 1) {
        *n += 100;
        char* snew = new char[*n];
        strcpy(snew, s);
        int x = strlen(s);
        delete s;
        snew[x] = ch;
        snew[x+1] = '\0';
        return snew;
    }
    int x = strlen(s);
    s[x] = ch;
    s[x+1] = '\0';
    return s;
}

char** addstring(char** arr, char* s, int* k) {
    if (mystrlen(arr) == *k - 1) {
        *k += 100;
        char** arrnew = new char*[*k];
        arrnew = mystrcpy(arrnew, arr);
        delete arr;
        arr = NULL;
        int x = mystrlen(arr);
        arrnew[x] = s;
        arrnew[x+1] = NULL;
        return arrnew;
    }
    int x = mystrlen(arr);
    arr[x] = s;
    arr[x+1] = NULL;
    return arr;
}

void sort(char** arr) {
    for (int i = 0; i < mystrlen(arr); i++) {
        for(int q = 0; q < mystrlen(arr)-1; q++) {
            if (strlen(arr[q]) > strlen(arr[q+1])) {
                char* t = arr[q];
                arr[q] = arr[q+1];
                arr[q+1] = t;
            }
        }
    }
    
}

void print(char** arr) {
    for(int i = 0; i < mystrlen(arr); i++) { 
        cout << arr[i] << endl;
    }
}

void to_file(char** arr, char* toFileName) {
    ofstream f3(toFileName);
    for(int i = 0; i < mystrlen(arr); i++) {    
        f3 << arr[i];  
        if (i != mystrlen(arr)-1) {
            f3 << endl;
        }
    }
    f3.close();
}