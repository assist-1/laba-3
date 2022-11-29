#include <iostream>
#include "progmake.h"
#include <fstream>

char* prog(char* file_to_read){

    char sentences[1000][1000];
    int kolvo=0;
    int len=0;
    int maxlen = 0;
    int all_len = 0;
    char symbol, presymbol;
    

    if(file_to_read[0]){

        std::ifstream in(file_to_read);
        if (in.is_open()){
            while( !in.eof() ){
                symbol = in.get();
                if (symbol == ' ' && presymbol == '.') continue;

                sentences[kolvo][len] = symbol;
                len++;
                if (symbol == '.') {
                    kolvo++;
                    if (len>maxlen) maxlen = len;
                    len=0;
                }
                presymbol = symbol;
                all_len++;
            }
        }
        else std::cout << "The file does not exist" << std::endl;
        in.close();
    }
    else{
        std::cout << "Enter the text for the main task" << std::endl;
        while (std::cin.get(symbol)) {
            if (symbol == '\n') {
                break;
            }
            
            if (symbol == ' ' && presymbol == '.') continue;

            sentences[kolvo][len] = symbol;
            len++;
            if (symbol == '.') {
                kolvo++;
                if (len>maxlen) maxlen = len;
                len=0;
            }
            presymbol = symbol;
            all_len++;
        }
    }

    if(kolvo==0){
        std::cout<<"Nothing was read\n";
        exit(0);
    }

    all_len=all_len+kolvo;

    int dlin[kolvo];
    for (int i = 0; i<kolvo; i++){
        int sum=0;
        for(int j =0; j<maxlen; j++){
            if (sentences[i][j]) sum++;
            else break;
        }
        dlin[i]=sum;
    }

    for (int i = 0; i < kolvo; i++) {
        for (int j = 0; j < kolvo-1; j++) {
            if (dlin[j] > dlin[j + 1]) {
                int b = dlin[j];
                dlin[j] = dlin[j + 1];
                dlin[j + 1] = b; 

                std::swap(sentences[j], sentences[j+1]);
            }
        }
    }

    char *ans = new char[all_len];
    int k =0;    
    k=0;

    for (int i = 0; i<kolvo; i++){
        for(int j = 0; j<dlin[i]; j++){
            ans[k] = sentences[i][j];
            k++;
        }
        ans[k] = '\n';
        k++;
    }

    return  ans;
}


void clear(char* file_to_clear) {
    std::ofstream file(file_to_clear);
    file<<"";
}

int reversemax(){

    std::cout << "Enter the text for the additional task" << std::endl;

    char sentences[100][100];
    
    int kolvo=0;
    int len=0;
    int maxlen = 0;
    char symbol, presymbol;

    int flag;


    while (std::cin.get(symbol)) {
        if (symbol == '\n') {
            break;
        }
        
        if (symbol == ' ' && presymbol == '.') continue;

        sentences[kolvo][len] = symbol;
        len++;
        if (symbol == '.') {
            if (len>maxlen){
                maxlen = len;
                flag = kolvo;
            }
            kolvo++;
            len=0;
        }
        presymbol = symbol;
    }
    if(kolvo==0){
        std::cout<<"Nothing was read\n";
        exit(0);
    }
    char file_to_clear[8]={'N','I','N','E','.','t','x','t'};
    clear(file_to_clear);
    std::ofstream ofs;
    ofs.open("NINE.txt", std::ios::app); 
    int k, i;
    if (ofs.is_open()){
        for(i = maxlen-1; i>=0; i--){
            if (i==0 || sentences[flag][i-1] == ' '){
                k=i;
                while (sentences[flag][k] != ' ' && sentences[flag][k] != '.'){
                    ofs << sentences[flag][k];
                    k++;
                }
                if (i != 0) ofs << ' ';
                else ofs << '.';
            }
            
        }
    }

    ofs.close();
    return 0;
}
