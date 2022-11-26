#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

const int STREAM_SIZE = 32;
char      stream[STREAM_SIZE];
double *  starts;
double *  ends;
int       index_stream;
char      token;
double    number1 = 0;
double    number2 = 0;

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
	int    empty         = 0;
	while(IsDigit(stream[index_stream]))
		whole_part = whole_part * 10 + (stream[index_stream++] - '0');
	if(IsPoint(stream[index_stream])) {
		if(IsDigit(stream[index_stream + 1])) {
			index_stream++;
			while(IsDigit(stream[index_stream])) {
				empty = empty * 10 + (stream[index_stream++] - '0');
				count_decimal++;
				if(count_decimal > 2) {
					std::cerr << "ERROR: incorrect number of decimal places!" << std::endl;
					exit(1);
				}
			}
		}
		else {
			std::cerr << "ERROR: decimal part not found!" << std::endl;
			exit(1);
		}
	}
	if(IsSpace(stream[index_stream]) || !stream[index_stream])
		decimal_part = empty / pow(10, count_decimal);
	else {
		std::cerr << "ERROR: number must be separated by a space!" << std::endl;
		exit(1);
	}

	if(positive)
		return (whole_part + decimal_part);
	return -(whole_part + decimal_part);
}
double GetMax(double a, double b) {
	if(a > b) return a;
	return b;
}
int GetNumberSegments() {
	int result;
	if(token = stream[index_stream]) {
		while(token = stream[index_stream++]) {
			if(!IsDigit(token)) {
				std::cerr << "ERROR: invalid characters in the natural number of segments input!" << std::endl;
				exit(1);
			}
		}
	}
	else {
		std::cerr << "ERROR: number of segments not entered!" << std::endl;
		exit(1);
	}
	index_stream = 0;
	result = int(GetNumber(1));
	memset(stream, '\0', sizeof(stream));
	if(result <= 0 || result > 10000) {
		std::cerr << "ERROR: You must enter a natural number of segments not exceeding 10000!" << std::endl;
		exit(1);
	}
	return result;
}
void SortSegments(int segments_count) {
	for(int i = 0; i < segments_count; i++) {
		double max_start = -10000000000;
		int index_max = 0;
		double empty;
		for(int j = 0; j < segments_count - i; j++) {
			if(starts[j] > max_start) {
				max_start = starts[j];
				index_max = j;
			}
		}
		empty = starts[segments_count-1-i];
		starts[segments_count-1-i] = starts[index_max];
		starts[index_max] = empty;
		empty = ends[segments_count-1-i];
		ends[segments_count-1-i] = ends[index_max];
		ends[index_max] = empty;
	}
}
void ConvertToSegments(int index) {
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
	if(!IsSegment(number1, number2)) {
		std::cerr << "ERROR: the beginning of the segment must be less than the end!" << std::endl;
		exit(1);
	}
	else {
		starts[index] = number1;
		ends[index]   = number2;
	}
}
void GetResultFromConsole() {
	std::cin.getline(stream, STREAM_SIZE - 1); // водим вол-во отрезков
	int NUM_SEGMENTS = GetNumberSegments();
	starts = new double[NUM_SEGMENTS];
	ends   = new double[NUM_SEGMENTS];
	for(int i = 0; i < NUM_SEGMENTS; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		ConvertToSegments(i);
	}
	SortSegments(NUM_SEGMENTS);

	std::cout << "\n";
	std::cout << "RESULT:" << std::endl;
	std::cout << "\n";
	double glob_start = starts[0];
	double glob_end   = ends[0];
	if(NUM_SEGMENTS == 1) {
		std::cout << glob_start << " " << glob_end << std::endl;
	}
	else {
		for(int i = 1; i < NUM_SEGMENTS; i++) {
			if(starts[i] <= glob_end) {
				glob_end = GetMax(glob_end, ends[i]);
			}
			
			else {
				std::cout << glob_start << " " << glob_end << std::endl;
				glob_start = starts[i];
				glob_end   = ends[i];
			}
		}
		std::cout << glob_start << " " << glob_end << std::endl;
	}
	delete[] starts;
	delete[] ends;
}
void GetResultFromConsole(const char * namefile) {
	std::cin.getline(stream, STREAM_SIZE - 1); // водим вол-во отрезков
	int NUM_SEGMENTS = GetNumberSegments();
	starts = new double[NUM_SEGMENTS];
	ends   = new double[NUM_SEGMENTS];
	for(int i = 0; i < NUM_SEGMENTS; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		ConvertToSegments(i);
	}
	SortSegments(NUM_SEGMENTS);
	

}