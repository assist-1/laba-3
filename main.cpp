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

    int T;
    std::cin >> T;
    float* lower = new float[T];
    float* upper = new float[T];
    float a, b;

    for (int i = 0; i < T; ++i) {
        std::cin >> a >> b;
        lower[i] = a;
        upper[i] = b;
    }

    sort(lower, T, upper, T);

    for (int i = 0; i < T; ++i) {
        std::cout << lower[i] << '\t' << upper[i] << std::endl;
    }
    
    int ans_maxlen = T / 2 + 1;
    float* ans_lower = new float[ans_maxlen];
    float* ans_upper = new float[ans_maxlen];
    
    parse(lower, T, upper, T, ans_lower, ans_maxlen, ans_upper, ans_maxlen);

    return 0;
}
