#include <iostream>
#include <stack>
#include <fstream>
#include <cmath> 

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
    std::ofstream out;          // поток для записи
    out.open(filename); // окрываем файл для записи
    if (out.is_open())
    {
        int count;
        char str[256]="";
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

void Function(char* filename) {
    int lenght2 = lenght(filename);
    char *str= new char[lenght2+1];
    char ch;
    int i = 0; //Длина всего
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
    //Считаем количество строк
    while (str[j] != '\n') {
        count = count * 10 + (str[j] - '0');
        j++;
    }
    j++;

    //Считаем первое число число
    bool flag1 = false;
    int znak1 = 1;
    //Считаем знак
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
            //Целая часть
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


    //Считаем вторе число
    //Считаем знак
    flag1 = false;
    znak1 = 1;
    //Считаем знак
    if (str[j] == '-') {
        znak1 = -1;
        j++;
    }

    stepen = 1;
    //Считаем второе число число число
    while (str[j] != '\n')
    {
        if ((str[j] == '.') || (str[j] == ',')) {
            flag1 = true;
        }
        else {
            //Целая часть
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






    //Считаем все оставшиеся
    while (j <= i - 1) {
        float Local1 = 0;
        float Local2 = 0;
        //Считаем первое число число
        bool flag1 = false;
        int znak1 = 1;
        //Считаем знак
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
                //Целая часть
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

        //Считаем вторе число
        //Считаем знак
        flag1 = false;
        znak1 = 1;
        //Считаем знак
        if (str[j] == '-') {
            znak1 = -1;
            j++;
        }

        stepen = 1;
        //Считаем второе число число число
        while (str[j] != '\n')
        {
            if ((str[j] == '.') || (str[j] == ',')) {
                flag1 = true;
            }
            else {
                //Целая часть
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

        //Найдём минимальное и максимальные значения левых и правых точек
        if (Local1 < min1)
            min1 = Local1;
        else if (Local1 > max1)
            max1 = Local1;

        if (Local2 < min2)
            min2 = Local2;
        else if (Local2 > max2)
            max2 = Local2;
    }

    //Чтобы было пересечение, ни одна правая точка пересечения не должна лежать левее любой левой
    //Чтобы было пересечение, ни одна левая точка пересечения не должна лежать правее любой правой
    //Это выводится из того, что можем брать по два отрезочка, брать их пересечение1 (оно будет находится по данной формуле) 
    // а возьмём переечение пересечение1 и отрезка 3, получим (оно будет находится по данной формуле) пересечение2
    // и тд
    std::cout << min1 << " " << max1 << " " << min2 << " " << max2;

    if (max2 < 0)
        max2 = min2;

    if (max1<min2)
        std::cout << max1 << " " << min2;
    else
        std::cout << "NO INTERSECTIONS";
}

void Function2(char* filename) {
    Write(filename);
    Function(filename);
}