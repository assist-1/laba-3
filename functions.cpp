#include <iostream>
#include <fstream>

int length;
double *start;
double *end;

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

int read_f(char *file_name) {
    std::ifstream file;
    file.open(file_name);

    file >> length;
    /* ДОПИСАТЬ */
    return 0;
}

void print(double cs, double ce, int seg_ind) {
    std::cout << "Segment " << seg_ind++ << ": "
              << cs << '\t' << ce << std::endl;
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

int solver(int file = 0) {
    sort();

    int seg_ind = 1;
    int flag = 0;

    if (!length) return 1;
    
    double cs = start[0]; double ce = end[0];
    for (int i = 1; i < length; ++i) {
        if (start[i] >= cs && start[i] <= ce)
            ce = max(ce, end[i]);
        else {
            if (!file) print(cs, ce, seg_ind++);
            cs = start[i]; ce = end[i];
        }
    }

    if (!file) print(cs, ce, seg_ind++);
    return 0;
}

int main() {
    if (read())
        return 1;
    solver();

    return 0;
}


