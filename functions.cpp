#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

const int len = 600;
char vyr[len];

void readfromcin() {
	cin.read(vyr, len - 1);
	int s = cin.gcount();
	vyr[s] = '\0';
}

void bubblesort(int* num, int raz) {
	for (int i = 0; i < raz - 1; i++) {
		for (int j = (raz - 1); j > i; j--) {
			if (num[j - 1] > num[j]) {
				int temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}



void readtofile(char* name) {
	ofstream par;
	par.open(name);
	if (par.is_open()) {
		int i = 0;
		while (vyr[i]) {
			if (vyr[i] == '\n') vyr[i] = ' ';
			par << vyr[i];
			i++;
		}
	}
	else { cout << "No open" << endl; }
	par.close();
}

void readfromfile(char* name) {
	int i = 0;
	ifstream file_in(name);
	noskipws(file_in);
	while (file_in >> vyr[i]) {
		if (vyr[i] == '\n') {
			vyr[i] = ' ';
			vyr[i - 1] = ' ';
		}
		++i;
		if (file_in.peek() == EOF) {
			break;
		}
	}
	//j++;
//}
//int z = 0;
//while (vyr[z]) {
	//cout << vyr[z] << endl;
	//z++;
//}
}

void task() {
	int g = 0;
	int size = 0;
	while (vyr[g]) {
		size++;
		g++;
	}
	int m = 0;
	int k = 0;
	for (int j = 0; j < size; j++) {
		if (vyr[j] == '.' || vyr[j] == '!' || vyr[j] == '?') {
			m++;
		}
	}
	//cout << size << endl;
	//cout << m << endl;
	int* arr = new int[m];
	int x = 0;
	for (int i = 0; i < size; i++) {
		if (vyr[i] != '.' && vyr[i] != '!' && vyr[i] != '?') {
			k++;
		}
		else {
			arr[x] = k;
			k = 0;
			x++;
		}
	}
	for (int i = 1; i < m; i++) {
		arr[i]--;
	}
	//for (int i = 0; i < m; i++) {
		//cout << arr[i] << endl;
	//}
	int* mas = new int[m];
	for (int i = 0; i < m; i++) {
		mas[i] = arr[i];
	}
	bubblesort(arr, m);
	//for (int i = 0; i < m; i++) {
		//cout << mas[i] << endl;
	//}
	int u = 0;
	int p = 0;
	int* rt = new int[m];
	for (int i = 0; i < m; i++) {
		rt[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] == rt[j]) {
				u = 1;
			}
		}
		if (u == 0) {
			rt[p] = arr[i];
		}
		p++;
		u = 0;
	}
	bubblesort(rt, m);
	//for (int i = 0; i < m; i++) {
		//cout << rt[i] << endl;
	//}
	int* sum = new int[m];
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			sum[i] = mas[i];
		}
		else {
			sum[i] = sum[i - 1] + mas[i];
		}
	}
	//for (int i = 0; i < m; i++) {
		//cout << sum[i] << endl;
	//}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (rt[i] == mas[j]) {
				if (j != 0) {
					//if (i != 0) {
					int k = 0;
					int v = sum[j - 1] + 2 * j;
					if (vyr[v] == ' ') k = v + 1;
					else k = v;
					for (int l = k; l <= sum[j] + 2 * j; l++) {
						if (vyr[l] == '\n') {
							cout << ' ';
						}
						else {
							if (l > k && vyr[l] == vyr[l - 1] && vyr[l] == ' ') { continue; }
							else { cout << vyr[l]; }
						}
					}
					cout << endl;
				}
				//else {
					//for (int k = sum[j - 1] + j + 1; k <= sum[j] + j; k++) {
						//cout << str[k];
					//}
					//cout << endl;
				//}
			//}
				else {
					//if (i != 0) {
					for (int l = 0; l <= sum[j]; l++) {
						if (vyr[l] == '\n') {
							cout << ' ';
						}
						else {
							if (l > 0 && vyr[l] == vyr[l - 1] && vyr[l] == ' ') { continue; }
							else { cout << vyr[l]; }
						}
					}
					cout << endl;
				}
				//else {
					//for (int k = 0; k <= sum[j]; k++) {
						//cout << str[k];
					//}
					//cout << endl;
			}
			//}
		}
	}
	int max = 0;
	int f = 0;
	for (int i = 0; i < m; i++) {
		if (mas[i] > max) {
			max = mas[i];
			f = i;
		}
	}
	//cout << max << endl;
	//cout << u << endl;
	ofstream out;
	out.open("NINE.txt");
	if (out.is_open()) {
		int w = 0;
		if (f != 0) {
			for (int i = sum[f] + 2 * f - 1; i >= sum[f - 1] + 2 * f; i--) {
				if (i != (sum[f - 1] + 2 * f)) {
					if (vyr[i] == ' ' || vyr[i] == '\n') {
						for (int j = i + 1; j < i + w + 1; j++) {
							out << vyr[j];
						}
						out << ' ';
						w = 0;
					}
					else {
						w++;
					}
				}
				else {
					for (int j = sum[f - 1] + 2 * f; j < i + w + 1; j++) {
						out << vyr[j];
					}
					out << '.';
				}
			}
		}
		else {
			for (int i = sum[f] - 1; i >= 0; i--) {
				if (i != (sum[f - 1] + 2 * f)) {
					if (vyr[i] == ' ' || vyr[i] == '\n') {
						for (int j = i + 1; j < i + w + 1; j++) {
							out << vyr[j];
						}
						out << ' ';
						w = 0;
					}
					else {
						w++;
					}
				}
				else {
					for (int j = sum[f - 1] + 2 * f; j < i + w + 1; j++) {
						out << vyr[j];
					}
					out << '.';
				}
			}
		}
	}
	else { cout << "No open" << endl; }
	out.close();

	delete[] arr;
	delete[] mas;
	delete[] sum;
	delete[] rt;
}