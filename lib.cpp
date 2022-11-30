#include <cstring>
#include <iostream>

/**
 * Проверка вводимых флагов, вводимых в консоле при запуске программы, на правильность
 * \param argc Количество полученных аргументов
 * \param argv Сами полученные аргументы
 * \return При отсутсnвии дополнительных флагов вернет 0, если есть "--fromfile" - 1, "--togile" - 2, если оба - 2,
 * при введении большего количества флагов либо наличие неверных вернет -1.
 */
int  check_args(int argc, char** argv){
    if(argc == 1){
        return 0;
    }
    if(argc == 2){
        if(!strcmp(argv[1], "--fromfile")){
            return 1;
        }
        if(!strcmp(argv[1], "--tofile")){
            return 2;
        }
    }
    if(argc == 3){
        if(!strcmp(argv[1], "--tofile") && !strcmp(argv[2], "--fromfile") ||
        !strcmp(argv[2], "--tofile") && !strcmp(argv[1], "--fromfile")){
            return 3;
        }
    }
    return -1;
}


/**
 * Фукнция сортирует двумерный массив по первому элементу вложенного массива
 * \param array ссылка на массив, который нужно отсортировать, поскольку сортируется изначальный массив, то функция void
 * \param len длина сортируевомого массива (имеется в виду его первого уровня, длины вложенных массивов не важны)
 */
void sort(int** array, int len){
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len - 1; ++j){
            if(array[j][0] > array[j + 1][0]){
                std::swap(array[j], array[j + 1]);
            }
        }
    }

}