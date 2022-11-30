#include"Lab2.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    if (!strcmp(argv[1], "--fromfile")) {
        Function(argv[2]);
    }
    else if(!strcmp(argv[1], "--tofile")) {
        Function2(argv[2]);
    }
    else {
        std::cout << "Вы сделали что-то не то)))" << std::endl;
    }
    return 0;
}

