#include <iostream>
#include <fstream>
#include "progmake.h"

int main(){

    int flag;
    int i;
    char a;
    char *mas;
    std::ifstream ifs1("./testfiles/test1_ans.txt");
    std::ifstream ifs2("./testfiles/test2_ans.txt");
    
    //TEST_1
    flag = 1;
    char name1[] = "./testfiles/test1.txt";
    mas = prog(name1);

    i = 0;
    while(mas[i]){
        a = ifs1.get();
        if (mas[i] != a) {
            flag = 0;
            break;
        }
        i++;        
    }
    delete[] mas;
    ifs1.close();

    if (flag == 1) std::cout<<"TEST_1 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_1 --> failed!"<<std::endl;
    
    //TEST_2
    flag = 1;
    char name2[] = "./testfiles/test2.txt";

    mas = prog(name2);
    i=0;
    while(mas[i]){
        a = ifs2.get();
        if (mas[i] != a) {
            flag = 0;
            break;
        }
        i++;        
    }
    delete[] mas;
    ifs2.close();
    if (flag == 1) std::cout<<"TEST_2 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_2 --> failed!"<<std::endl;
    return 0;
}