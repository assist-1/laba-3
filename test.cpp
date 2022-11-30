#include "pch.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <cmath> 
#include <sstream>
using std::stringstream;

int lenght(char* filename) {
    int i = 0;
    std::ifstream f(filename);
    while (!f.eof())
    {
        char ch;
        f >> ch;
        i++;
    }
    return i;
}

void Write(char* filename) {
    std::ofstream out;          // ïîòîê äëÿ çàïèñè
    out.open(filename); // îêðûâàåì ôàéë äëÿ çàïèñè
    if (out.is_open())
    {
        int count;
        char str[256] = "";
        std::cin >> count;
        out << count << std::endl;
        for (int i = 0; i < count * 2; i++) {
            std::cin >> str;
            out << str;
            if (i % 2 == 0)
                out << ' ';
            else {
                out << '\n';
            }
        }
    }
    out.close();
}

char* convert(double a) {
    int b = a * 100;
    int c = b;
    int i = 0;
    while (c != 0) {
        c = c / 10;
        i++;
    }
    int firstSymble = 0;

    //Ó÷ò¸ì çíàê
    if (a < 0) {
        firstSymble = 1;
        b = b * (-1);
    }
    char* str = new char[i + 2 + firstSymble];
    str[i + 2 + firstSymble] = '\0';
    if (firstSymble == 1)
        str[0] = '-';

    for (int j = i + firstSymble; j >= firstSymble; j--)
    {
        if ((i - j) == 1) //Ìåñòî äëÿ çàïÿòîé
        {
            str[j] = '.';
        }
        else {
            char ch = (char)(b % 10 + 48);
            str[j] = ch;
            b = b / 10;

        }
    }

    return str;
}

