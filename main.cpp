#include <iostream>
#include <cstring>
#include "mylib.h"
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    int arr[10];
    int i = 0;
    if (argc == 3) {
        if (strcmp(argv[1], "--tofile") == 0) {
            int k = obrabotka(i, arr);
            if (k == -1000000)
                std::cout << "Ошибка ввода";
            else {
                sort(arr, k);
                char *arr1;
                arr1 = new char[arr[k-1]];
                rabota(arr1, arr, k, argv[2]);
            }
        }
        if (strcmp(argv[1], "--fromfile") == 0) {
            int k = obrabotka2(i, arr,argv[2]);
            if (k == -1000000)
                std::cout << "Ошибка ввода";
            else {
                sort(arr, k);
                char *arr1;
                arr1 = new char[arr[k-1]];
                rabota2(arr1, arr, k);
            }
        }
    }
    if (argc == 5) {
        if (strcmp(argv[2], "--tofile") == 0 && strcmp(argv[1], "--fromfile") == 0) {
            int k = obrabotka1(i, arr,argv[3]);
            if (k == -1000000)
                std::cout << "Ошибка ввода";
            else {
                sort(arr, k);
                char *arr1;
                arr1 = new char[arr[k-1]];
                rabota1(arr1, arr, k, argv[4]);
            }
        }
    }
}