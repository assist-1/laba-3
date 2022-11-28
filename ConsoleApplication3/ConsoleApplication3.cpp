#include <fstream>
#include <cstring>
#include <iostream>
#include "fun.h"

int main(int argc, char *argv[]){
    float begin[10000], end[10000], begin1[10000], end1[10000];
    int n;
    if (argc > 1) {
        if ((strcmp(argv[1], "--fromfile") == 0)) {
            std::ifstream fin(argv[2]);
            if (!fin)
            {
                std::cout << "Incorrect input (0)";
                return 0;
            }
            fin >> n;
            for (int i = 0; i < n; i++) {
                fin >> begin[i] >> end[i];
                if (begin[i] > end[i]) {
                    std::cout << "Incorrect input (1)";
                    return 0;
                }
            }
            fin.close();
        }
    }
    else {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> begin[i] >> end[i];
            if (begin[i] > end[i]) {
                std::cout << "Incorrect input (1)";
                return 0;
            }
        }
    }sort(begin, end, n);
    int j = 0;
    float help_end = end[0], help_begin = begin[0];
    for (int i = 1; i < n; i++) {
        if (begin[i] < help_end) {
            if (help_end < end[i]) help_end = end[i];
        }
        else {
            begin1[j] = help_begin;
            end1[j] = help_end;
            help_end = end[i];
            help_begin = begin[i];
            j++;
        }
    }begin1[j] = help_begin;
    end1[j] = help_end;
    bool flag = true;
    if (argc > 1) {
        if ((strcmp(argv[1], "--tofile") == 0)) {
            output(argv[2], begin1, end1, j);
            flag = false;
        }
    }if (argc > 3) {
        if ((strcmp(argv[3], "--tofile") == 0)) {
            output(argv[4], begin1, end1, j);
            flag = false;
        }
    }if (flag) {
        for (int i = 0; i <= j; i++) {
            std::cout << begin1[i] << " " << end1[i] << std::endl;
        }
    }
}