#include <iostream>
#include <fstream>
#include "sort.cpp"
// #include "parse.cpp"

bool* get_args(int argc, char* argv[]) {
    static bool flags[2] = {false, true};

    return flags;
}


float max(float a, float b) {
    if (a >= b) return a;
    else return b;
}


int parse(float lower[], int n1, float upper[], int n2, 
            float ans_low[], int n3, float ans_up[], int n4) {
    
    int ans_count = 0;
    bool intersected = false;
    for (int i = 0; i < n1 - 1; ++i) {
        if (lower[i] <= lower[i + 1] <= upper[i]) {
            ans_low[ans_count] = lower[i];
            ans_up[ans_count] = max(upper[i], upper[i + 1]);
            intersected = true;
        }
    }

    return ans_count;
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
    
    int ans_maxlen = T / 2 + 1;
    float* ans_lower = new float[ans_maxlen];
    float* ans_upper = new float[ans_maxlen];
    
    
    int ans_n = parse(lower, T, upper, T, ans_lower, ans_maxlen, ans_upper, ans_maxlen);
    
    for (int i = 0; i < ans_n; ++i) {
        std::cout << ans_lower[ans_n] << '\t' << ans_upper[ans_n] << std::endl;
    }
}
