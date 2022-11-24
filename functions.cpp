#include <iostream>
#include <fstream>

int length; ///< Количество отрезков
double *start; ///< Массив начал отрезков
double *end; ///< Массив концов отрезков

/**
 * \brief Выводит в консоль справку.
 *
 * Функция вызывается, если пользователь неверно ввел флаги при запуске программы.
 */
void usage() {
    std::cout << std::endl;
    std::cout << "USAGE: ./prog [--tofile <file_name>] [--fromfile <file_name>]" << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------Flags meaning-----------------------" << std::endl;
    std::cout << "--tofile   ------> write output data in file"                  << std::endl;
    std::cout << "--fromfile ------> read input data from file"                  << std::endl;
    std::cout << std::endl;
}

/**
 * \brief Осуществляет чтение из станадртного потока cin.
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружна ошибка ввода
 *
 * Функция выполняет чтение данных из стандартного потока cin в массивы start[] и end[].
 * Длина массивов задается в процессе выполнения функции.
 * Если произошла ошибка ввода, то выведется соответствующее сообщение, и функция прекратит свое выполнение.
 */
int read() {
    std::cin >> length;
    if (std::cin.fail() || length <= 0) {
        std::cerr << "### Wrong number of segments ###\n";
        return 1;
    }

    start = new double[length];
    end = new double[length];

    for (int i = 0; i < length; ++i) {
        std::cin >> start[i] >> end[i];
        if (std::cin.fail()) {
            std::cerr << "### Wrong segment cooridante(s) ###\n";
            delete[] start;
            delete[] end;
            return 1;
        }
    }

    return 0;
}

/**
 * \brief Осуществляет чтение из файла.
 * \param[in] file_name - имя файла
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружна ошибка
 *
 * Функция выполняет чтение данных из файла в массивы start[] и end[].
 * Длина массивов задается в процессе выполнения функции.
 * Если произошла ошибка ввода или файл не удалось открыть,
 * то выведется соответствующее сообщение, и функция прекратит свое выполнение.
 */
int read(char* file_name) {
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open()) {
        std::cerr << "### Input file does not exist ###\n";
        return 1;
    }

    file >> length;
    if (file.fail() || length <= 0) {
        std::cerr << "### Wrong number of segments ###\n";
        return 1;
    }

    start = new double[length];
    end = new double[length];

    for (int i = 0; i < length; ++i) {
        file >> start[i] >> end[i];
        if (file.fail()) {
            std::cerr << "### Wrong segment cooridante(s) ###\n";
            return 1;
        }
    }
    file.close();

    return 0;
}

/**
 * \brief Осуществляет вывод результата в стандартный поток cout.
 * \param[in] cs - координата начала отрезка
 * \param[in] ce - координата конца отрезка
 * \param[in] seg_ind - номер отрезка
 * \return 0 - функция выполнена успешно
 *
 * Функция выводит в стандартный поток cout номер сегмента, считая слева, и его координаты.
 */
int print(double cs, double ce, int seg_ind) {
    std::cout << "Segment " << seg_ind << ": "
              << cs << '\t' << ce << std::endl;
    return 0;
}

/**
 * \brief Осуществляет вывод результата в файл.
 * \param[in] cs - координата начала отрезка
 * \param[in] ce - координата конца отрезка
 * \param[in] seg_ind - номер отрезка
 * \param[in] file_name - имя файла
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
 *
 * Функция выводит в файл номер сегмента, считая слева, и его координаты.
 * Если файл не существует, то выведется соответствующее значение и функция
 * прекратит свое выполнение.
 */
int print(double cs, double ce, int seg_ind, const char file_name[]) {
    std::ofstream file;
    file.open(file_name, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "### Output file does not exist ###\n";
        return 1;
    }
    file << "Segment " << seg_ind << ": " 
              << cs << '\t' << ce << '\n';
    file.close();
    return 0;
}

/**
 * \brief Возвращает максимальное значение из полученных.
 * \param[in] i, k - переменные для осуществления сравнения
 * \return Максимальное значение
 */
double max(double i, double k) {
    if (i > k) return i;
    return k;
}

/**
 * \brief Меняет местам элементы глобальных массивов.
 * \param[in] i, j - индексы элементов
 *
 * Меняет местами i-ый и j-ый элементы сначала массива start[], затем массива end[].
 */
void swap(int i, int j) {
    double tmp;
    tmp = start[i];
    start[i] = start[j]; start[j] = tmp;
    tmp = end[i];
    end[i] = end[j]; end[j] = tmp;
}

/**
 * \brief Сортирует массивы по возрастанию на основе значений элементов массива start[].
 *
 * Выполняет сортировку вставкой. Сортирует элементы массива start[] по возрастанию и переставляет
 * соответствующие им элементы массива end[].
 */
void sort() {
    int mi;
    for (int i = 0; i < length - 1; ++i) {
        mi = i;
        for (int j = i + 1; j < length; ++j)
            if (start[j] < start[mi])
               mi = j;

        if (mi != i)
            swap(mi, i);
    }
}

/**
 * \brief Находит объединения отрезков.
 * \param[in] file - 0, 1 в зависимости от того, осуществляется вывод в файл или нет
 * \param[in] file_name - имя файла, в который осуществляется вывод
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружна ошибка
 *
 * Функция сортирует массивы start[] и end[] при помощи функции sort(). 
 * Задает стартовые значения начала cs и конца ce отрезка как у первого отрезка.
 * Поочереди проходит по координатам каждого отрезка.
 * Если координата начала данного отрезка лежит между cs и ce, то она становится новой cs,
 * а ce становится максимальной из координт конца отрезка и ce.
 * Иначе выводятся cs и ce, и им присваиваются занчения данного отрезка. 
 */
int solver(int file, const char file_name[]) {
    sort();

    int seg_ind = 1;
    double cs = start[0]; double ce = end[0];
    for (int i = 1; i < length; ++i) {
        if (start[i] >= cs && start[i] <= ce)
            ce = max(ce, end[i]);
        else {
            if (!file)  print(cs, ce, seg_ind++);
            else if    (print(cs, ce, seg_ind++, file_name)) return 1;
            cs = start[i]; ce = end[i];
        }
    }
    delete[] start;
    delete[] end;

    if (!file)  print(cs, ce, seg_ind++);
    else if    (print(cs, ce, seg_ind++, file_name)) return 1;

    return 0;
}

