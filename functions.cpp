#include <iostream>

const int STREAM_SIZE = 10;

char stream[STREAM_SIZE];
int  index_stream;
char token;


int IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9')
		return 1;
	return 0;
}

int IsMinus(char symbol) {
	if(symbol == '-')
		return 1;
	return 0;
}

void GetResultFromConsole() {
	const int NUM_SEGMENTS;
	std::cin >> NUM_SEGMENTS;
	float segments[NUM_SEGMENTS][2];

	for(int i = 0; i < 0; i++) {
		std::cin.getline(stream, STREAM_SIZE - 1);
		index_stream = 0;
		while(token = stream[index_stream++]) {
			if(IsMinus(token)) {
				if(IsDigit(stream[index_stream])) {

				}
				else {
					std::cerr << "ERROR: segment enteres incorrectly!" << std::endl;
					exit(1);
				}
			}

		}
	}


}


void ReadingFromFile() {

}