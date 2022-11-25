#include <iostream>
#include <cstring>
#include "functions.h"

/**
 * \mainpage Лабораторная работа №3
 * Программа получает на вход количество отрезков и координаты их начала и конца.
 * После чего возвращает координаты отрезков, полученных путем объединения выходных отрезков.\n\n
 *
 * Ввод:\n\n
 * 5\n
 * 1.2 3.4\n
 * -1.8 0.1\n
 * 0.5 1.5\n
 * 1.3 2.8\n
 * -2 -1\n\n
 * Вывод:\n\n
 * Segment 1: -2 0.1\n
 * Segment 2: 0.5 3.4\n\n
 * 
 * Для того, чтобы скомпилировать программу, необходимо написать в консоли make.
 * Команда make clean удаляет объектные файлы, команда make distclean удаляет объектные 
 * файлы и скомпилированную программу.  
 */

/**
 * \brief Обрабатывает параметры запуска.
 * \param[in] argc - количество параметров запуска
 * \param[in] argv - список параметров запуска
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
 *
 * В зависимости от введеных при запуске флагов определяет, откуда будут поступать данные, 
 * и куда их потом нужно будет вывести. Флаг --tofile сообщает, что вывод будет производиться
 * в файл, после него указывается имя файла. Флаг --fromfile сообщает, что ввод будет производиться 
 * из файла, после него указывается имя файла. Возможна обработка обоих флагов одновременно.
 * Если во время выполнения произошла ошибка, то выведется ошибка, и программа закончит выполнение 
 * с кодом 1, иначе с кодом 0.
 */
int main(int argc, char ** argv) {
    switch (argc) {
        case 1:
            if (read()) exit(1);
            solver(0, "NO");
            break;
        case 2:
            if (strcmp("--help", argv[1]))
                exit(1);
            usage();
            break;
        case 3:
            if (!strcmp("--tofile", argv[1])) {
                if (read()) exit(1);
                solver(1, argv[2]);
            }
            else if (!strcmp("--fromfile", argv[1])) {
                if (read(argv[2])) exit(1);
                solver(0, "NO");
            }
            else {
                std::cerr << "### Wrong flags ###\n";
                usage();
                exit(1);
            }
            break;
        case 5:
            if (!strcmp("--fromfile", argv[1]) && 
                !strcmp("--tofile", argv[3])) {
                if (read(argv[2])) exit(1);
                solver(1, argv[4]);
            }
            else if (!strcmp("--fromfile", argv[3]) && 
                     !strcmp("--tofile", argv[1])) {
                if (read(argv[4])) exit(1);
                solver(1, argv[2]);
            }
            else {
                std::cerr << "### Wrong flags ###\n";
                usage();
                exit(1);
            }
            break;
        default:
            std::cerr << "### Wrong flags ###\n";
            usage();
            exit(1);
    }
    exit(0);
}
