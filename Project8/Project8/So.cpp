#include <iostream>
#include <fstream>
#include "So.h"

using namespace std;

struct Str
{
    int iStart;
    int Lenght;

    Str() {}

    Str(int ind, int len) {
        iStart = ind;
        Lenght = len;
    }
};

int TofileFromfile()
{


    cout << "Entered file vvod: ";
    char filename[150];
    cin.getline(filename, 150);

    ifstream fin;
    fin.open(filename);

    if (!fin.is_open())
    {
        cout << "ERROR. File is not oppened." << endl;
    }

    int realTextLenght = 0;
    const int maxTextLenght = 1000;
    char text[maxTextLenght];
    int realStrCount = 0;
    const int maxStrCount = 300;


    Str strs[maxStrCount]; //Str - предложение


    int nowStrLenght = 0;
    int nowStrStart = 0;
    for (char symbol; realTextLenght < 1000 && fin.get(symbol);) {
        if (symbol == ' ' && text[realTextLenght - 1] == '.') {
            strs[realStrCount] = Str(nowStrStart, nowStrLenght);
            nowStrStart = realTextLenght;
            nowStrLenght = 0;
            realStrCount++;
        }
        else {
            text[realTextLenght] = symbol;
            nowStrLenght++;
            realTextLenght++;
        }
    }
    if (nowStrLenght > 0)
        strs[realStrCount++] = Str(nowStrStart, nowStrLenght);

    //сортируем по длиннам(пузырьковая сортировка)
    for (int i = 0; i < realStrCount; i++) {
        for (int j = i + 1; j < realStrCount; j++) {
            if (strs[i].Lenght > strs[j].Lenght) {
                Str buf = strs[i];
                strs[i] = strs[j];
                strs[j] = buf;
            }
        }
    }

    cout << "Entered file vivod: ";
    char filename2[150];
    cin.getline(filename2, 150);

    ofstream OUT;
    OUT.open(filename2);
    if (!OUT.is_open()) {
        cout << "ERROR. File is not opened" << endl;
    }


    else
    {
        for (int i = 0; i < realStrCount; i++, OUT << endl) {
            for (int iText = strs[i].iStart; iText < strs[i].iStart + strs[i].Lenght; iText++) {
                OUT << text[iText];
            }

        }
    }
    OUT.close();
    return 0;
}

int fromfile()
{

    cout << "Entered file vvod: ";
    char filename[150];
    cin.getline(filename, 150);

    ifstream fin;
    fin.open(filename);

    if (!fin.is_open())
    {
        cout << "ERROR. File is not oppened." << endl;
    }

    int realTextLenght = 0;
    const int maxTextLenght = 1000;
    char text[maxTextLenght];
    int realStrCount = 0;
    const int maxStrCount = 300;


    Str strs[maxStrCount]; //Str - предложение


    int nowStrLenght = 0;
    int nowStrStart = 0;
    for (char symbol; realTextLenght < 1000 && fin.get(symbol);) {
        if (symbol == ' ' && text[realTextLenght - 1] == '.') {
            strs[realStrCount] = Str(nowStrStart, nowStrLenght);
            nowStrStart = realTextLenght;
            nowStrLenght = 0;
            realStrCount++;
        }
        else {
            text[realTextLenght] = symbol;
            nowStrLenght++;
            realTextLenght++;
        }
    }
    if (nowStrLenght > 0)
        strs[realStrCount++] = Str(nowStrStart, nowStrLenght);

    //сортируем по длиннам(пузырьковая сортировка)
    for (int i = 0; i < realStrCount; i++) {
        for (int j = i + 1; j < realStrCount; j++) {
            if (strs[i].Lenght > strs[j].Lenght) {
                Str buf = strs[i];
                strs[i] = strs[j];
                strs[j] = buf;
            }
        }
    }





    for (int i = 0; i < realStrCount; i++, cout << endl) {
        for (int iText = strs[i].iStart; iText < strs[i].iStart + strs[i].Lenght; iText++) {
            cout << text[iText];
        }

    }

    return 0;
}

int tofile()
{




    ifstream fin;
    fin.open("f.txt");



    int realTextLenght = 0;
    const int maxTextLenght = 1000;
    char text[maxTextLenght];
    int realStrCount = 0;
    const int maxStrCount = 300;


    Str strs[maxStrCount]; //Str - предложение


    int nowStrLenght = 0;
    int nowStrStart = 0;
    for (char symbol; realTextLenght < 1000 && fin.get(symbol);) {
        if (symbol == ' ' && text[realTextLenght - 1] == '.') {
            strs[realStrCount] = Str(nowStrStart, nowStrLenght);
            nowStrStart = realTextLenght;
            nowStrLenght = 0;
            realStrCount++;
        }
        else {
            text[realTextLenght] = symbol;
            nowStrLenght++;
            realTextLenght++;
        }
    }
    if (nowStrLenght > 0)
        strs[realStrCount++] = Str(nowStrStart, nowStrLenght);

    //сортируем по длиннам(пузырьковая сортировка)
    for (int i = 0; i < realStrCount; i++) {
        for (int j = i + 1; j < realStrCount; j++) {
            if (strs[i].Lenght > strs[j].Lenght) {
                Str buf = strs[i];
                strs[i] = strs[j];
                strs[j] = buf;
            }
        }
    }

    cout << "Entered file vivod: ";
    char filename2[150];
    cin.getline(filename2, 150);

    ofstream OUT;
    OUT.open(filename2);
    if (!OUT.is_open()) {
        cout << "ERROR. File is not opened" << endl;
    }


    else
    {
        for (int i = 0; i < realStrCount; i++, OUT << endl) {
            for (int iText = strs[i].iStart; iText < strs[i].iStart + strs[i].Lenght; iText++) {
                OUT << text[iText];
            }

        }
    }
    OUT.close();
    return 0;
}