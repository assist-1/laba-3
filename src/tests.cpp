#include <iostream>
#include <fstream>
#include "progmake.h"

int main(){

    int flag;
    int i;
    char a;
    
    std::ifstream ifs1("./testfiles/test1_ans.txt");
    std::ifstream ifs2("./testfiles/test2_ans.txt");
    std::ifstream ifs3("./testfiles/test3_ans.txt");
    
    //TEST_1
    flag = 1;
    char name1[] = "./testfiles/test1.txt";

    char *mas1 = prog(name1);
    i=0;
    while(mas1[i]){
        a = ifs1.get();
        if (mas1[i] != a) {
            flag = 0;
            break;
        }
        i++;        
    }
    ifs1.close();
    delete[] mas1;
    if (flag == 1) std::cout<<"TEST_1 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_1 --> failed!"<<std::endl;
    

    //TEST_2
    flag = 1;
    char name2[] = "./testfiles/test2.txt";
    char *mas2 = prog(name2);

    i = 0;
    while(mas2[i]){
        a = ifs2.get();
        if (mas2[i] != a) {
            flag = 0;
            break;
        }
        i++;        
    }
    ifs2.close();
    delete[] mas2;
    if (flag == 1) std::cout<<"TEST_2 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_2 --> failed!"<<std::endl;

    //TEST_3
    flag = 1;
    char name3[] = "./testfiles/test3.txt";
    char *mas3 = prog(name3);

    i = 0;
    while(mas3[i]){
        a = ifs3.get();
        if (mas3[i] != a) {
            flag = 0;
            break;
        }
        i++;        
    }
    ifs3.close();
    delete[] mas3;
    if (flag == 1) std::cout<<"TEST_3 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_3 --> failed!"<<std::endl;


    return 0;
}