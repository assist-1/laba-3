#include <iostream>
#include <cstring>
#include "func.h"

int main(int argc, char**argv) 
{ 
    std::cout << "Программа читает только из файла fromfile.txt и записывает только в файл tofile.txt, если имеются соответствующие флаги! :)\n"; 
    if (argc == 1) { 
        read_cin(); 
        func(0); 
        exit(0); 
    } 
    else { 
        if (argc == 2) {
            if (strcmp(argv[1], "--tofile") == 0) { 
                read_cin(); 
                func(1); 
                exit(0); 
            } 
            else if (strcmp(argv[1], "--fromfile") == 0) { 
                read_file(); 
                func(0); 
                exit(0); 
            } 
        }
        else if (argc == 3) {
            if (strcmp(argv[1], "--tofile") == 0 && strcmp(argv[2], "--fromfile") == 0 || 
                strcmp(argv[2], "--tofile") == 0 && strcmp(argv[1], "--fromfile") == 0) { 
                if (read_file()) 
                    exit(1); 
                func(1); 
                exit(0); 
            }
            else exit(1);
        }  
    } 
     
}