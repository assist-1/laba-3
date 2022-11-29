#include <iostream>
#include "progmake.h"
#include <fstream>

int main(int argc, char* argv[]){

    char file_to_read[100];
    char file_to_write[100];
    int flag_dop = 0;

    for(int i = 1; i<argc; i++){
        if (argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='f' && argv[i][3]=='r' && argv[i][4]=='o' &&
        argv[i][5]=='m' && argv[i][6]=='f' && argv[i][7]=='i' && argv[i][8]=='l' && argv[i][9]=='e') {
            std::cout << "Eter the file to read name" << std::endl;
            int name_len=0;
            char bukv;
            while (std::cin.get(bukv)) {
                if (bukv == '\n') {
                    break;
                }
                file_to_read[name_len] = bukv;
                name_len++;
            }
        }

        if (argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='t' && argv[i][3]=='o' && argv[i][4]=='f' &&
        argv[i][5]=='i' && argv[i][6]=='l' && argv[i][7]=='e') {
            std::cout << "Eter the file to write name" << std::endl;
            int name_len=0;
            char bukv;
            while (std::cin.get(bukv)) {
                if (bukv == '\n') {
                    break;
                }
                file_to_write[name_len] = bukv;
                name_len++;
            }
        }

        if (argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='d' && argv[i][3]=='o' && argv[i][4]=='p') {
            flag_dop=1;
        }

    }
    
    char *mas = prog(file_to_read);
    if(file_to_write[0]) clear(file_to_write);
    else std::cout<<"Answer: "<<std::endl;
    int i = 0;
    while(mas[i]){
        if(file_to_write[0]){
            std::ofstream wrfile(file_to_write, std::ios::app);
            wrfile << mas[i];
            wrfile.close();
        }
        else std::cout<<mas[i];
        i++;        
    }

    delete[] mas;
    
    if (flag_dop==1) {
        std::cout<<std::endl;
        reversemax();
    }

    return 0;
}