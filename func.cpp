#include <fstream>
#include <iostream>
#include "lab5.h"
int k = 0;
int n;
int const T = 10001;
float const END = -1000000000;
float em[T], bm[T];
float e, b;
int temppoint;
int tp;
int binf(float x, float* a, int k) {
	int l = -1;
	int r = k + 1;
	int mid;
	while (r - l > 1) {
		mid = (int)(l + r) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] > x) r = mid;
		else l = mid;
	}
	return l;
}
int check() {
	tp = temppoint + 1;
	while (bm[tp] <= em[temppoint] && bm[tp] != END) {
		em[temppoint] = em[temppoint] < em[tp] ? em[tp] : em[temppoint];
		for (int j = tp; j < k - 1; j++) {
			em[j] = em[j + 1];
			bm[j] = bm[j + 1];
		}
		em[k - 1] = END;
		bm[k - 1] = END;
		--k;
	}
	return 0;
}
int allright(char* argv[]) {
	std::ifstream fin;
	std::ofstream fout;
	if (flag_read == 1 && flag_write == 1) {
		fin.open(argv[2]);
		fout.open(argv[4]);
	}
	else {
		if (flag_read == 1) {
			fin.open(argv[2]);
		}
		if (flag_write == 1) {
			fout.open(argv[2]);
		}
	}
	if (flag_read)
	{
		fin >> n;
	}
	else { std::cin >> n; }
	if (n == 1) { std::cout << "NOTHING FOUND" << std::endl; return 0; }
	for (int i = 0; i < n; i++) {
		if (flag_read)
		{
			fin >> b >> e;
		}
		else { std::cin >> b >> e; }
		if (e <= b) {
			std::cout << "ERROR! Data isn't correct" << std::endl;
			return 0;
		}
		if (k == 0) {
			bm[k] = b;
			em[k] = e;
			++k;
		}
		else {
			temppoint = binf(b, bm, k);
			if (temppoint == -1) {
				if (k>=T) {
					std::cout << "ERROR! Too many values" << std::endl;
					return 0;
				}
				temppoint = 0;
				for (int j = k - 1; j >= temppoint; j--) {
					em[j + 1] = em[j];
					bm[j + 1] = bm[j];
				}
				em[temppoint] = e;
				bm[temppoint] = b;
				k++;
				check();
			}
			else if (temppoint == k) {
				if (b>em[k-1])
				{
					em[temppoint] = e;
					bm[temppoint] = b;
					++k;
				}
				else {
					em[temppoint - 1] = (em[temppoint - 1] < e) ? e : em[temppoint - 1];
				}
			}
			else if (temppoint == k - 1) {
				em[temppoint] = (em[temppoint] < e) ? e : em[temppoint];
			}
			else {
				if (bm[temppoint] == b) {
					if (em[temppoint] < e) {
						em[temppoint] = e;
						check();
					}
				}
				else if (bm[temppoint] < b) {
					if (em[temppoint] >= b) {
						if (em[temppoint] < e) {
							em[temppoint] = e;
							check();
						}
					}
					else {
						if (k >= T) {
							std::cout << "ERROR! Too many values" << std::endl;
							return 0;
						}
						else {
							for (int j = k - 1; j >= temppoint; j--) {
								em[j + 1] = em[j];
								bm[j + 1] = bm[j];
							}
							temppoint = binf(b, bm, k);
							if (temppoint<T)
							{
								em[temppoint] = e;
								bm[temppoint] = b;
								++k;
							}
							check();
						}
					}
				}
			}
		}
	}
	std::cout << ' ' << std::endl;
	for (int i = 0; i < k; i++) {
		if (flag_write == 1) { fout << bm[i] << ' ' << em[i] << std::endl; }
		else { 
			std::cout << bm[i] << ' ' << em[i] << std::endl; }
	}
	fin.close();
	fout.close();
	return 0;
}