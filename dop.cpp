#include <iostream>
#include <cstring>

using namespace std;

char* AddStr(char* s1, char* s2, int n) {
    int k1, k2;
    k1 = strlen(s1);
    k2 = strlen(s2);
    char* sre = new char[k1 + k2 + 2];
    strncpy(sre, s2, n);
    sre[n] = '\0';
    strcat(sre, " ");
    sre[n+1] = '\0';
    strcat(sre, s1);
    sre[k1 + k2 + 1] = '\0';
    return sre;
}

char* reverse_words(char* strch) {
    char* output = new char[strlen(strch) + 1];
    output[0] = '\0';
    int i = 0;
    while (i < strlen(strch)) {
        if (strch[i] != ' ') {
            i++;
            continue;
        }
        output = AddStr(output, strch, i);
        strch += i + 1;
        i = 0;
    }
    output = AddStr(output, strch, strlen(strch));
    return output;
}