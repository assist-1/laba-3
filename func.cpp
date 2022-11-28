#include "header.h"

void swap(double *first, double *second, int n) {
    double x, y;
    for (int j = 1; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (first[k] > first[k + 1]) {
                x = first[k];
                first[k] = first[k + 1];
                first[k + 1] = x;
                y = second[k];
                second[k] = second[k + 1];
                second[k + 1] = y;
            }
        }
    }
}

void del(double *first, double *second, int n, int k){
    for (int h = k; h < n; ++h) {
        first[h] = first[h+1];
        second[h] = second[h+1];
    }
}

void res(double *first, double *second, double *otv, int k, int i) {
    otv[k] = first[i];
    otv[k+1] = second[i];
}