#include "func.h"
#include <fstream>
#include <iostream>

void convertToArray(bool fileOrConsole,char convertedText[20][20][40]){ //file=1;console=0
    bool lever = false;
    std::ifstream text;
    if (fileOrConsole) {
        text.open("FileWithText.txt");
        if(text.is_open()){
            lever=true;
        }
    }
    char character;
    int sentenceCount=0,sentenceWordCount=0,wordCharactersCount=0;
    bool lastWasDot = false, dotIsHere = false;
    if(!lever){
        do{
            if(lever) character= text.get();
            character = getchar();
            if(character == ' '){
                if(lastWasDot){
                    lastWasDot=false;dotIsHere=true;continue; //пропускаем пробел после .
                }
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = character;
                wordCharactersCount = 0;
                sentenceWordCount++;
                continue;
            }
            if(character!='.'){
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = character;
                wordCharactersCount++;
            }
            if(character=='.'){
                lastWasDot=true;
                dotIsHere=true;
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = '&';
                // &=end of sentence
                wordCharactersCount=0;
                sentenceWordCount=0;
                sentenceCount++;

            }
            if((dotIsHere)&&(character=='\n')){
                convertedText[sentenceCount][0][0]='&';
            }
            if(!dotIsHere){
                character = '1';
                continue;
            }

        }while(character!='\n');
    }
    if (lever){
        do{
            character= text.get();
            if(character == ' '){
                if(lastWasDot){
                    lastWasDot=false;dotIsHere=true;continue; //пропускаем пробел после .
                }
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = character;
                wordCharactersCount = 0;
                sentenceWordCount++;
                continue;
            }
            if((character!='.')){
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = character;
                wordCharactersCount++;
            }
            if(character=='.'){
                lastWasDot=true;
                dotIsHere=true;
                convertedText[sentenceCount][sentenceWordCount][wordCharactersCount] = '&';
                // &=end of sentence
                wordCharactersCount=0;
                sentenceWordCount=0;
                sentenceCount++;

            }
            if((dotIsHere)&&(character=='\n')){
                convertedText[sentenceCount][0][0]='&';
            }
            if(!dotIsHere){
                character = '1';
                continue;
            }

        }while(!text.eof());
        convertedText[sentenceCount+1][0][0]='&';
    }
}

void strangePrint(char text[20][20][40]){
    bool brake = false;
    for(int k=0;k<20;k++){
        if(text[k][0][0]=='&') {std::cout << "end?";break;}
        for(int j=0;j<20;j++){
            for(int i=0;i<40;i++){
                if(text[k][j][i]=='\0') break;
                if(text[k][j][i]=='&') {brake=true;break;}
                if(text[k][j][i]=='\n'){continue;}
                std::cout<< text[k][j][i];
            }
            if (brake) {brake=false;break;}
        }
        brake = false;
        std::cout << '\n';
        std::cout << "END" << std::endl;
    }
}

void countLength(int Length[20],char text[20][20][40]){
    bool brake = false;
    for(int i=0;i<20;i++){Length[i]=0;}
    for(int k=0;k<20;k++){
        if(text[k][0][0]=='&') {break;}
        for(int j=0;j<20;j++){
            for(int i=0;i<40;i++){
                if(text[k][j][i]=='\0') break;
                if(text[k][j][i]=='&') {brake=true;break;}
                if(text[k][j][i]=='\n'){continue;}
                Length[k]++;
            }
            if (brake) {brake=false;break;}
        }
        brake = false;
    }
}

void printSentence(int SentenceNumber,char text[20][20][40],bool toFile,std::ofstream &answersFile){
    bool brake = false;
    for(int i=0;i<20;i++){
        for(int j=0;j<40;j++){
            if(text[SentenceNumber][i][j]=='\0') break;
            if(text[SentenceNumber][i][j]=='&') {brake=true;break;}
            if(text[SentenceNumber][i][j]=='\n'){continue;}

            if(!toFile){std::cout<<text[SentenceNumber][i][j];}
            if(toFile){answersFile<<text[SentenceNumber][i][j];}
        }
        if (brake) {brake=false;break;}
    }
    if(!toFile){std::cout<<'.'<<std::endl;}
    if(toFile){answersFile<<'.'<<'\n';}
}

void printReverseSentence(int SentenceNumber,char text[20][20][40]){
    std::ofstream file("NINE.txt");
    file.clear();
    bool brake = false;
    int storage = 0;
    for(int i=19;i>=0;i--){
        for(int j=0;j<40;j++){
            if(text[SentenceNumber][i][j]=='&'){
                storage=i;
                brake =  true;
            }
        }
        if (brake) {brake=false;break;}
    }
    
    for(int i=storage;i>=0;i--){
        for(int j=0;j<40;j++){
            if(text[SentenceNumber][i][j]=='\0') break;
            if(text[SentenceNumber][i][j]=='&') {file<<' ';continue;}
            if(text[SentenceNumber][i][j]=='\n'){continue;}
            file<<text[SentenceNumber][i][j];
        }
    }
}

void printAnswer(int Length[20],char text[20][20][40],bool toFile){
    int minStorage = 0;
    int maxStorage = 0;
    int minimum = 100;
    int maximum = 0;
    bool check = false;
    std::ofstream answersFile("Answers.txt");
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(Length[j]==0) continue;
            if(Length[j]>maximum){maximum=Length[j];maxStorage=j;}
            if(Length[j]<= minimum){
                minStorage=j;
                minimum=Length[j];
                check = true;
            }
        }
        if(check){
            minimum=100;
            Length[minStorage]=0;
            //std::cout<<minStorage<<std::endl;
            check = false;
            printSentence(minStorage,text,toFile,answersFile);
        }
    }
    //std::cout <<"MaxStorage:"<<maxStorage<<std::endl;
    printReverseSentence(maxStorage,text);
}
