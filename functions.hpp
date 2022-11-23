#ifndef LABA_FUNCTIONS_HPP
#define LABA_FUNCTIONS_HPP

#include <iostream>
#include <cstring>
#include <fstream>

int TaskFromFile(std::ifstream &file);

void Sort(double *array1, double *array2, int count);

void Swap(double *a, double *b);

void MainFunction(double *arrBegin, double *arrEnd, int count, bool &k);

int TaskToFile(std::ofstream &file);

int TaskFromToFile(std::fstream &file);

int TaskToFile(std::ofstream &file);

#endif //LABA_FUNCTIONS_HPP
