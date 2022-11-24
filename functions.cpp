#include <iostream>
#include <cmath>
//incorrect number of decimal places
const int STREAM_SIZE = 32;

char     stream[STREAM_SIZE];
double * starts;
double * ends;
int      index_stream;
char     token;
double   number1 = 0;
double   number2 = 0;

int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9') return 1;
	return 0;
}
int IsMinus(char symbol) {
	if(symbol == '-') return 1;
	return 0;
}
int IsSpace(char symbol) {
	if(symbol == ' ') return 1;
	return 0;
}
int IsPoint(char symbol) {
	if(symbol == '.') return 1;
	return 0; 
}
int IsCorrectSymbol(char symbol) {
	if(IsDigit(symbol) || IsMinus(symbol) || IsSpace(symbol) || IsPoint(symbol)) return 1;
	return 0;
}
int IsSegment(double a, double b) {
	if(a < b) return 1;
	return 0;
}

double GetNumber(int positive) {
	double whole_part    = 0;
	double decimal_part  = 0;
	int    count_decimal = 0;
	while(IsDigit(stream[index_stream]))
		whole_part = whole_part * 10 + (stream[index_stream++] - '0');

	if(IsPoint(stream[index_stream])) {
		if(IsDigit(stream[index_stream + 1])) {
			index_stream++;
			while(IsDigit(stream[index_stream])) {
				decimal_part = decimal_part * 10 + (stream[index_stream++] - '0');
				count_decimal++;
			}
		}
		else {
			std::cerr << "ERROR: decimal part not found!" << std::endl;
			exit(1);
		}
	}
	else if(IsSpace(stream[index_stream]) || !stream[index_stream]) {
		decimal_part = decimal_part / pow(10, count_decimal);
		if(ceil(trunc(decimal_part * 100))) {
			std::cerr << "ERROR: incorrect number of decimal places!" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "ERROR: segment enteres incorrectly!" << std::endl;
		exit(1);
	}

	if(positive)
		return (whole_part + decimal_part);
	return -(whole_part + decimal_part);
}


void GetResultFromConsole() {
	int NUM_SEGMENTS;
	std::cin >> NUM_SEGMENTS;
	std::cin.ignore();
	starts = new double[NUM_SEGMENTS];
	ends   = new double[NUM_SEGMENTS];
	for(int i = 0; i < NUM_SEGMENTS; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		index_stream = 0;
		while(token = stream[index_stream++]) {
			if(!IsCorrectSymbol(token)) {
				std::cerr << "ERROR: invalid character!" << std::endl;
				exit(1);
			}
		}
		index_stream = 0;

		while(token = stream[index_stream++]) {
			if(IsMinus(token)) {
				if(IsDigit(stream[index_stream])) {
					number1 = GetNumber(0);
				}
				else {
					std::cerr << "ERROR: segment enteres incorrectly!" << std::endl;
					exit(1);
				}
			}
			else if(IsDigit(token)) {
				index_stream--;
				number1 = GetNumber(1);
			}
			else if(IsSpace(token)) {
				if((IsMinus(stream[index_stream]) && IsDigit(stream[index_stream + 1])) || IsDigit(stream[index_stream])) {
					token = stream[index_stream];
					if(IsMinus(token)) {
						index_stream++;
						number2 = GetNumber(0);
					}
					else if(IsDigit(token)) {
						number2 = GetNumber(1);
					}
				}
				else {
					std::cerr << "ERROR: segment enteres incorrectly!" << std::endl;
					exit(1);
				}
			}

		}
		starts[i] = number1;
		ends[i]   = number2;
	}


	std::cout << std::endl;
}

