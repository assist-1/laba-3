#include <iostream>
#include <cstring>
#include "functions.h"

int main(int argc, char ** argv) {
    switch (argc) {
        case 1:
            if (read()) exit(1);
            solver(0, "no");
        case 3:
            if (!strcmp("--tofile", argv[1])) {
                if (read()) exit(1);
                solver(1, argv[2]);
            }
            else if (!strcmp("--fromfile", argv[1])) {
                if (read(argv[2])) exit(1);
                solver(0, "no");
            }
            else {
                std::cerr << "### Wrong flags ###\n";
                usage();
                exit(1);
            }
            exit(0);
        case 5:
            if (!strcmp("--fromfile", argv[1]) && 
                !strcmp("--tofile", argv[3])) {
                if (read(argv[2])) exit(1);
                solver(1, argv[4]);
            }
            else if (!strcmp("--fromfile", argv[3]) && 
                     !strcmp("--tofile", argv[1])) {
                if (read(argv[4])) exit(1);
                solver(1, argv[2]);
            }
            else {
                std::cerr << "### Wrong flags ###\n";
                usage();
                exit(1);
            }
            exit(0);
        default:
            std::cerr << "### Wrong flags 1 ###\n";
            usage();
            exit(1);
    }
}
