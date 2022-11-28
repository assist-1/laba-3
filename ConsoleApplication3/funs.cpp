#include <fstream>
#include "fun.h"

void sort(float begin[], float end[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (begin[j] > begin[j + 1]) {
                float temp = begin[j];
                begin[j] = begin[j + 1];
                begin[j + 1] = temp;
                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }
}

void output(char* f, float a[], float b[], int n) {
    std::ofstream fou(f);
    for (int i = 0; i <= n; i++) {
        fou << a[i] << " " << b[i] << "\n";
    }
}