char* Function(char* filename) {
    int lenght2 = lenght(filename);
    char* str = new char[lenght2 + 1];
    char ch;
    int i = 0; //Äëèíà âñåãî
    float min1 = 0;
    float min2 = 0;
    float max1 = 0;
    float max2 = 0;
    std::fstream fin(filename, std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        str[i] = ch;
        i++;
    }
    int count = 0;
    int j = 0;
    //Ñ÷èòàåì êîëè÷åñòâî ñòðîê
    while (str[j] != '\n') {
        count = count * 10 + (str[j] - '0');
        j++;
    }

    j=j+1;

    //Ñ÷èòàåì ïåðâîå ÷èñëî ÷èñëî
    bool flag1 = false;
    int znak1 = 1;
    //Ñ÷èòàåì çíàê
    if (str[j] == '-') {
        znak1 = -1;
        j++;
    }
    int stepen = 1;

    while (str[j] != ' ')
    {
        if ((str[j] == '.') || (str[j] == ',')) {
            flag1 = true;
        }
        else {
            //Öåëàÿ ÷àñòü
            if (!flag1) {
                min1 = min1 * 10 + (str[j] - '0');
            }
            else {
                min1 = min1 + (str[j] - '0') / pow(10, stepen);
                ++stepen;
            }
        }
        j++;
    }
    min1 = min1 * znak1;
    max1 = min1;
    j++;

    //Ñ÷èòàåì âòîðå ÷èñëî
    //Ñ÷èòàåì çíàê
    flag1 = false;
    znak1 = 1;
    //Ñ÷èòàåì çíàê
    if (str[j] == '-') {
        znak1 = -1;
        j++;
    }

    stepen = 1;
    //Ñ÷èòàåì âòîðîå ÷èñëî ÷èñëî ÷èñëî
    while ((str[j] != '\n'))
    {
        if ((str[j] == '.') || (str[j] == ',')) {
            flag1 = true;
        }
        else {
            //Öåëàÿ ÷àñòü
            if (!flag1) {
                min2 = min2 * 10 + (str[j] - '0');
            }
            else {
                min2 = min2 + (str[j] - '0') / pow(10, stepen);
                ++stepen;
            }
        }
        j++;
    }
    min2 = min2 * znak1;
    max2 = min2;
    j++;



    //Ñ÷èòàåì âñå îñòàâøèåñÿ
    while (j <= i - 1) {
        float Local1 = 0;
        float Local2 = 0;
        //Ñ÷èòàåì ïåðâîå ÷èñëî ÷èñëî
        bool flag1 = false;
        int znak1 = 1;
        //Ñ÷èòàåì çíàê
        if (str[j] == '-') {
            znak1 = -1;
            j++;
        }
        int stepen = 1;

        while (str[j] != ' ')
        {
            if ((str[j] == '.') || (str[j] == ',')) {
                flag1 = true;
            }
            else {
                //Öåëàÿ ÷àñòü
                if (!flag1) {
                    Local1 = Local1 * 10 + (str[j] - '0');
                }
                else {
                    Local1 = Local1 + (str[j] - '0') / pow(10, stepen);
                    ++stepen;
                }
            }
            j++;
        }
        Local1 = Local1 * znak1;
        j++;

        //Ñ÷èòàåì âòîðå ÷èñëî
        //Ñ÷èòàåì çíàê
        flag1 = false;
        znak1 = 1;
        //Ñ÷èòàåì çíàê
        if (str[j] == '-') {
            znak1 = -1;
            j++;
        }

        stepen = 1;
        //Ñ÷èòàåì âòîðîå ÷èñëî ÷èñëî ÷èñëî
        while ((str[j] != '\n'))
        {
            if ((str[j] == '.') || (str[j] == ',')) {
                flag1 = true;
            }
            else {
                //Öåëàÿ ÷àñòü
                if (!flag1) {
                    Local2 = Local2 * 10 + (str[j] - '0');
                }
                else {
                    Local2 = Local2 + (str[j] - '0') / pow(10, stepen);
                    ++stepen;
                }
            }
            j++;
        }
        Local2 = Local2 * znak1;
        j++;

        //Íàéä¸ì ìèíèìàëüíîå è ìàêñèìàëüíûå çíà÷åíèÿ ëåâûõ è ïðàâûõ òî÷åê
        if (abs(Local1) < abs(min1))
            min1 = Local1;
        else if (Local1 > max1)
            max1 = Local1;

        if (Local2 < min2)
            min2 = Local2;
        else if (Local2 > max2)
            max2 = Local2;
    }

    //×òîáû áûëî ïåðåñå÷åíèå, íè îäíà ïðàâàÿ òî÷êà ïåðåñå÷åíèÿ íå äîëæíà ëåæàòü ëåâåå ëþáîé ëåâîé
    //×òîáû áûëî ïåðåñå÷åíèå, íè îäíà ëåâàÿ òî÷êà ïåðåñå÷åíèÿ íå äîëæíà ëåæàòü ïðàâåå ëþáîé ïðàâîé
    //Ýòî âûâîäèòñÿ èç òîãî, ÷òî ìîæåì áðàòü ïî äâà îòðåçî÷êà, áðàòü èõ ïåðåñå÷åíèå1 (îíî áóäåò íàõîäèòñÿ ïî äàííîé ôîðìóëå) 
    // à âîçüì¸ì ïåðåå÷åíèå ïåðåñå÷åíèå1 è îòðåçêà 3, ïîëó÷èì (îíî áóäåò íàõîäèòñÿ ïî äàííîé ôîðìóëå) ïåðåñå÷åíèå2
    // è òä



    if (max1 >= min2) {
        return "NO INTERSECTIONS";
    }
    
  //Êîíâåðòèðóåì ïåðâîå ÷èñëî â ñòðîêó

    //Îïðåäåëèì äëèííó ïåðâîé ñòðîêè
    double a = max1;
    int b = a * 100;
    int c = b;
    i = 0;
    while (c != 0) {
        c = c / 10;
        i++;
    }
    int firstSymble = 0;

    //Ó÷ò¸ì çíàê
    if (a < 0) {
        firstSymble = 1;
        b = b * (-1);
    }
    int lenght1 = i + 1 + firstSymble;


    //Îïðåäåëèì äëèííó âòîðîé ñòðîêè
    
    double a1 = min2;
    int b1 = a1*100;

    int c1 = b1;
    int i1 = 0;
    while (c1 != 0) {
        c1 = c1 / 10;
        i1++;
    }
    int firstSymble1 = 0;

    //Ó÷ò¸ì çíàê
    if (a1 < 0) {
        firstSymble1 = 1;
        b1 = -b1;
    }
    int lenghtTwo = i1 + 1 + firstSymble1;
    //Ñôîðìèðóåì ñòðîêó
    char* string1 = new char[lenght1 + lenghtTwo + 2];
    string1[lenght1 + lenghtTwo + 1] = '\0';
    if (firstSymble == 1)
        string1[0] = '-';

    for (int j = lenght1 - 1; j >= firstSymble; j--)
    {
        if ((lenght1 - j) == 3) //Ìåñòî äëÿ çàïÿòîé
        {
            string1[j] = '.';
        }
        else {
            char ch = (char)(b % 10 + 48);
            string1[j] = ch;
            b = b / 10;
        }
    }
    string1[lenght1] = ' ';

    //Äîáàâèì âòîðîå ÷èñëî
    if (firstSymble1 == 1)
        string1[lenght1 + 1] = '-';



    // for (int j = lenght1 - 1; j >= firstSymble; j--)
    for (int j = lenght1 + lenghtTwo; j >= lenght1 + 1 + firstSymble1; j--)
    {
        if ((lenght1 + lenghtTwo - j) == 2) //Ìåñòî äëÿ çàïÿòîé
        {
            string1[j] = '.';
        }
        else {
            char ch = (char)(b1 % 10 + 48);
            string1[j] = ch;
            b1 = b1 / 10;

        }
    }

   return string1;
}



char* Function2(char* filename) {
    Write(filename);
    return Function(filename);
}

TEST(TestFrom, NegativeDouble) {
    char* answer = "-7.13 -6.35";
    char* result = Function("fileNegative.txt");
    for (int i = 0; i <11; i++) {
        EXPECT_EQ(result[i], answer[i]);
    }
}
TEST(TestFrom, PositiveDouble) {
    char* answer = "6.25 7.13";
    char* result = Function("file.txt");
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(result[i], answer[i]);
    }
}

TEST(TestFrom, PositiveInt) {
    char* answer = "6.00 7.00";
    char* result = Function("fileint.txt");
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(result[i], answer[i]);
    }
}

TEST(TestTo, PositiveDouble) {
    //Ââîäè òîæå ñàìîå ÷òî è èç file.txt
    char* answer = "6.25 7.13";
    char* result = Function2("file2.txt");
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(result[i], answer[i]);
    }
}
