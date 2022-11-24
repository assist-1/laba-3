#include <iostream>
#include <cstdio>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

void AddToFile(){
char token;
std::ofstream fout;
    fout.open("text.txt");
while (cin >> token ){
    if (token != '.'){
        fout << token;

    }
    if (token == '.'){
    fout << '.';
        fout << '\n';
    }
}
fout.close();
}
int main() {
  AddToFile();
}
