#include <iostream>
#include <cstring>
#include "functions.hpp"


int main(int argc, char ** argv) {
    switch (argc) {
        case 1:
            if (!strcmp("--fromfile", argv[1]) && !strcmp("--tofile", argv[3])) {
                if (read(argv[2])) exit(1);
                solve(1, argv[4]);
                }
            else if (!strcmp("--fromfile", argv[3]) && !strcmp("--tofile", argv[1])) {
                if (read(argv[4])) exit(1);
                solve(1, argv[2]);
            }
            else {
                std::cerr << ">>> Wrong flags <<<\n";
                exit(1);
            }
            break;
        case 2:
            if (!strcmp("--tofile", argv[1])) {
                if (read()) exit(1);
                solve(1, argv[2]);
            }
            else if (!strcmp("--fromfile", argv[1])) {
                if (read(argv[2])) exit(1);
                solve(0, "NO");
            }
            else {
                std::cerr << ">>> Wrong flags <<<\n";
                exit(1);
            }
            break;
        case 3:
            if (read()) exit(1);
            solve(0, "NO");
            break;
        default:
            std::cerr << ">>> Wrong flags <<<\n";
            exit(1);
    }

    exit(0);
}
