#include <iostream>
#include "Header.h"
#include <fstream>

int Fromfile() {
	std::ifstream file;
	file.open(arg[2]);
	if (!file) {
		std::cout << "Error! Can not open file!" << std::endl;
		return 0;
	}
	char stroka[100000];
	char k;
	int i = 1, j, h = 0, chit = 0, p;
	while (file.get(k)) {
		if (i == 1000001) {
			std::cout << "Enter a shorter line" << std::endl;
			return 0;
		}
		if (k == '\n') stroka[i - 1] = '\0';
		else stroka[i - 1] = k;
		i += 1;
	}
	file.close();
	int tochki[1000000];
	int tmp;
	for (j = 0; j < i; j++) {
		if (stroka[j] == '.') {
			tochki[h] = j - h;
			h = j + 2;
			chit += 1;
		}
		else tochki[j] = 0;
	}
	int nine[1000000];
	int minn = 1000000, mini;
	for (j = 0; j < chit; j++) {
		for (p = 0; p < i; p++) {
			if (tochki[p] != 0 && tochki[p] < minn) {
				minn = tochki[p];
				mini = p;
			}
		}
		tmp = mini;
		for (p = mini; p <= mini + minn + 1;p++) {
			if (j == chit - 1 && (stroka[p-1]==' ' || stroka[p-1]=='.')){
				nine[tmp] = p - tmp - 1;
				tmp = p;
			}
			else nine[p] = 0;
			std::cout << stroka[p];
		}
		std::cout << std::endl;
		if (j == chit - 1) {
			std::ofstream file3("NINE.txt");
			for (p = i - 1;p>= 0; p--) {
				if (nine[p] != 0) {
					file3 << ' ';
					for (h=p;h<p+ nine[p]; h++) {
						file3 << stroka[h];
					}
				}
			}
			file3.close();
		}
		tochki[mini] = 0;
		minn = 1000000;
	}
	return 0;
}
int Tofile() {
	std::cout << "Enter the text and at the end, after the period, put '|'" << std::endl;
	char stroka[100000];
	char k;
	int i = 1, j, h = 0, chit = 0, p;
	std::ofstream file;
	if (arc == 3) file.open(arg[2]);
	else file.open("Tofile.txt");
	if (!file) {
		std::cout << "Error! Can not open file!" << std::endl;
		return 0;
	}
	for (j = 0; j <= 100000; j++) {
		if (j == 100000) {
			std::cout << "Enter a shorter line" << std::endl;
			return 0;
		}
		k = getchar();
		if (k == '|') break;
		if (k == '\n') stroka[j] = '\0';
		else stroka[j] = k;
		i = j + 1;
	}
	int tochki[100000];
	for (j = 0; j < i; j++) {
		if (stroka[j] == '.') {
			tochki[h] = j - h;
			h = j + 2;
			chit += 1;
			tochki[j] = 0;
		}
		else tochki[j] = 0;
	}
	int nine[100000],tmp;
	int minn = 100000, mini;
	for (j = 0; j < chit; j++) {
		for (p = 0; p < i; p++) {
			if (tochki[p] != 0 && tochki[p] < minn) {
				minn = tochki[p];
				mini = p;
			}
		}
		tmp = mini;
		for (p = mini; p <= mini + minn + 1; p++) {
			if (j == chit - 1 && (stroka[p - 1] == ' ' || stroka[p - 1] == '.')) {
				nine[tmp] = p - tmp - 1;
				tmp = p;
			}
			else nine[p] = 0;
			file << stroka[p];
		}
		file << std::endl;
		if (j == chit - 1) {
			std::ofstream file3("NINE.txt");
			for (p = i - 1; p >= 0; p--) {
				if (nine[p] != 0) {
					file3 << ' ';
					for (h = p; h < p + nine[p]; h++) {
						file3 << stroka[h];
					}
				}
			}
			file3.close();
		}
		file << std::endl;
		file.flush();
		tochki[mini] = 0;
		minn = 100000;
	}
	file.close();
	std::cout << "Check your file or file Tofile.txt" << std::endl;
	return 0;
}
int Fromtofile() {
	std::ifstream file;
	file.open(arg[3]);
	if (!file) {
		std::cout << "Error! Can not open file!" << std::endl;
		return 0;
	}
	char stroka[100000];
	char k;
	int i = 1, j, h = 0, chit = 0, p;
	while (file.get(k)) {
		if (i == 100001) {
			std::cout << "Enter a shorter line" << std::endl;
			return 0;
		}
		if (k == '\n') stroka[i - 1] = '\0';
		else stroka[i-1] = k;
		i += 1;
	}
	int tochki[100000];
	for (j = 0; j < i; j++) {
		if (stroka[j] == '.') {
			tochki[h] = j - h;
			h = j + 2;
			chit += 1;
			tochki[j] = 0;
		}
		else tochki[j] = 0;
	}
	file.close();
	std::ofstream file2;
	if (arc == 5) file2.open(arg[4]);
	else file2.open("Tofile.txt");
	if (!file2) {
		std::cout << "Error! Can not open file!" << std::endl;
		return 0;
	}
	int nine[100000], tmp;
	int minn = 100000, mini;
	for (j = 0; j < chit; j++) {
		for (p = 0; p < i; p++) {
			if (tochki[p] != 0 && tochki[p] < minn) {
				minn = tochki[p];
				mini = p;
			}
		}
		tmp = mini;
		for (p = mini; p <= mini + minn + 1; p++) {
			if (j == chit - 1 && (stroka[p - 1] == ' ' || stroka[p - 1] == '.')) {
				nine[tmp] = p - tmp - 1;
				tmp = p;
			}
			else nine[p] = 0;
			file2 << stroka[p];
		}
		file2 << std::endl;
		if (j == chit - 1) {
			std::ofstream file3("NINE.txt");
			for (p = i - 1; p >= 0; p--) {
				if (nine[p] != 0) {
					file3 << ' ';
					for (h = p; h < p + nine[p]; h++) {
						file3 << stroka[h];
					}
				}
			}
			file3.close();
		}
		file2 << std::endl;
		file2.flush();
		tochki[mini] = 0;
		minn = 100000;
	}
	file2.close();
	std::cout << "Check your file or file Tofile.txt" << std::endl;
	return 0;
}