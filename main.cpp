#include <iostream>
#include <fstream>

bool *get_args(int argc, char* argv[]) {
    static bool flags[2] = {false, true};

    return flags;
}


float get_data(float * numbers[], int n, bool from_file) {
    if (from_file) {
        return 1;
    }
    return 0;
}


int main(int argc, char * argv[]) {
    bool* flags = get_args(argc, argv);
    std::cout << flags[0] << " " << flags[1] << std::endl;
}
