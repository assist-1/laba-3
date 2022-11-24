#include "functions.hpp"

void Sort(double *array1, double *array2, int count) {
    for (int k = 0; k < count - 1; ++k) {
        for (int j = count - 1; j >= k + 1; --j) {
            if (array1[j - 1] > array1[j]) {
                Swap((array1 + j - 1), (array1 + j));
                Swap((array2 + j - 1), (array2 + j));
            }
        }
    }
}

void Swap(double *a, double *b) {
    double c;
    c = *b;
    *b = *a;
    *a = c;
}

void MainFunction(double *arrBegin, double *arrEnd, int count, bool &k) {
    Sort(arrBegin, arrEnd, count);
    for (int l = 1; l < count; ++l) {
        if (arrBegin[l] < arrEnd[l - 1]) {
            k = true;
            if (arrEnd[l] > arrEnd[l - 1]) {
                arrEnd[l - 1] = arrEnd[l];
            }
            for (int m = l; m < count - 1; ++m) {
                arrBegin[m] = arrBegin[m + 1];
                arrEnd[m] = arrEnd[m + 1];
            }
        }
    }
}

int TaskFromFile(std::ifstream &file) {
    if (!file.is_open()) {
        return -1;
    }

    char symbol = file.peek();
    if (!(symbol >= '1' && symbol <= '9')) {
        std::cerr << "Incorrect enter" << std::endl;
        return -1;
    }
    int count;
    file >> count;
    double *arrBegin = new double[count + 1];
    double *arrEnd = new double[count + 1];
    double a;
    double b;
    int i = 0;
    while (i < count && file) {
        file >> a >> b;
        if (a >= b) {
            std::cerr << "Incorrect enter" << std::endl;
            delete[] arrEnd;
            delete[] arrBegin;
            return -1;
        }
        arrBegin[i] = a;
        arrEnd[i] = b;
        ++i;
    }
    bool k = false;
    MainFunction(arrBegin, arrEnd, count, k);
    if (!k) {
        std::cerr << "NOTHING FOUND" << std::endl;
        delete[] arrEnd;
        delete[] arrBegin;
        return -2;
    }
    std::cout << arrBegin[0] << " " << arrEnd[0] << std::endl;
    int l = 1;
    while (arrEnd[l] != arrBegin[l] && arrBegin[l] > arrEnd[l - 1]) {
        std::cout << arrBegin[l] << " " << arrEnd[l] << std::endl;
        ++l;
    }
    delete[] arrEnd;
    delete[] arrBegin;
    return 0;
}

int TaskToFile(std::ofstream &file) {
    int count;
    char symbol = std::cin.peek();
    if (!(symbol >= '1' && symbol <= '9')) {
        std::cerr << "Incorrect enter" << std::endl;
        return -1;
    }
    std::cin >> count;
    double *arrBegin = new double[count + 1];
    double *arrEnd = new double[count + 1];
    double a;
    double b;
    int i = 0;
    while (i < count) {
        std::cin >> a >> b;
        if (a >= b) {
            std::cerr << "Incorrect enter" << std::endl;
            delete[] arrEnd;
            delete[] arrBegin;
            return -1;
        }
        arrBegin[i] = a;
        arrEnd[i] = b;
        ++i;
    }
    bool k = false;
    MainFunction(arrBegin, arrEnd, count, k);
    if (!k) {
        std::cerr << "NOTHING FOUND" << std::endl;
        delete[] arrEnd;
        delete[] arrBegin;
        return -2;
    }
    file << arrBegin[0] << " " << arrEnd[0] << std::endl;
    int l = 1;
    while (arrEnd[l] != arrBegin[l] && arrBegin[l] > arrEnd[l - 1]) {
        file << arrBegin[l] << " " << arrEnd[l] << std::endl;
        ++l;
    }
    delete[] arrEnd;
    delete[] arrBegin;
    return 0;
}

int TaskFromToFile(std::fstream &file) {
    if (!file.is_open()) {
        return -1;
    }
    int count;
    char symbol = file.peek();
    if (!(symbol >= '1' && symbol <= '9')) {
        std::cerr << "Incorrect enter" << std::endl;
        return -1;
    }
    file >> count;
    double *arrBegin = new double[count + 1];
    double *arrEnd = new double[count + 1];
    double a;
    double b;
    int i = 0;
    while (i < count && file) {
        file >> a >> b;
        if (a >= b) {
            std::cerr << "Incorrect enter" << std::endl;
            delete[] arrEnd;
            delete[] arrBegin;
            return -1;
        }
        arrBegin[i] = a;
        arrEnd[i] = b;
        ++i;
    }
    bool k = false;
    MainFunction(arrBegin, arrEnd, count, k);
    if (!k) {
        std::cerr << "NOTHING FOUND" << std::endl;
        delete[] arrEnd;
        delete[] arrBegin;
        return -2;
    }
    file << arrBegin[0] << " " << arrEnd[0] << std::endl;
    int l = 1;
    while (arrEnd[l] != arrBegin[l] && arrBegin[l] > arrEnd[l - 1]) {
        file << arrBegin[l] << " " << arrEnd[l] << std::endl;
        ++l;
    }
    delete[] arrEnd;
    delete[] arrBegin;
    return 0;
}