#include <iostream>
#include <cstring>
#include <fstream>
#include "lib.h"

int main(int argc, char** argv) {
    bool tofile = false;
    bool fromfile = false;
    int args = check_args(argc, argv);
    if(args == -1){
        std::cerr << "Wrong arguments.";
        return -1;
    }

    noskipws(std::cin);

    //считывание названий файлов при наличие флагов
    char* input_file = new char[50];
    if(args == 1 || args == 3){
        std::cout << "Please, type a filename to read from.\0";
        int i = 0;

        while(std::cin >> input_file[i]){
            ++i;
            if(std::cin.peek() == '\n'){
                break;
            }
        }
    }

    char* output_file = new char[50];
    if(args == 2 || args == 3){
        std::cout << "Please, type a filename to write in.\n";
        int i = 0;
        while(std::cin >> output_file[i]){
            ++i;
            if(std::cin.peek() == '\n'){
                break;
            }
        }
    }

    //считывание предложений
    char* str = new char[200];
    int** dots = new int*[200];
    int i = 0, dots_count = 0;
    int pre_start = 0;
    if(args == 1 || args == 3){
        std::ifstream input(input_file);
        noskipws(input);
        while(input >> str[i]){
            if(str[i] == '\n'){
                str[i] = ' ';
            }
            if(str[i] == '.'){
                dots[dots_count] = new int[3];
                dots[dots_count][0] = i - pre_start + 1;
                dots[dots_count][1] = pre_start; dots[dots_count][2] = i;
                pre_start = i + 1;
                ++dots_count;
            }
            ++i;
        }
    }
    else{
        while(std::cin >> str[i]){
            if(str[i] == '\n'){
                str[i] = ' ';
            }
            if(str[i] == '.'){
                dots[dots_count] = new int[3];
                dots[dots_count][0] = i - pre_start + 1;
                dots[dots_count][1] = pre_start; dots[dots_count][2] = i;
                pre_start = i + 1;
            }
            ++i;
        }
    }

    //учет неправильно ввода, то есть если предложений нет
    if(dots_count == 0){
        std::cerr << "Nothing founnd.";
        return -1;
    }

    //сортировка и вывод
    sort(dots, i);

    return 0;
}
