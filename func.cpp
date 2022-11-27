#include <iostream>
#include <math.h>
#include <cstring>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;

void ToFile(){
    std::ofstream out_temp_file ("temp_file.txt"); // Создаем промежуточный файл
    std::ofstream result_file("result.txt"); // Создаем файл для записи результата
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
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;

    int temp = 0;
    char temps[numSentences];
    char stream[500];
    char token;
    int ind = 0;
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j] > lengths[j+1]){
                temp = lengths[j];
                lengths[j] = lengths[j+1];
                lengths[j+1] = temp;
                while (token = sentences[j][ind++])
                    stream[ind - 1] = token;
                ind = 0;
                while(token = sentences[j + 1][ind++])
                    sentences[j][ind - 1] = token;
                ind = 0;
                while(token = stream[ind++])
                    sentences[j + 1][ind - 1] = token;
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;
    result_file.close();
}
void ToFile(char *namefile){
    std::ofstream out_temp_file ("temp_file.txt"); // Создаем промежуточный файл
    std::ofstream result_file(namefile); // Создаем файл для записи результата
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
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;

    int temp = 0;
    char temps[numSentences];
    char stream[500];
    char token;
    int ind = 0;
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j] > lengths[j+1]){
                temp = lengths[j];
                lengths[j] = lengths[j+1];
                lengths[j+1] = temp;
                while (token = sentences[j][ind++])
                    stream[ind - 1] = token;
                ind = 0;
                while(token = sentences[j + 1][ind++])
                    sentences[j][ind - 1] = token;
                ind = 0;
                while(token = stream[ind++])
                    sentences[j + 1][ind - 1] = token;
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        result_file << sentences[i] << "   " << lengths[i] << endl;
    result_file.close();
}
void FromFile() {

    std::ofstream out_temp_file ("temp_file.txt");
    std::ifstream input_file ("input_file.txt");
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
    char temps[numSentences];
    char stream[500];
    char token;
    int ind = 0;
    for (int i = 0; i < numSentences;i++){
        for (int j = 0; j < numSentences - i - 1;j++){
            if (lengths[j] > lengths[j+1]){
                temp = lengths[j];
                lengths[j] = lengths[j+1];
                lengths[j+1] = temp;
                while (token = sentences[j][ind++])
                    stream[ind - 1] = token;
                ind = 0;
                while(token = sentences[j + 1][ind++])
                    sentences[j][ind - 1] = token;
                ind = 0;
                while(token = stream[ind++])
                    sentences[j + 1][ind - 1] = token;
            }
        }
    }
    for (int i = 0; i < numSentences; ++i)
        cout << sentences[i] << "   " << lengths[i] << endl;
}
