#include <iostream>
#include <fstream>
#include <cstring>
#include "sort.cpp"
#include "parse.cpp"


int main(int argc, char* argv[]) {
    char* input_path;
    char* output_path;
    bool flags[2] = {false,  // --fromfile
                     false}; // --tofile
    int input_path_index;
    int output_path_index;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp("--fromfile", argv[i]) == 0) {
                input_path = argv[i + 1];
                flags[0] = true;
                ++i;
            }
            if (strcmp("--tofile", argv[i]) == 0) {
                output_path = argv[i + 1];
                flags[1] = true;
                ++i;
            }
        }
    }
    
    std::ifstream input(input_path);
    std::ofstream output(output_path);

    if (!input) {
        std::cerr << "Wrong input file name. Try again." << std::endl;
        exit(-1);
    }

    
    int T;
    if (flags[0]) input >> T;
    else std::cin >> T;


    float* lower = new float[T];
    float* upper = new float[T];
    float a, b;

    for (int i = 0; i < T; ++i) {
        if (flags[0]) input >> a >> b;
        else std::cin >> a >> b;
        lower[i] = a;
        upper[i] = b;
    }

    bubbleSort(lower, T, upper, T);
    
    int ans_c = 0;
    float* ans = parse(lower, T, upper, T, &ans_c);
    
    if (ans_c) {
        for (int i = 0; i < ans_c; i += 2) {
            if (flags[1]) {
                output << ans[i] << ' ' << ans[i + 1] << std::endl;
            }
            else {
                std::cout << ans[i] << ' ' << ans[i + 1] << std::endl;
            }
        }
    }
    else {
        if (flags[1]) {
            output << "NOTHING FOUND" << std::endl;
        }
        else std::cout << "NOTHING FOUND" << std::endl;
    }
    if (flags[0]) input.close();
    if (flags[1]) output.close();
}