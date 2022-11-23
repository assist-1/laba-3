#include "functions.hpp"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 5) {
        std::cerr << "Incorrect enter!" << std::endl;
        return -1;
    }
    if (strcmp(argv[1], "--tofile") == 0 && argc < 5) {
        if (argc == 2) {
            std::ofstream out("F");
            TaskToFile(out);
        } else {
            std::ofstream out(argv[2]);
            TaskToFile(out);
        }
    }
    if (strcmp(argv[1], "--fromfile") == 0 && argc == 3) {
        std::ifstream in(argv[2]);
        TaskFromFile(in);
    }
    if (argc >= 3 && ((strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2], "--tofile") == 0) ||
                      (strcmp(argv[2], "--fromfile") == 0 && strcmp(argv[1], "--tofile") == 0))) {
        if (argc == 3) {
            std::fstream inOut("F");
            TaskFromToFile(inOut);
        } else {
            std::fstream inOut(argv[3]);
            TaskFromToFile(inOut);
        }

    }
    return 0;
}
