#include <iostream>
#include <fstream>

int length;
double *start;
double *end;

void usage() {
    std::cout << "USAGE" << std::endl;
}

int read() {
    std::cin >> length;
    if (std::cin.fail() || length < 0) {
        std::cerr << "### Wrong number of segments ###\n";
        return 1;
    }

    start = new double[length];
    end = new double[length];

    for (int i = 0; i < length; ++i) {
        std::cin >> start[i] >> end[i];
        if (std::cin.fail()) {
            std::cerr << "### Wrong segment cooridante(s) ###\n";
            return 1;
        }
    }

    return 0;
}

int read(char const* file_name) {
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open()) {
        std::cerr << "### Input file does not exist ###\n";
        return 1;
    }

    file >> length;
    if (file.fail() || length < 0) {
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

int print(double cs, double ce, int seg_ind) {
    std::cout << "Segment " << seg_ind << ": "
              << cs << '\t' << ce << std::endl;
    return 0;
}

int print(double cs, double ce, int seg_ind, std::ofstream& file) {
    file << "Segment " << seg_ind << ": "
              << cs << '\t' << ce << '\n';
    return 0;
}

double max(double i, double k) {
    if (i > k) return i;
    return k;
}

void swap(int i, int j) {
    double tmp;
    tmp = start[i];
    start[i] = start[j]; start[j] = tmp;
    tmp = end[i];
    end[i] = end[j]; end[j] = tmp;
}

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

int solver(int file = 0, char const file_name[] = "no") {
    std::ofstream f;
    if (file) {
        f.open(file_name);
        if (!f.is_open()) {
            std::cerr << "### Output file does not exist ###\n";
            return 1;
        }
    }
    sort();

    int seg_ind = 1;
    int flag = 0;

    if (!length) return 1;
    
    double cs = start[0]; double ce = end[0];
    for (int i = 1; i < length; ++i) {
        if (start[i] >= cs && start[i] <= ce)
            ce = max(ce, end[i]);
        else {
            if (!file)  print(cs, ce, seg_ind++);
            else if    (print(cs, ce, seg_ind++, f)) return 1;
            cs = start[i]; ce = end[i];
        }
    }

    if (!file)  print(cs, ce, seg_ind++);
    else if    (print(cs, ce, seg_ind++, f)) return 1;

    f.close();

    delete[] start;
    delete[] end;

    return 0;
}

