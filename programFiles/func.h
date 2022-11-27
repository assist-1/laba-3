#include <fstream>
void convertToArray(bool fileOrConsole,char convertedText[20][20][40]);
void strangePrint(char text[][20][40]);
void countLength(int Length[20],char text[20][20][40]);
void printSentence(int SentenceNumber,char text[20][20][40],bool toFile,std::ofstream &answersFile);
void printReverseSentence(int SentenceNumber,char text[20][20][40]);
void printAnswer(int Length[20],char text[20][20][40],bool toFile);