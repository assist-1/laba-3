/**
* @file
* @brief Файл, в котором описаны функции для решения задачи об отрезках.
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
//! Константная переменная типа Integer, хранящая величину массива stream, в который записываются символы с входного потока.
const int STREAM_SIZE = 32;
//! Статический массив типа Char, в котором хранится входной поток символов с консоли / файла
char      stream[STREAM_SIZE];
//! Динамический массив типа Double, в котором хранятся начала отрезков
double *  starts;
//! Динамический массив типа Double, в котором хранятся концы отрезков
double *  ends;
//! Переменная типа Integer, предназначенная для обращения к ячейке массива stream
int       index_stream;
//! Переменная типа Char, в который записывается текущий символ входного потока
char      token;
//! Переменная типа Double, в котором будет храниться начало отрезка
double    number1 = 0;
//! Переменная типа Double, в котором будет храниться конец файла
double    number2 = 0;
/**
* @brief Help() - функция для вывода инструкции по работе с программой
*/
void Help() {
	std::cout << "\n";
	std::cout << "##########################################################_INSTRUCTION_#################################################################" << std::endl;
	std::cout << "You must enter:  [./<program_name>] [*] "                                                                                                 << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Instead of the [*], You must enter the following options:"                                                                                << std::endl;
	std::cout << "  1) --help ........................................(output of instructions for working with the program)"                                << std::endl;
	std::cout << "  2) --default .....................................(console input and console output)"                                                   << std::endl;
	std::cout << "  3) --tofile ......................................(console input and default file 'DefaultFile.txt' output)"                            << std::endl;
	std::cout << "  4) --tofile <filename> ...........................(console input and user-selected file output)"                                        << std::endl;
	std::cout << "  5) --fromfile <filename> .........................(user-selected file input and console output)"                                        << std::endl;
	std::cout << "  6) --fromfile <filename> --tofile ................(user-selected file input and default file 'DefaultFile.txt' output)"                 << std::endl;
	std::cout << "  7) --fromfile <filename1> --tofile <filename2> ...(user-selected file input and user-selected file output, neccesary different files!)" << std::endl;
	std::cout << "########################################################################################################################################" << std::endl;
	std::cout << "\n";
}
/**
* @brief IsDigit() - функция, проверяющая, является ли введенный символ цифрой
* @param symbol - переменная, хранящая символ, который проходит проверку на цифру
* @return 1 - если символ является цифрой
* @return 0 - если символ не является цифрой
*/
int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9') return 1;
	return 0;
}
/**
* @brief IsMinus() - функция, проверяющая, является ли введенный символ знаком Минус
* @param symbol - переменная, хранящая символ, который проходит проверку на знак Минус
* @return 1 - если символ является знаком Минус
* @return 0 - если символ не является знаком Минус
*/
int IsMinus(char symbol) {
	if(symbol == '-') return 1;
	return 0;
}
/**
* @brief IsSpace() - функция, проверяющая, является ли введенный символ Пробелом
* @param symbol - переменная, хранящая символ, который проходит проверку на Пробел
* @return 1 - если символ является Пробелом
* @return 0 - если символ не является Пробелом
*/
int IsSpace(char symbol) {
	if(symbol == ' ') return 1;
	return 0;
}
/**
* @brief IsPoint() - функция, проверяющая, является ли введенный символ Точкой
* @param symbol - переменная, хранящая символ, который проходит проверку на Точку
* @return 1 - если символ является Точкой
* @return 0 - если символ не является Точкой
*/
int IsPoint(char symbol) {
	if(symbol == '.') return 1;
	return 0; 
}
/**
* @brief IsCorrectSymbol() - функция, проверяющая, является ли введенный символ корректным для работы программы
* @param symbol - переменная, хранящая символ, который проходит проверку на корректность
* @return 1 - если символ является корректным для ввода
* @return 0 - если символ не является корректным для ввода
*/
int IsCorrectSymbol(char symbol) {
	if(IsDigit(symbol) || IsMinus(symbol) || IsSpace(symbol) || IsPoint(symbol)) return 1;
	return 0;
}
/**
* @brief IsSegment() - функция, проверяющая, является ли пара введенных вещественных чисел концами отрезка
* @param a - переменная, хранящая вещественное число и являющаяся началом отрезка
* @param b - переменная, хранящая вещественное число и являющаяся концом отрезка
* @return 1 - если конец отрезка строго больше начала, т.е. пара чисел 
* @return 0 - в противном случае
*/
int IsSegment(double a, double b) {
	if(a < b) return 1;
	return 0;
}
/**
* @brief GetNumber() - функция, обрабатывающая массив символов входного потока и конвертирующая их в число
* @param positive - переменная, хранящая 0 или 1 и показывающая, является ли возвращаемое число отрицательным или положительным соответственно
* @return положительное число, если positive равен 1
* @return отрицательное число, если positive равен 0
*/
double GetNumber(int positive) {
	//! Целая часть возвращаемого числа
	//!@code 
	//! double whole_part
	//! @endcode
	double whole_part    = 0;
	//! Десятичная часть возвращаемого числа
	//! @code
	//! double decimal_part
	//! @endcode
	double decimal_part  = 0;
	//! Счетчик дробных разрядов возвращаемого числа
	//! @code
	//! int count_decimal
	//! @endcode
	int    count_decimal = 0;
	//! Промежуточная переменная для записи десятичной части, чтобы максимально избежать погрешности при работе с вещ. числами
	//! @code
	//! int empty
	//! @endcode
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
/**
* @brief GetMax() - фукнция, принимающая на вход два числа и возвращающая максимальное из них
* @param a первое число
* @param b второе число
* @return a - если a > b
* @return b - если b >= a
* @note в случае равенства чисел нам неважно, какое число возвращать, поэтому по умолчанию возвращается b
*/
double GetMax(double a, double b) {
	if(a > b) return a;
	return b;
}
/**
* @brief GetNumberSegments() - функция, работающая с массивом stream и возвращающая введенное число отрезков
* @return result - введенное пользователем число отрезков
*/
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
/**
* @brief SortSegments() - функция, сортирующая отрезки по возрастанию их начал. Используется сортировка Insertion Sort
* @param segments_conut количество отрезков, которые требуется отсортировать
*/
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
/**
* @brief ConvertToSegments() - функция, преобразующая символы входного потока в числа, обозначающие концы и начала отрезка
* @param index_segments Текущий инденкс. В соответствующие ячейки массивов starts и ends запишутся начало и конец отрезка соответственно
*/
void ConvertToSegments(int index_segments) {
	index_stream = 0;
	if(token = stream[index_stream]) {
		if(IsDigit(token) || IsMinus(token)) {
			while(token = stream[index_stream++]) {
				if(!IsCorrectSymbol(token)) {
					std::cerr << "ERROR: invalid character!" << std::endl;
					exit(1);
				}
			}
		}
		else {
			std::cerr << "ERROR: segment enteres incorrectly!" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "ERROR: segments doesn't entered" << std::endl;
		exit(1);
	}
	index_stream = 0;
	int flag = 0;
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
			flag = 1;
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
	if(!flag) {
		std::cerr << "ERROR: segment's end doesn't endtered!" << std::endl;
		exit(1);
	}
	if(!IsSegment(number1, number2)) {
		std::cerr << "ERROR: the beginning of the segment must be less than the end!" << std::endl;
		exit(1);
	}
	else {
		starts[index_segments] = number1;
		ends[index_segments]   = number2;
	}
}
/**
* @brief SolutionToConxole() - функция, в который реализован основной алгоритм поиска обьединенных отрезков
* @note Результат функции выводится на консоль
* @param segments_count Количество введенных пользователем отрезков
*/
void SolutionToConsole(int segments_count) {
	std::cout << "\nRESULT:\n" << std::endl;
	double glob_start = starts[0];
	double glob_end   = ends[0];
	int    count      = 1;
	if(segments_count == 1) {
		std::cout << count << ") " << glob_start << " " << glob_end << std::endl;
	}
	else {
		for(int i = 1; i < segments_count; i++) {
			if(starts[i] <= glob_end) {
				glob_end = GetMax(glob_end, ends[i]);
			}
			
			else {
				std::cout << count++ << ") " << glob_start << " " << glob_end << std::endl;
				glob_start = starts[i];
				glob_end   = ends[i];
			}
		}
		std::cout << count << ") " << glob_start << " " << glob_end << std::endl;
	}
}
/**
* @brief SolutionToFile() - функция, в которой реализован основной алгоритм поиска обьединенных отрезков
* @note Результат функции записывается в файл
* @param nametofile Название файла, куда запишется результат функции
* @param segments_count Количество введенных пользователем отрезков
*/
void SolutionToFile(const char * nametofile, int segments_count) {
	std::ofstream ToFile(nametofile);
	ToFile << "RESULT:\n" << std::endl;
	double glob_start = starts[0];
	double glob_end   = ends[0];
	int    count      = 1;
	if(segments_count == 1) {
		ToFile << count << ") " << glob_start << " " << glob_end << std::endl;
	}
	else {
		for(int i = 1; i < segments_count; i++) {
			if(starts[i] <= glob_end) {
				glob_end = GetMax(glob_end, ends[i]);
			}
			else {
				ToFile << count++ << ") " << glob_start << " " << glob_end << std::endl;
				glob_start = starts[i];
				glob_end   = ends[i];
			}
		}
		ToFile << count << ") " << glob_start << " " << glob_end << std::endl;
	}
	ToFile.close();
}
/**
* @brief GetResultFromConsole() - функция, осуществляющая ввод данных пользователем с консоли и вывод также в консоль
*/
void GetResultFromConsole() {  // из консоли в консоль
	std::cin.getline(stream, STREAM_SIZE - 1); // водим вол-во отрезков
	int NUM_SEGMENTS = GetNumberSegments();
	starts = new double[NUM_SEGMENTS];
	ends   = new double[NUM_SEGMENTS];
	for(int i = 0; i < NUM_SEGMENTS; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		ConvertToSegments(i);
	}
	SortSegments(NUM_SEGMENTS);
	SolutionToConsole(NUM_SEGMENTS);
	delete[] starts;
	delete[] ends;
}
/**
* @brief GetResultFromConsole() - перегруженная функция, осуществляющая ввод данных пользователем с консоли и вывод в файл
* @param nametofile Название файла, в который будет записан результат выполнения функции
* @param is_name_file Флаг, обозначающий, ввел ли пользователь название файла или нет
* @note Если is_name_file = 1, значит пользователь выбрал конкретный файл, в который будет записан результат выполения функции.
* Если is_name_file = 0, значит пользователь не вводил название файла ,запись будет осуществленная в файл DefaultFile.txt по умолчанию
*/
void GetResultFromConsole(const char * nametofile, int is_name_file) { // из консоли в файл
	std::cin.getline(stream, STREAM_SIZE - 1); // водим вол-во отрезков
	int NUM_SEGMENTS = GetNumberSegments();
	starts = new double[NUM_SEGMENTS];
	ends   = new double[NUM_SEGMENTS];
	for(int i = 0; i < NUM_SEGMENTS; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		ConvertToSegments(i);
	}
	SortSegments(NUM_SEGMENTS);

	if(is_name_file) {
		std::ifstream check(nametofile);
		if(check.is_open()) {
			check.close();
			SolutionToFile(nametofile, NUM_SEGMENTS);
			std::cout << "-COMMAND COMPLETED, CHECK " << nametofile << "-" << std::endl;
			delete[] starts;
			delete[] ends;
		}
		else {
			check.close();
			delete[] starts;
			delete[] ends;
			std::cerr << "ERROR: file for output not found, You must create it or enter right!" << std::endl;
			exit(1);
		}
	}
	else {
		SolutionToFile(nametofile, NUM_SEGMENTS);
		std::cout << "-COMMAND COMPLETED, CHECK " << nametofile << "-" << std::endl;
		delete[] starts;
		delete[] ends;
	}
}
/**
* @brief GetResultFromFile() - функция, осуществляющая ввод данных пользователем с файла и вывод в консоль
* @param namefromfile Название файла, из которого будет производиться чтение данных
*/
void GetResultFromFile(const char * namefromfile) { // из файла в консоль
	std::ifstream FromFile(namefromfile);
	if(FromFile.is_open()) {
		FromFile.getline(stream, STREAM_SIZE - 1);
		int NUM_SEGMENTS = GetNumberSegments();
		starts = new double[NUM_SEGMENTS];
		ends   = new double[NUM_SEGMENTS];
		for(int i = 0; i < NUM_SEGMENTS; i++) {
			FromFile.getline(stream, STREAM_SIZE - 1);
			ConvertToSegments(i);
		}
		if(!FromFile.eof()) {
			std::cerr << "ERROR: number of strings more than number of segments!" << std::endl;
			exit(1);
		}
		SortSegments(NUM_SEGMENTS);
		SolutionToConsole(NUM_SEGMENTS);
		FromFile.close();
		delete[] starts;
		delete[] ends;
	}
	else {
		FromFile.close();
		delete[] starts;
		delete[] ends;
		std::cout << "ERROR: file for input not found, You must create it or enter right!" << std::endl;
		exit(1);
	}
}
/**
* @brief GetResultFromFile() - перегруженная функция, осуществляющая ввод данных пользователем с файла и вывод в файл
* @param namefromfile Названия файла, с которого будет производиться чтение данных
* @param nametofile  Название файла, в который будет производиться запись данных
* @param is_name_file Флаг, обозначающий, ввел ли пользователь название файла для вывода данных или нет
* @note Если is_name_file = 1, значит пользователь выбрал конкретный файл, в который будет записан результат выполения функции.
* Если is_name_file = 0, значит пользователь не вводил название файла ,запись будет осуществленная в файл DefaultFile.txt по умолчанию
*/
void GetResultFromFile(const char * namefromfile, const char * nametofile, int is_name_file) { // из файла в файл
	std::ifstream FromFile(namefromfile);
	if(FromFile.is_open()) {
		FromFile.getline(stream, STREAM_SIZE - 1);
		int NUM_SEGMENTS = GetNumberSegments();
		starts = new double[NUM_SEGMENTS];
		ends   = new double[NUM_SEGMENTS];
		for(int i = 0; i < NUM_SEGMENTS; i++) {
			FromFile.getline(stream, STREAM_SIZE - 1);
			ConvertToSegments(i);
		}
		if(!FromFile.eof()) {
			std::cerr << "ERROR: number of strings more than number of segments!" << std::endl;
			exit(1);
		}
		SortSegments(NUM_SEGMENTS);

		if(is_name_file) {
			std::ifstream check(nametofile);
			if(check.is_open()) {
				check.close();
				SolutionToFile(nametofile, NUM_SEGMENTS);
				std::cout << "-COMMAND COMPLETED, CHECK " << nametofile << "-" << std::endl;
				delete[] starts;
				delete[] ends;
			}
			else {
				check.close();
				delete[] starts;
				delete[] ends;
				std::cerr << "ERROR: file for output not found, You must create it or enter right!" << std::endl;
				exit(1);
			}
		}
		else {
			SolutionToFile(nametofile, NUM_SEGMENTS);
			std::cout << "-COMMAND COMPLETED, CHECK " << nametofile << "-" << std::endl;
			delete[] starts;
			delete[] ends;
		}
	}
	else {
		FromFile.close();
		delete[] starts;
		delete[] ends;
		std::cerr << "ERROR: file for input not found, You must create it or enter right!" << std::endl;
		exit(1);
	}
}