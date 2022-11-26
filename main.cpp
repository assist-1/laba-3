#include <iostream>
#include <cstring>
#include <fstream>
#include "func.h"

int main(int argc, char** argv) {
    if (checkflag(argc, argv) == 0)
        return 0;
    int n, i = 0;
    std::ifstream fin("input.txt");
    if (argc == 1 || argc == 2 && strcmp(argv[1], "--fromfile"))
        std::cin >> n;
    else
        fin >> n;
    n = n * 2;
    double* seg = new double[n];
    if (argc == 1 || argc == 2 && strcmp(argv[1], "--fromfile"))
        for (int i = 0; i < n; ++i)
            std::cin >> seg[i];
    if (argc == 3 || argc == 2 && strcmp(argv[1], "--fromfile") == 0)
        while (!fin.eof()){
            fin >> seg[i];
            ++i;
        }
    sortmas(seg, n);
    if (checkmas(seg, n) == 0)
      return 0;
    conjunction(seg, n, argc, argv);
    delete []seg;
}