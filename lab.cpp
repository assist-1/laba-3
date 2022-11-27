#include <iostream>
#include <cstring>
#include <fstream>

void read_from_terminal(char* text);
void read_from_file(FILE* fp, char *filename, char* text);
void sort_and_out(const char *text, char *tofile);
int get_point_coord(const char *text, int *points);
int find_min(int *lenght, int counter);
void print(int points, const char *text);

int main(int argc, char** argv) {
    FILE* fp;
    char tofile_name[32] = {0};
    int fromfile = 0;
    char text[1024];
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
			if ((std::strcmp(argv[i], "--tofile")) == 0) {
                if (i + 1 >= argc || (fp = fopen(argv[i+1], "r")) == NULL) {
                    if (i + 1 >= argc || argv[i+1][0] == '-') {
                        std::ofstream oFile ( "tofile.txt" );
                        std::strcpy(tofile_name, "tofile.txt");
                    } 
                    else {
                        std::ofstream oFile (argv[i+1]);
                        std::strcpy(tofile_name, argv[i+1]);
                    }
                } else {
                    std::strcpy(tofile_name, argv[i+1]);
                    fclose(fp);
                }
			}
			else if ((std::strcmp(argv[i], "--fromfile")) == 0) {
				if (i + 1 >= argc || (fp = fopen(argv[i+1], "r")) == NULL) {
                    fromfile = -1;
                } else {
                    fromfile = i + 1;
                    fclose(fp);
                }
			}
		}
    }
    if (fromfile >= 0) {
        if (fromfile == 0) {
            read_from_terminal(text);
        } else {
            read_from_file(fp, argv[fromfile], text);
        }
        sort_and_out(text, tofile_name);
    } else {
        std::cout << "Incorrect file for reading\n";
    }
    return 0;
}

void read_from_terminal(char* text) {
    std::cout << "Enter text. \nTo mark the end of input, type '~' and press Enter.\n" << std::endl;
    std::cin.getline(text, 1024, '~');
}

void read_from_file(FILE* fp, char *filename, char* text) {
    int j = 0;
    fp = fopen(filename, "r");
    while ((text[j] = fgetc(fp)) != EOF) {
		j++;
	}
	text[j] = '\0';
    fclose(fp);
}

void sort_and_out(const char *text, char *tofile) {
    int counter;
    int points[128];
    int j;
    counter = get_point_coord(text, points);
    int flag;
    int lenght[128] = {0};
    for (int k = 0; k < counter; k++) {
        flag = 0;
        j = points[k] - 1;
        while (text[j - 1] != '.' && j != -1 && flag == 0) {
            j--;
            if (text[j - 1] == '.' && text[j] == ' ') {
                flag = 1;
                j++;
            }
        }
        for (int h = j; h < points[k] + 1; h++) {
            if (text[h] != '\n' && text[h] != ' ') {
                lenght[k]++;
            } 
        }
    }
    for (int l = 0; l < counter; l++) {
        j = find_min(lenght, counter);
        print(points[j], text);
        std::cout << '\n';
        lenght[j] = 900;
    }
}

int get_point_coord(const char *text, int *points) {
    int j = 0;
    int k = 0;
    for (j = 0; j < std::strlen(text); j++) {
        if (text[j] == '.') {
            points[k] = j;
            k++;
        }
    }
    return k;
}

int find_min(int *lenght, int counter) {
    int min = 0;
    for (int i = 1; i < counter; i++) {
        if (lenght[i] < lenght[min]) {
            min = i;
        }
    }
    return min;
}

void print(int points, const char *text) {
    int flag = 0;
    int j = points - 1;
    while (text[j - 1] != '.' && j != -1 && flag == 0) {
        j--;
        if (text[j - 1] == '.' && text[j] == ' ') {
            flag = 1;
            j++;
        }
    }
    for (int h = j; h < points + 1; h++) {
        if (text[h] == '\n') {
            //std::cout << ' ';
        } 
        else if (text[h] != '\n'){
            std::cout << text[h];
        }
    }
}