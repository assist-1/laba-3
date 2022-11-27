#include "func.h"
#include <iostream>
#include <cstring>

int main(int argc,char** argv){
    bool toFile = false;
    bool fromFile = false;
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"--toFile")==0) toFile=true;
        if(strcmp(argv[i],"--fromFile")==0) fromFile=true;
    }
    char convertedText[20][20][40];
    int length[20];
    convertToArray(fromFile,convertedText);
    //strangePrint(convertedText);
    countLength(length,convertedText);
    /*for(int i=0;i<20;i++){
        std::cout<<length[i]<<' ';
    }*/
    //std::cout << std::endl;
    //printSentence(2,convertedText);
    printAnswer(length,convertedText,toFile);
    //printReverseSentence(2,convertedText);
    //printSentence(2,convertedText);
    return 0;
}