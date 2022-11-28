#include <cstring>
#include <iostream>

int  check_args(int argc, char** argv){
    if(argc == 1){
        return 0;
    }
    if(argc == 2){
        if(!strcmp(argv[1], "--fromfile")){
            return 1;
        }
        if(!strcmp(argv[1], "--tofile")){
            return 2;
        }
    }
    if(argc == 3){
        if(!strcmp(argv[1], "--tofile") && !strcmp(argv[2], "--fromfile") ||
        !strcmp(argv[2], "--tofile") && !strcmp(argv[1], "--fromfile")){
            return 3;
        }
    }
    return -1;
}

void sort(int** array, int len){
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len - 1; ++j){
            if(array[j][0] > array[j + 1][0]){
                std::swap(array[j], array[j + 1]);
            }
        }
    }

}