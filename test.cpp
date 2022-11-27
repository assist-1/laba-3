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
    std::ofstream out;          // ����� ��� ������
    out.open(filename); // �������� ���� ��� ������
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

    //���� ����
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
        if ((i - j) == 1) //����� ��� �������
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
    int i = 0; //����� �����
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
    //������� ���������� �����
    while (str[j] != '\n') {
        count = count * 10 + (str[j] - '0');
        j++;
    }

    j=j+1;

    //������� ������ ����� �����
    bool flag1 = false;
    int znak1 = 1;
    //������� ����
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
            //����� �����
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

    //������� ����� �����
    //������� ����
    flag1 = false;
    znak1 = 1;
    //������� ����
    if (str[j] == '-') {
        znak1 = -1;
        j++;
    }

    stepen = 1;
    //������� ������ ����� ����� �����
    while ((str[j] != '\n'))
    {
        if ((str[j] == '.') || (str[j] == ',')) {
            flag1 = true;
        }
        else {
            //����� �����
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



    //������� ��� ����������
    while (j <= i - 1) {
        float Local1 = 0;
        float Local2 = 0;
        //������� ������ ����� �����
        bool flag1 = false;
        int znak1 = 1;
        //������� ����
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
                //����� �����
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

        //������� ����� �����
        //������� ����
        flag1 = false;
        znak1 = 1;
        //������� ����
        if (str[j] == '-') {
            znak1 = -1;
            j++;
        }

        stepen = 1;
        //������� ������ ����� ����� �����
        while ((str[j] != '\n'))
        {
            if ((str[j] == '.') || (str[j] == ',')) {
                flag1 = true;
            }
            else {
                //����� �����
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

        //����� ����������� � ������������ �������� ����� � ������ �����
        if (abs(Local1) < abs(min1))
            min1 = Local1;
        else if (Local1 > max1)
            max1 = Local1;

        if (Local2 < min2)
            min2 = Local2;
        else if (Local2 > max2)
            max2 = Local2;
    }

    //����� ���� �����������, �� ���� ������ ����� ����������� �� ������ ������ ����� ����� �����
    //����� ���� �����������, �� ���� ����� ����� ����������� �� ������ ������ ������ ����� ������
    //��� ��������� �� ����, ��� ����� ����� �� ��� ���������, ����� �� �����������1 (��� ����� ��������� �� ������ �������) 
    // � ������ ���������� �����������1 � ������� 3, ������� (��� ����� ��������� �� ������ �������) �����������2
    // � ��


    if (max1 < 0)
        max1 = min1;
    if (max2 < 0)
        max2 = min2;


    if (max1 >= min2) {
        return "NO INTERSECTIONS";
    }
    
  //������������ ������ ����� � ������

    //��������� ������ ������ ������
    double a = max1;
    int b = a * 100;
    int c = b;
    i = 0;
    while (c != 0) {
        c = c / 10;
        i++;
    }
    int firstSymble = 0;

    //���� ����
    if (a < 0) {
        firstSymble = 1;
        b = b * (-1);
    }
    int lenght1 = i + 1 + firstSymble;


    //��������� ������ ������ ������
    
    double a1 = min2;
    int b1 = a1*100;

    int c1 = b1;
    int i1 = 0;
    while (c1 != 0) {
        c1 = c1 / 10;
        i1++;
    }
    int firstSymble1 = 0;

    //���� ����
    if (a1 < 0) {
        firstSymble1 = 1;
        b1 = -b1;
    }
    int lenghtTwo = i1 + 1 + firstSymble1;
    //���������� ������
    char* string1 = new char[lenght1 + lenghtTwo + 2];
    string1[lenght1 + lenghtTwo + 1] = '\0';
    if (firstSymble == 1)
        string1[0] = '-';

    for (int j = lenght1 - 1; j >= firstSymble; j--)
    {
        if ((lenght1 - j) == 3) //����� ��� �������
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

    //������� ������ �����
    if (firstSymble1 == 1)
        string1[lenght1 + 1] = '-';



    // for (int j = lenght1 - 1; j >= firstSymble; j--)
    for (int j = lenght1 + lenghtTwo; j >= lenght1 + 1 + firstSymble1; j--)
    {
        if ((lenght1 + lenghtTwo - j) == 2) //����� ��� �������
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
    //����� ���� ����� ��� � �� file.txt
    char* answer = "6.25 7.13";
    char* result = Function2("file2.txt");
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(result[i], answer[i]);
    }
}
