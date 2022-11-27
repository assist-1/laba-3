#include <iostream>
#include <math.h>
#include <cstring>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
void FromUsage(){
    cout << "For reading from file enter: [./nameprog --fromfile <namefile.txt>]" << endl;
}
void ToUsage(){
    cout << "For out to file enter: [./<nameprog> --tofile <namefile.txt>]" << endl;
}
void FromToUsage(){
    cout << "For reading from one file and out to another file enter: [./<nameprog> --fromfile --tofile <file1> <file2>]" << endl;
}
void CommonUsage(){
    cout << "Write options in correct form:" << endl;
    FromUsage();
    ToUsage();
    FromToUsage();
}
void ToFile(char *namefile){
    std::ofstream out_temp_file ("temp_file.txt"); // Создаем промежуточный файл
    std::ofstream result_file(namefile); // Создаем файл для записи результата
    std::ofstream maxSent ("maxSent.txt");
    char cur_char = '0';
    char prev_char = 'a';
    int curLen = 0;
    int maxLen = 0;
    int numSentences = 0;
    while (std::cin.get(cur_char) && cur_char != '\n') { //Пока с потока cin мы считываем символ, и он не переход
        if (cur_char == '.') {    //Если предложение закончилось, то увеличиваем кол-во, обновляем макс.длину при необх
            numSentences += 1;
            maxLen = std::max(++curLen, maxLen);
            curLen = 0;
            prev_char = '.';
            out_temp_file << ".\n";
        }
        else if (cur_char == ' ' && prev_char == '.')
            continue;

        else {                 //Иначе просто считываем символ из файла, увеличивая длину
            out_temp_file << cur_char;
            prev_char = cur_char;
            curLen++;
        }
    }
    out_temp_file.close();
    maxLen++;
    char sentences[numSentences][maxLen];  //Объявляем два массива, в одном будут хранится предложения и их длины
    int lengths[numSentences]; //Во втором длины, но с связью с первым массивом
    std::ifstream in_temp_file ("temp_file.txt"); //Из файла посимвольно записываем предложения в массив, а также их длины
    for (int i = 0; i < numSentences; ++i) { //Проходимся двойным циклом, если предложение закончилось, то мы
        for (int k = 0; k < maxLen; ++k) { // В массив длин записываем длину предл.
            in_temp_file.get(cur_char);
            if (cur_char == '\n') {
                sentences[i][k] = '\0';
                lengths[i] = k;
                break;
            }
            sentences[i][k] = cur_char;   // Продолжаем считывать в массив символы с файла
        }
    }
    in_temp_file.close();
    int temp = 0;
    char temps[maxLen];
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j]> lengths[j+1]){
                    temp = lengths[j];
                    lengths[j] = lengths[j+1];
                    lengths[j+1] = temp;
                    strcpy(temps,sentences[j]);
                    strcpy(sentences[j],sentences[j+1]);
                    strcpy(sentences[j+1],temps);
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;
    maxSent << sentences[numSentences-1] << endl;
    result_file.close();
}
void FromFile(char *namefile) { //Фром файл c задаванием пользователем файла
    std::ofstream out_temp_file ("temp_file.txt");
    std::ifstream input_file (namefile);
    std::ofstream maxSent ("maxSent.txt");
    char cur_char = '0';
    char prev_char = 'a';
    int curLen = 0;
    int maxLen = 0;
    int numSentences = 0;
    while (input_file.get(cur_char) && cur_char != '\n') {
        if (cur_char == '.') {
            numSentences += 1;
            maxLen = std::max(++curLen, maxLen);
            curLen = 0;
            prev_char = '.';
            out_temp_file << ".\n";
        }
        else if (cur_char == ' ' && prev_char == '.')
            continue;
        else {
            out_temp_file << cur_char;
            prev_char = cur_char;
            curLen++;
        }
    }
    out_temp_file.close();
    input_file.close();
    maxLen++;
    char sentences[numSentences][maxLen];
    int lengths[numSentences];
    std::ifstream in_temp_file ("temp_file.txt");
    for (int i = 0; i < numSentences; ++i) {
        for (int k = 0; k < maxLen; ++k) {
            in_temp_file.get(cur_char);
            if (cur_char == '\n') {
                sentences[i][k] = '\0';
                lengths[i] = k;
                break;
            }
            sentences[i][k] = cur_char;
        }
    }
    in_temp_file.close();
    int temp = 0;
    char temps[maxLen];
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j]> lengths[j+1]){
                    temp = lengths[j];
                    lengths[j] = lengths[j+1];
                    lengths[j+1] = temp;
                    strcpy(temps,sentences[j]);
                    strcpy(sentences[j],sentences[j+1]);
                    strcpy(sentences[j+1],temps);
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        cout << sentences[i] << "   " << lengths[i] << endl;
    maxSent << sentences[numSentences-1] <<  endl;
}
void FromAndToFile(char *in_file, char *to_file){
    std::ofstream out_temp_file ("temp_file.txt");
    std::ifstream input_file (in_file);
    std::ofstream result_file(to_file);
    std::ofstream maxSent ("maxSent.txt");
    char cur_char = '0';
    char prev_char = 'a';
    int curLen = 0;
    int maxLen = 0;
    int numSentences = 0;
    while (input_file.get(cur_char) && cur_char != '\n') {
        if (cur_char == '.') {
            numSentences += 1;
            maxLen = std::max(++curLen, maxLen);
            curLen = 0;
            prev_char = '.';
            out_temp_file << ".\n";
        }
        else if (cur_char == ' ' && prev_char == '.')
            continue;
        else {
            out_temp_file << cur_char;
            prev_char = cur_char;
            curLen++;
        }
    }
    out_temp_file.close();
    input_file.close();
    maxLen++;
    char sentences[numSentences][maxLen];
    int lengths[numSentences];
    std::ifstream in_temp_file ("temp_file.txt");
    for (int i = 0; i < numSentences; ++i) {
        for (int k = 0; k < maxLen; ++k) {
            in_temp_file.get(cur_char);
            if (cur_char == '\n') {
                sentences[i][k] = '\0';
                lengths[i] = k;
                break;
            }
            sentences[i][k] = cur_char;
        }
    }
    in_temp_file.close();
    int temp = 0;
    char temps[maxLen];
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j]> lengths[j+1]){
                    temp = lengths[j];
                    lengths[j] = lengths[j+1];
                    lengths[j+1] = temp;
                    strcpy(temps,sentences[j]);
                    strcpy(sentences[j],sentences[j+1]);
                    strcpy(sentences[j+1],temps);
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;
    maxSent << sentences[numSentences-1]  << endl;
}
void Nine(){
    std::ifstream input_file("maxSent.txt");
    std::ofstream temp("tempfile.txt");
    char cur_char = '0';
    char prev_char = 'a';
    int curLen = 0;
    int maxLen = 0;
    int numWords = 1;
    while (input_file.get(cur_char)){
        if (cur_char == ' '){
            numWords+=1;
            maxLen = std::max(++curLen, maxLen);
            curLen = 0;
            temp << "\n";
        }
        else {
            temp << cur_char;
            curLen++;
    }
    }
    input_file.close();
    temp.close();
    maxLen++;
    char words[numWords][maxLen];
    std::ifstream tempor ("tempfile.txt");
    std::ofstream res_file("nine.txt");
    for (int i = 0; i< numWords;i++){
        for (int j = 0; j< maxLen;j++){
            tempor.get(cur_char);
            if (cur_char == '\n') {
                    words[i][j] = '\0';
                    break;
                }
            if (cur_char!='.'){

                words[i][j] = cur_char;
                }
    }
    }
    char token;
    for (int i = numWords-1;i>=0;i--){
        int j = 0;
        while (token = words[i][j++]){
            res_file << token;
        }
        res_file << " ";
    }
    tempor.close();
}
