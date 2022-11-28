#include "header.h"

int main(int argc, char **argv) {
    int n, i = 0, kol = 0;
    double ch1, ch2;
    if (argc == 1) {
        std::cout << "Enter the number of pairs \n";
        cin >> n;
        int m = n;
        double begin[m + 1], end[m + 1], otv[m + 1];
        std::cout << "Enter pairs \n";
        while (m != 0) {
            cin >> ch1 >> ch2;
            if (ch2 <= ch1) {
                std::cout << "Invalid input \n";
                return 0;
            }
            begin[i] = ch1;
            end[i] = ch2;
            ++i;
            --m;
        }
        begin[n] = 0;
        end[n] = 0;
        swap(begin, end, n);
        for (int h = 0; h < n+1; ++h) {
            if (begin[h] == 0 && end[h] == 0) {
                del(begin, end, n, h);
            }
        }
        int j = 0;
        while (j < n - 1) {
            if (end[j] >= begin[j + 1] && end[j + 1] < end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            } else if (end[j] >= begin[j + 1] && end[j + 1] > end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                end[j] = end[j + 1];
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            }
            ++j;
        }
        if (kol == 0) {
            std::cout << "NOTHING FOUND \n";
            return 0;
        } else {
            for (int z = 0; z < n; z += 2) {
                if (kol > 0) {
                    kol -= 2;
                    std::cout << otv[z] << " " << otv[z + 1] << "\n";
                } else {
                    return 0;
                }
            }
        }
    } else if (argc == 3 && strcmp(argv[1], "--fromfile") == 0) {
        std::ifstream inp(argv[2]);
        if (!inp.is_open()){
            return -1;
        }
        // cin.rdbuf(inp.rdbuf());
        inp >> n;
        int m = n;
        double begin[m + 1], end[m + 1], otv[m + 1];
        while (m != 0) {
            inp >> ch1 >> ch2;
            if (ch2 <= ch1) {
                std::cout << "Invalid input \n";
                inp.close();
                return 0;
            }
            begin[i] = ch1;
            end[i] = ch2;
            ++i;
            --m;
        }
        begin[n] = 0;
        end[n] = 0;
        swap(begin, end, n);
        for (int h = 0; h < n+1; ++h) {
            if (begin[h] == 0 && end[h] == 0) {
                del(begin, end, n, h);
            }
        }
        int j = 0;
        while (j < n - 1) {
            if (end[j] >= begin[j + 1] && end[j + 1] < end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            } else if (end[j] >= begin[j + 1] && end[j + 1] > end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                end[j] = end[j + 1];
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            }
            ++j;
        }
        if (kol == 0) {
            std::cout << "NOTHING FOUND \n";
            inp.close();
            return 0;
        } else {
            for (int z = 0; z < n; z += 2) {
                if (kol > 0) {
                    kol -= 2;
                    std::cout << otv[z] << " " << otv[z + 1] << "\n";
                } else {
                    inp.close();
                    return 0;
                }
            }
        }
    } else if (argc >= 2 && strcmp(argv[1], "--tofile") == 0 && argc <= 3) {
        std::ofstream f;
        if (argc == 3) {
            f.open(argv[2]);
        } else if (argc == 2) {
            f.open("output.txt");
        }
        std::cout << "Enter the number of pairs \n";
        cin >> n;
        int m = n;
        double begin[m + 1], end[m + 1], otv[m + 1];
        std::cout << "Enter pairs \n";
        while (m != 0) {
            cin >> ch1 >> ch2;
            if (ch2 <= ch1) {
                f << "Invalid input \n";
                f.close();
                return 0;
            }
            begin[i] = ch1;
            end[i] = ch2;
            ++i;
            --m;
        }
        begin[n] = 0;
        end[n] = 0;
        swap(begin, end, n);
        for (int h = 0; h < n+1; ++h) {
            if (begin[h] == 0 && end[h] == 0) {
                del(begin, end, n, h);
            }
        }
        int j = 0;
        while (j < n - 1) {
            if (end[j] >= begin[j + 1] && end[j + 1] < end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            } else if (end[j] >= begin[j + 1] && end[j + 1] > end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                end[j] = end[j + 1];
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            }
            ++j;
        }
        if (kol == 0) {
            f << "NOTHING FOUND \n";
            f.close();
            return 0;
        } else {
            for (int z = 0; z < n; z += 2) {
                if (kol > 0) {
                    kol -= 2;
                    f << otv[z] << " " << otv[z + 1] << "\n";
                } else {
                    f.close();
                    return 0;
                }
            }
        }
    } else if (argc == 2 && strcmp(argv[1], "--fromfile") == 0) {
        std::cout << "Enter the file" << "\n";
        return 0;
    }else if (argc >= 3 ) {
        std::ofstream f;
        if (strcmp(argv[1], "--tofile") == 0) {
            if (strcmp(argv[2], "--fromfile") == 0) {
                f.open("output.txt");
            } else if (strcmp(argv[2], "--fromfile") != 0){
                f.open(argv[2]);
            }
        } else if (strcmp(argv[1], "--fromfile") == 0) {
            if (strcmp(argv[3], "--tofile") == 0 && argc == 5) {
                f.open(argv[4]);
            } else {
                f.open("output.txt");
            }
        }
        std::ifstream inp(argv[2]);
        if (!inp.is_open()){
            return -1;
        }
        cin.rdbuf(inp.rdbuf());
        cin >> n;
        int m = n;
        double begin[m + 1], end[m + 1], otv[m + 1];
        while (m != 0) {
            cin >> ch1 >> ch2;
            if (ch2 <= ch1) {
                f << "Invalid input \n";
                f.close();
                inp.close();
                return 0;
            }
            begin[i] = ch1;
            end[i] = ch2;
            ++i;
            --m;
        }
        begin[n] = 0;
        end[n] = 0;
        swap(begin, end, n);
        for (int h = 0; h < n+1; ++h) {
            if (begin[h] == 0 && end[h] == 0) {
                del(begin, end, n, h);
            }
        }
        int j = 0;
        while (j < n - 1) {
            if (end[j] >= begin[j + 1] && end[j + 1] < end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            } else if (end[j] >= begin[j + 1] && end[j + 1] > end[j] && end[j] != begin[j] && end[j + 1] != begin[j + 1]) {
                end[j] = end[j + 1];
                res(begin, end, otv, kol, j);
                kol += 2;
                del(begin, end, n, j + 1);
            }
            ++j;
        }
        if (kol == 0) {
            f << "NOTHING FOUND \n";
            f.close();
            inp.close();
            return 0;
        } else {
            for (int z = 0; z < n; z += 2) {
                if (kol > 0) {
                    kol -= 2;
                    f << otv[z] << " " << otv[z + 1] << "\n";
                } else {
                    f.close();
                    inp.close();
                    return 0;
                }
            }
        }
    }
    return 0;
}