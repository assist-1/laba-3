#include <fstream>
#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    int tmp;

    if(argc == 1){
      cout << "OK\n";
      sol1();
    }else if((argc == 3)||(argc == 2)){
        if(strcmp(argv[1], "--fromfile") == 0){
          cout << "OK3 from\n";
          sol3i(argv);
        }else if(strcmp(argv[1], "--tofile") == 0){
          cout << "OK3 to\n";
          sol3o(argc, argv);
        }else{
          cout << "Incorect flag\n";
          return 0;
        }
    }else if((argc == 5)||(argc == 4)){
      bool flag = true;
        if((strcmp(argv[1], "--fromfile") == 0)||(strcmp(argv[2], "--fromfile") == 0)||(strcmp(argv[3], "--fromfile") == 0)){
          if(strcmp(argv[1], "--fromfile") == 0){
            cout << "OK5 from1\n";
            flag = true;
          }else{
            cout << "OK5 from3\n";
            flag = false;
          }
        }else{
          cout << "Incorrect flag\n";
          return 0;
        }
        if((strcmp(argv[1], "--tofile") == 0)||(strcmp(argv[3], "--tofile") == 0)){
          if(strcmp(argv[1], "--tofile") == 0){
            cout << "OK5 to1\n";
          }else{
            cout << "OK5 to3\n";
          }
        }else{
          cout << "Incorrect flag\n";
          return 0;
        }
        sol5(argc, argv, flag);
    }
    return 0;
}
