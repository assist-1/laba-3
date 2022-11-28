#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;

#define flag1 "--tofile"
#define flag2 "--fromfile"
#define length 2048

void tofile();
void to_console(char* file_name);
void from_f_to_f(char* filename);
void sort(int len[], int nomer[], int temp2);
int read(char data[100][1024], int* len, int* nomer, int temp2);
int read_file(char* filename, char data0[100][1024], int* len, int* nomer, int temp2);
void reverse(int len, char* str);


int main(int argc, char* argv[]) {
    if (strcmp(flag2, argv[1]) == 0 && argc == 3){
        cout << ">>> Reading data form " << argv[2] << endl;
        cout << ">>> Result: " << endl;
        to_console(argv[2]);
    }
    else if (strcmp(flag1, argv[1]) == 0 && argc == 2) {
        cout << ">>> Press ESC + ENTER when finish" << endl;
        tofile();
        cout << ">>> Results saved to result.txt and NINE.txt" << endl;
    }
    else if(strcmp(flag2, argv[1]) == 0 && strcmp(flag1, argv[2]) == 0 && argc == 4){
        cout << ">>> Reading data form " << argv[3] << endl;
        from_f_to_f(argv[3]);
        cout << ">>> Results saved to result.txt and NINE.txt" << endl;
    }
    else{
        cout << ">>> Wrong input!" << endl;
    }
    return 0;
}

int read(char data[100][1024], int* len, int* nomer, int temp2){
    char Ch;
    int temp3 = 0;
    temp2 = 0;
    int temp1 = 1;
    while(Ch != 27){
        Ch = cin.peek();
        if(Ch == '\n'){
            Ch = ' ';
        }
        else if(Ch == 27){
            break;
        }
        if(Ch == '.'){
            cin.ignore();
            char Ch2 = cin.peek();
            Ch = Ch2;
            len[temp2] = temp1;
            nomer[temp2] = temp2;
            temp2++;
            temp3 = temp1;
            temp1 = 0;
        }
        data[temp2][temp1-1] = Ch;
        temp1++;
        cin.ignore();
    }
    reverse(temp3, data[temp2-1]);
    return temp2;
}

void tofile(){
    char data[100][1024];
    int len[1024];
    int nomer[1024];
    int temp2 = read(data, len, nomer, temp2);
    sort(len, nomer, temp2);
    char temp3[100][1024];
    ofstream fout("result.txt");
    for (int i = 0; i < temp2; i++) {
        fout << data[nomer[i]] << '.' << endl;
    }
    fout.close();
    reverse(strlen(data[nomer[temp2-1]]), data[nomer[temp2-1]]);
}


void sort(int len[], int nomer[], int temp2) {
    int var;
    int var1;
    for (int i = 0; i < temp2-1; i++) {
        for (int j = 0; j < temp2 - i-1; j++) {
            if (len[j] > len[j + 1]) {
                var = nomer[j + 1];
                nomer[j + 1] = nomer[j];
                nomer[j] = var;
                var1 = len[j + 1];
                len[j + 1] = len[j];
                len[j] = var1;
            }
        }
    }
}

void to_console(char* file_name){
    char data[100][1024];
    int len[1024];
    int nomer[1024];
    int temp2 = read_file(file_name, data, len, nomer, temp2);
    sort(len, nomer, temp2);
    for (int i = 0; i < temp2; i++) {
        cout << data[nomer[i]] << '.' << endl;
    }
    reverse(strlen(data[nomer[temp2-1]]), data[nomer[temp2-1]]);
}

int read_file(char* filename, char data0[100][1024], int* len, int* nomer, int temp2){
    ifstream in(filename,ios::binary);
    int size_of_file = in.seekg(0,ios::end).tellg();
    in.seekg(0);
    char * data = new char[size_of_file+1];
    in.read(data,size_of_file);
    data[size_of_file] = 0;
    temp2 = 0;
    int temp1 = 1;
    for (int i = 0; i < size_of_file; i++){
        char Ch = data[i];
        if(Ch == '\n'){
            Ch = ' ';
        }
        if(Ch == '.'){
            len[temp2] = temp1;
            nomer[temp2] = temp2;
            temp2++;
            temp1 = 0;
            continue;
        }
        data0[temp2][temp1-1] = Ch;
        temp1++;
    }
    return temp2;
}

void from_f_to_f(char* filename){
    char data[100][1024];
    int len[1024];
    int nomer[1024];
    int temp2 = read_file(filename, data, len, nomer, temp2);
    sort(len, nomer, temp2);
    ofstream fout("result.txt");
    for (int i = 0; i < temp2; i++) {
        fout << data[nomer[i]] << '.' << endl;
    }
    fout.close();
    reverse(strlen(data[nomer[temp2-1]]), data[nomer[temp2-1]]);
}

void reverse(int len, char* str){
    int temp = len;
    ofstream nine("NINE.txt");
    nine << ">>> Original sentence: " << str << endl;
    nine << ">>> Reversed sentence:";
    for (int i = len-1; i > -1; i--){
        if(str[i] == ' ' || i == 0){
            int j = i;
            while(j <= temp){
                nine << str[j];
                j++;
            }
            nine << ' ';
            temp = i;
        }
    }
    nine << endl;
    nine.close();
}
