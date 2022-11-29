/*!
\file
\brief  MAIN FILE
*/

#include <iostream>
#include <fstream>
#include "Functions.h"

int main(int argc, char **argv) {
    /*!
    \brief  **если нет флага**
    \code
    if (argc == 1) {
        std::cerr << "Enter the '--tofile' or '--fromfile'";
        return 0;
    }
    \endcode
    */
    if (argc == 1) {
        std::cerr << "Enter the '--tofile' or '--fromfile'";
        return 0;
    }
    /*!
    \brief **если флагов больше двух или первый флаг не равен,и "tofile", "--fromfile"**
    \code
    if ((strcmp(argv[1], "--tofile") == 1 && strcmp(argv[1], "--fromfile") == 1) || argc > 3) {
        std::cerr << "Wrong command, try again";
        return 0;
    }
    \endcode
    */
    if ((strcmp(argv[1], "--tofile") == 1 && strcmp(argv[1], "--fromfile") == 1) || argc > 3) {
        std::cerr << "Wrong command, try again";
        return 0;
    }
    /*!
    \brief **если флаг один и равен "--tofile"**
    \code
    if ((strcmp(argv[1], "--tofile") == 0) && argc == 2) {
        std::ofstream output;//создаем объект класса ofstream
        output.open("output1.txt");//связываем объект с файлом
        if (output.is_open()) {
            int N;//количество отрезков
            std::cin >> N;
            if (N < 1 || N > 10000) {//проверка на то,что количество отрезков больше 0 и меньше 10001
                std::cerr << "Numbers of rows > 0 and <= 10000";
            }
            Obj obj;//создаем переменную типа Obj
            Obj A[N];//создаем массив А, который хранит набор значений типа Obj
            for (int i = 0; i < N; i++) {
                std::cin >> obj.start;
                std::cin >> obj.end;
                if (obj.start > obj.end) {//проверка на то, что конец отрезка не может быть перед его началом
                    std::cerr << "The end can't be before the start";
                }
                A[i] = obj;//добавляем значения в массив А
            }
            //сортировка массива методом пузырька по началу отрезка
            for (int i = 0; i + 1 < N; i++) {
                for (int j = 0; j + 1 < N - i; j++) {
                    if (A[j + 1] < A[j]) {
                        swapp(A[j], A[j + 1]);
                    }
                }
            }
            //в отсортированном массиве находим пересечения отрезков
            double l = 0, r = 0;//создаем перменные которые хранят в своих значениях координаты объеденения
            int cnt = 0;
            for (int i = 0; i + 1 < N; i++) {
                if (A[i].end >= A[i + 1].start &&
                    cnt == 0) {//если до этого не было объеденения и конец первого >= начала второго
                    l = A[i].start;//присваиваем значению l начало первого отрезка
                    r = max(A[i].end, A[i + 1].end);//присаиваем r максимальный конец из двух отрезков
                    cnt += 1;//в счетчик записываем, что было объеденение
                } else if (r >= A[i + 1].start &&
                           cnt != 0) {//если до этого было хотя бы одно объеденение и конец первого >= начала второго
                    r = max(r, A[i + 1].end);//присаиваем r максимальный конец из двух отрезков, l не меняем
                    cnt += 1;//в счетчик записываем, что было объеденение
                } else {//конец первого < начала второго и было объеденение, то выводим ответ
                    if (l != 0 && r != 0) {
                        output << l << " " << r << std::endl;
                    }
                    cnt = 0;//зануляем счетчик
                }
            }
            if (cnt >= 1) {//если счетчик больше 1, то осталось объеденение, которое мы не вывели
                output << l << " " << r;
            }
            if (l == 0 && r == 0) {//если объеденений не было, выводим "NOTHING FOUND"
                output << "NOTHING FOUND";
            }
        }
    }
    \endcode
    */
    if ((strcmp(argv[1], "--tofile") == 0) && argc == 2) {
        std::ofstream output;//создаем объект класса ofstream
        output.open("output1.txt");//связываем объект с файлом
        if (output.is_open()) {
            int N;//количество отрезков
            std::cin >> N;
            if (N < 1 || N > 10000) {//проверка на то,что количество отрезков больше 0 и меньше 10001
                std::cerr << "Numbers of rows > 0 and <= 10000";
            }
            Obj obj;//создаем переменную типа Obj
            Obj A[N];//создаем массив А, который хранит набор значений типа Obj
            for (int i = 0; i < N; i++) {
                std::cin >> obj.start;
                std::cin >> obj.end;
                if (obj.start > obj.end) {//проверка на то, что конец отрезка не может быть перед его началом
                    std::cerr << "The end can't be before the start";
                }
                A[i] = obj;//добавляем значения в массив А
            }
            //сортировка массива методом пузырька по началу отрезка
            for (int i = 0; i + 1 < N; i++) {
                for (int j = 0; j + 1 < N - i; j++) {
                    if (A[j + 1] < A[j]) {
                        swapp(A[j], A[j + 1]);
                    }
                }
            }
            //в отсортированном массиве находим пересечения отрезков
            double l = 0, r = 0;//создаем перменные которые хранят в своих значениях координаты объеденения
            int cnt = 0;
            for (int i = 0; i + 1 < N; i++) {
                if (A[i].end >= A[i + 1].start &&
                    cnt == 0) {//если до этого не было объеденения и конец первого >= начала второго
                    l = A[i].start;//присваиваем значению l начало первого отрезка
                    r = max(A[i].end, A[i + 1].end);//присаиваем r максимальный конец из двух отрезков
                    cnt += 1;//в счетчик записываем, что было объеденение
                } else if (r >= A[i + 1].start &&
                           cnt != 0) {//если до этого было хотя бы одно объеденение и конец первого >= начала второго
                    r = max(r, A[i + 1].end);//присаиваем r максимальный конец из двух отрезков, l не меняем
                    cnt += 1;//в счетчик записываем, что было объеденение
                } else {//конец первого < начала второго и было объеденение, то выводим ответ
                    if (l != 0 && r != 0) {
                        output << l << " " << r << std::endl;
                    }
                    cnt = 0;//зануляем счетчик
                }
            }
            if (cnt >= 1) {//если счетчик больше 1, то осталось объеденение, которое мы не вывели
                output << l << " " << r;
            }
            if (l == 0 && r == 0) {//если объеденений не было, выводим "NOTHING FOUND"
                output << "NOTHING FOUND";
            }
        }
    }
    /*!
    \brief **если флаг один и равен "--fromfile"**
    \code
    if ((strcmp(argv[1], "--fromfile") == 0) && argc == 2) {
        std::ifstream fin;
        fin.open("input.txt");
        int N;
        fin >> N;
        if (N < 1 || N > 10000) {
            std::cerr << "Numbers of rows > 0 and <= 10000";
        }
        Obj obj;
        Obj A[N];
        for (int i = 0; i < N; i++) {
            fin >> obj.start;
            fin >> obj.end;
            if (obj.start > obj.end) {
                std::cerr << "The end can't be before the start";
            }
            A[i] = obj;
        }

        for (int i = 0; i + 1 < N; i++) {
            for (int j = 0; j + 1 < N - i; j++) {
                if (A[j + 1] < A[j]) {
                    swapp(A[j], A[j + 1]);
                }
            }
        }

        double l = 0, r = 0;
        int cnt = 0;
        for (int i = 0; i + 1 < N; i++) {
            if (A[i].end >= A[i + 1].start && cnt == 0) {
                l = A[i].start;
                r = max(A[i].end, A[i + 1].end);
                cnt += 1;
            } else if (r >= A[i + 1].start && cnt != 0) {
                r = max(r, A[i + 1].end);
                cnt += 1;
            } else {
                if (l != 0 && r != 0) {
                    std::cout << l << " " << r << std::endl;
                }
                cnt = 0;
            }
        }
        if (cnt >= 1) {
            std::cout << l << " " << r;
        }
        if (l == 0 && r == 0) {
            std::cout << "NOTHING FOUND";
        }
        fin.close();
    }
    \endcode
    */
    if ((strcmp(argv[1], "--fromfile") == 0) && argc == 2) {
        std::ifstream fin;
        fin.open("input.txt");
        int N;
        fin >> N;
        if (N < 1 || N > 10000) {
            std::cerr << "Numbers of rows > 0 and <= 10000";
        }
        Obj obj;
        Obj A[N];
        for (int i = 0; i < N; i++) {
            fin >> obj.start;
            fin >> obj.end;
            if (obj.start > obj.end) {
                std::cerr << "The end can't be before the start";
            }
            A[i] = obj;
        }

        for (int i = 0; i + 1 < N; i++) {
            for (int j = 0; j + 1 < N - i; j++) {
                if (A[j + 1] < A[j]) {
                    swapp(A[j], A[j + 1]);
                }
            }
        }

        double l = 0, r = 0;
        int cnt = 0;
        for (int i = 0; i + 1 < N; i++) {
            if (A[i].end >= A[i + 1].start && cnt == 0) {
                l = A[i].start;
                r = max(A[i].end, A[i + 1].end);
                cnt += 1;
            } else if (r >= A[i + 1].start && cnt != 0) {
                r = max(r, A[i + 1].end);
                cnt += 1;
            } else {
                if (l != 0 && r != 0) {
                    std::cout << l << " " << r << std::endl;
                }
                cnt = 0;
            }
        }
        if (cnt >= 1) {
            std::cout << l << " " << r;
        }
        if (l == 0 && r == 0) {
            std::cout << "NOTHING FOUND";
        }
        fin.close();
    }
    /*!
    \brief **если флага два и первый из них "--tofile", а второй "--fromfile"**
    \code
    if (argc == 3) {
        if (strcmp("--tofile", argv[1]) == 0) {
            if (strcmp("--fromfile", argv[2]) == 0) {
                std::ifstream kin;
                kin.open("input.txt");
                std::ofstream output;
                output.open("output1.txt");
                if (output.is_open()) {
                    int N;
                    kin >> N;
                    if (N < 1 || N > 10000) {
                        std::cerr << "Numbers of rows > 0 and <= 10000";
                    }
                    Obj obj;
                    Obj A[N];
                    for (int i = 0; i < N; i++) {
                        kin >> obj.start;
                        kin >> obj.end;
                        if (obj.start > obj.end) {
                            std::cerr << "The end can't be before the start";
                        }

                        A[i] = obj;
                    }

                    for (int i = 0; i + 1 < N; i++) {
                        for (int j = 0; j + 1 < N - i; j++) {
                            if (A[j + 1] < A[j]) {
                                swapp(A[j], A[j + 1]);
                            }
                        }
                    }

                    double l = 0, r = 0;
                    int cnt = 0;
                    for (int i = 0; i + 1 < N; i++) {
                        if (A[i].end >= A[i + 1].start && cnt == 0) {
                            l = A[i].start;
                            r = max(A[i].end, A[i + 1].end);
                            cnt += 1;
                        } else if (r >= A[i + 1].start && cnt != 0) {
                            r = max(r, A[i + 1].end);
                            cnt += 1;
                        } else {
                            if (l != 0 && r != 0) {
                                output << l << " " << r << std::endl;
                            }
                            cnt = 0;
                        }
                    }
                    if (cnt >= 1) {
                        output << l << " " << r;
                    }
                    if (l == 0 && r == 0) {
                        output << "NOTHING FOUND";
                    }
                    kin.close();
                }
            } else {
                std::cerr << "Wrong command, try again";
                return 0;
            }
        } else {
            std::cerr << "Wrong command, try again";
            return 0;
        }
    }
    \endcode
    */
    if (argc == 3) {
        if (strcmp("--tofile", argv[1]) == 0) {
            if (strcmp("--fromfile", argv[2]) == 0) {
                std::ifstream kin;
                kin.open("input.txt");
                std::ofstream output;
                output.open("output1.txt");
                if (output.is_open()) {
                    int N;
                    kin >> N;
                    if (N < 1 || N > 10000) {
                        std::cerr << "Numbers of rows > 0 and <= 10000";
                    }
                    Obj obj;
                    Obj A[N];
                    for (int i = 0; i < N; i++) {
                        kin >> obj.start;
                        kin >> obj.end;
                        if (obj.start > obj.end) {
                            std::cerr << "The end can't be before the start";
                        }

                        A[i] = obj;
                    }

                    for (int i = 0; i + 1 < N; i++) {
                        for (int j = 0; j + 1 < N - i; j++) {
                            if (A[j + 1] < A[j]) {
                                swapp(A[j], A[j + 1]);
                            }
                        }
                    }

                    double l = 0, r = 0;
                    int cnt = 0;
                    for (int i = 0; i + 1 < N; i++) {
                        if (A[i].end >= A[i + 1].start && cnt == 0) {
                            l = A[i].start;
                            r = max(A[i].end, A[i + 1].end);
                            cnt += 1;
                        } else if (r >= A[i + 1].start && cnt != 0) {
                            r = max(r, A[i + 1].end);
                            cnt += 1;
                        } else {
                            if (l != 0 && r != 0) {
                                output << l << " " << r << std::endl;
                            }
                            cnt = 0;
                        }
                    }
                    if (cnt >= 1) {
                        output << l << " " << r;
                    }
                    if (l == 0 && r == 0) {
                        output << "NOTHING FOUND";
                    }
                    kin.close();
                }
            } else {
                std::cerr << "Wrong command, try again";
                return 0;
            }
        } else {
            std::cerr << "Wrong command, try again";
            return 0;
        }
    }
    return 0;
}
