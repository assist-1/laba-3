#include <cstring>
#include <fstream>
#include <iostream>

void selection_sort(int *arr, int size, int *points) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;

            t = points[i];
            points[i] = points[min_index];
            points[min_index] = t;
        }
    }
}

void print_string(const char *symbols, int point, std::ostream &output_stream) {
    int l = point;
    while (l > 0 && symbols[l - 1] != '.') {
        l--;
    }
    while (symbols[l] == ' ' || symbols[l] == '\n') {
        l++;
    }
    for (int l2 = l; l2 < point + 1; l2++) {
        output_stream << symbols[l2];
    }
    output_stream << std::endl;
}

void mirror_string(char *s, int begin, int end) {
    int mid = begin + (end - begin) / 2;
    for (int i = 0; i < mid - begin; ++i) {
        int left = begin + i;
        int right = begin + (end - begin) - i - 1;
        char t = s[left];
        s[left] = s[right];
        s[right] = t;
    }
}

void nine_txt(char *symbols, int right_point) {
    int left = right_point;
    while (left > 0 && symbols[left - 1] != '.') {
        --left;
    }
    while (symbols[left] == ' ' || symbols[left] == '\n') {
        ++left;
    }
    mirror_string(symbols, left, right_point);
    int right = left + 1;
    while (right < right_point) {
        while (symbols[right] != ' ' && symbols[right] != '.') {
            ++right;
        }
        mirror_string(symbols, left, right);
        left = right;
        while (left < right_point && symbols[left] == ' ') {
            ++left;
        }
        right = left + 1;
    }

    std::ofstream ofs("NINE.txt");
    print_string(symbols, right_point - 1, ofs);
}

int point_coordinate(const char *symbols, int *points) {
    int k = 0;
    for (int j = 0; j < std::strlen(symbols); j++) {
        if (symbols[j] == '.') {
            points[k] = j;
            k++;
        }
    }
    return k;
}

void result(char *symbols, std::ostream &output_stream) {
    int points[100];
    int count = point_coordinate(symbols, points);
    int len[100];
    for (int k = 0; k < count; k++) {
        int l = points[k];
        while (l > 0 && symbols[l - 1] != '.') {
            l--;
        }
        while (symbols[l] == ' ' || symbols[l] == '\n') {
            l++;
        }
        len[k] = points[k] - l + 1;
    }
    selection_sort(len, count, points);
    for (int k = 0; k < count; k++) {
        print_string(symbols, points[k], output_stream);
    }

    nine_txt(symbols, points[count - 1]);
}

int main(int argc, char **argv) {
    bool tofile = false;
    bool fromfile = false;
    char *tofilename = nullptr;
    char *fromfilename = nullptr;
    for (std::size_t i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--tofile") == 0) {
            tofile = true;
            if (((i + 1) < argc) && (std::strcmp(argv[i + 1], "--fromfile") != 0)) {
                tofilename = argv[i + 1];
                ++i;
            }
        } else if (std::strcmp(argv[i], "--fromfile") == 0) {
            fromfile = true;
            fromfilename = argv[i + 1];
            ++i;
        } else {
            std::cerr << "Unexpected argument: " << argv[i] << "\n";
            return EXIT_FAILURE;
        }
    }
    char symbols[10000];
    if (fromfile) {
        std::ifstream input_stream(fromfilename);
        if (!input_stream) {
            std::cerr << "Can't open file: " << fromfilename << std::endl;
            return EXIT_FAILURE;
        }
        input_stream.getline(symbols, 10000, EOF);
    } else {
        std::cout << "Enter the text" << "\n" << "To mark the end of the input, type '^' and press Enter" << "\n"
                  << std::endl;
        std::cin.getline(symbols, 10000, '^');
    }
    for (int i = 0; symbols[i] != '\0'; ++i) {
        if (symbols[i] == '\n') {
            symbols[i] = ' ';
        }
    }
    if (tofile) {
        std::ofstream ofs;
        if (tofilename) {
            ofs.open(tofilename);
        } else {
            ofs.open("tofile.txt");
        }
        result(symbols, ofs);
        ofs.close();
    } else {
        result(symbols, std::cout);
    }

    return EXIT_SUCCESS;
}
