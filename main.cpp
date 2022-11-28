#include <iostream>
#include <fstream>
#include "sort.cpp"
#include "parse.cpp"

bool* get_args(int argc, char* argv[]) {
    static bool flags[2] = {false, true};

    return flags;
}

int main(int argc, char* argv[]) {
    bool* flags = get_args(argc, argv);
    // std::cout << flags[0] << " " << flags[1] << std::endl;
    std::ifstream input("input.txt");
    int T;
    // std::cin >> T;
    input >> T;
    float* lower = new float[T];
    float* upper = new float[T];
    float a, b;

    for (int i = 0; i < T; ++i) {
        input >> a >> b;
        lower[i] = a;
        upper[i] = b;
    }

    sort(lower, T, upper, T);
    
    int ans_c = 0;
    float* ans = parse(lower, T, upper, T, &ans_c);
    
    if (ans_c) {
        for (int i = 0; i < ans_c; i += 2) {
            std::cout << ans[i] << ' ' << ans[i + 1] << std::endl;
        }
    }
    else {
        std::cout << "NOTHING FOUND" << std::endl;
    }
}
