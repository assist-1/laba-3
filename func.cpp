#include <iostream>
#include <cstring>
#include <fstream>

void sortmas(double* seg, int n){
    for (int i = 0; i < n; i += 2){
        for (int j = 0; j < n - i - 2; j += 2){
            if (seg[j] > seg[j + 2]) {
                std::swap(seg[j], seg[j + 2]);
                std::swap(seg[j + 1], seg[j + 3]);
            }
        }
    }
}

void conjunction(double* seg, int n, int &f, int argc, char**argv){
    std::ofstream fout("output.txt");
    for (int i = 1; i < n - 2; i += 2){
        if (seg[i] >= seg [i + 1]){
            seg[i + 1] = seg [i - 1];
            seg [i + 2] = std::max(seg[i], seg[i + 2]);
            seg[i - 1] = seg [i] = 0.001;
            f = 1;
        } else {
            if (f == 1){
                if (argc == 3 || argc == 2 && (strcmp(argv[1], "--tofile") == 0)) {
                    fout << seg[i - 1] << " " << seg[i] << "\n";
                    f = 0;
                }
                else {
                    std::cout << seg[i - 1] << " " << seg[i] << "\n";
                    f = 0;
                }
            }
        }
    }
    if (f == 1){
        if (argc == 3 || argc == 2 && (strcmp(argv[1], "--tofile") == 0))
            fout << seg[n - 2] << " " << seg[n - 1] << "\n";
        else
            std::cout << seg[n - 2] << " " << seg[n - 1] << "\n";
    }
}
int checkflag(int argc, char** argv){
    if (argc < 1 || argc > 3){
        std::cerr << "Wrong quantity of flags. Try again";
        return 0;
    }
    if (argc == 2)
        if (strcmp(argv[1], "--fromfile") != 0 && strcmp(argv[1], "--tofile") != 0){
            std::cerr << "Wrong flags. Try again";
            return 0;
        }
    if (argc == 3){
        if (strcmp(argv[1], "--fromfile") && strcmp(argv[1], "--tofile")
        || strcmp(argv[2], "--fromfile") && strcmp(argv[2], "--tofile")
        || strcmp(argv[1], argv[2]) == 0){
            std::cerr << "Wrong flags. Try again";
            return 0;
        }
    }
    return 1;
}

int checkmas (double* seg, int n){
    for (int i = 0; i < n - 1; i += 2){
        if (seg[i] > seg[i + 1]){
            std::cerr << "Wrong expression. Try again";
            return 0;
        }
    }
    return 1;
}