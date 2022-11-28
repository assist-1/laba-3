#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) {
    bool mtofile = 0;
    bool mfromfile = 0;
    std::string tofile_name;
    std::string fromfile_name;
    std::ofstream nine("NINE.txt");
    char arr9[1000] = {'0'};
    int count9 = 0;

    if (argc != 1) {
        if (std::strcmp(argv[1], "--tofile") == 0) {
            mtofile = 1;
            if (argc != 2) {
                tofile_name = (argv[2]);
                if (argc != 3) {
                    if (std::strcmp(argv[3], "--fromfile") == 0) {
                        mfromfile = 1;
                        if (argc != 4) {
                            fromfile_name = (argv[4]);
                        } else {
                            std::cout << "Input Error" << std::endl; 
                            return -1;
                        }
                    }
                }
            } else {
                tofile_name = "solution.txt";
            }
        } else if (std::strcmp(argv[1], "--fromfile") == 0) {
            mfromfile = 1;
            if (argc != 2) {
                fromfile_name = (argv[2]);
                if (argc != 3) {
                    if (std::strcmp(argv[3], "--tofile") == 0) {
                        mtofile = 1;
                        if (argc != 4) {
                            tofile_name = (argv[4]);
                        } else {
                            tofile_name = "solution.txt";
                        }
                    }
                }
            } else {
                std::cout << "Input Error" << std::endl; 
                return -1;
            }
        }
    }

    
    if (mfromfile) {
        std::ifstream fromfile(fromfile_name);
        if (!fromfile) {
            std::cout << "Input Error" << std::endl; 
            return -1;
        }
        char symb[10000] = {'0'};
        symb[0] = fromfile.get();
        symb[1] = fromfile.get();
        int i = 2;
        while (1) {
            if (fromfile.eof()) {
                break;
            }
            symb[i] = fromfile.get();
            i++;
        } //for (int j = 0; j < i-1; j++) {std::cout << symb[j];}
        int points_check[100] = {0};
        int counter_points = 1;
        points_check[0] = -1;
        for (int j = 0; j < i-1; j++) {if (symb[j] == '.') {points_check[counter_points] = j; counter_points++;}} //for (int j = 0; j < 10; j++) {std::cout << points_check[j] << " ";} std::cout << std::endl;
        int counter_len = 0;
        int senten_len[100] = {0};
        int l = 0;
        for (int j = 0; j < i-1; j++) {
            if ((symb[j] != '.') && (symb[j] != '\n') && (symb[j] != ' ')) {
                counter_len++;
            } else if (symb[j] == ' ') {
                if (symb[j-1] != '.') {
                    counter_len++;
                }
            } else if (symb[j] == '.') {
                senten_len[l] = counter_len;
                l++;
                counter_len = 0;
            }
        } //for (int j = 0; j < 10; j++) {std::cout << senten_len[j] << " ";} std::cout << std::endl;
        int positions[100] = {0};
        for (int j = 0; j < l; j++) {
            int index_min = 0;
            for (int k = 0; k < l; k++) {
                if (senten_len[k] < senten_len[index_min]) {index_min = k;}
            }
            positions[j] = index_min+1;
            senten_len[index_min] = 10000;
        } //for (int j = 0; j < 10; j++) {std::cout << positions[j] << " ";} std::cout << std::endl;

        if (mtofile) {
            std::ofstream tofile(tofile_name);
            if (!tofile) {
                std::cout << "Input Error" << std::endl; 
                return -1;
            }
            for(int j = 1; j < l+1; j++) {
                int k = positions[j-1];
                for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        tofile << "";
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        tofile << "";
                    } else {tofile << symb[p];}
                }
                tofile << '.' << std::endl;
                if (j == l) {
                    for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        continue;
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        continue;
                    } else {arr9[count9] = symb[p]; count9++;}}
                    arr9[count9] = ' ';
                    int space_check[100] = {0};
                    int counter_space = 1;
                    space_check[0] = -1;
                    for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {
                        if (arr9[n] == ' ') {space_check[counter_space] = n; counter_space++;}}
                    
                    space_check[counter_space] = (points_check[k] - points_check[k-1] - 1);
                    //for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {std::cout << space_check[n] << " ";} std::cout << std::endl;
                    for (int d = 0; d < counter_space + 1; d++) {
                        for (int q = space_check[counter_space - d - 1]+1; q < space_check[counter_space - d]; q++) {
                            nine << arr9[q];
                        }
                        nine << " ";
                    }
                }
            }
        } else {
            for(int j = 1; j < l+1; j++) {
                int k = positions[j-1];
                for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        std::cout << "";
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        std::cout << "";
                    } else {std::cout << symb[p];}
                }
                std::cout << '.' << std::endl;
                if (j == l) {
                    for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        continue;
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        continue;
                    } else {arr9[count9] = symb[p]; count9++;}}
                    arr9[count9] = ' ';
                    int space_check[100] = {0};
                    int counter_space = 1;
                    space_check[0] = -1;
                    for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {
                        if (arr9[n] == ' ') {space_check[counter_space] = n; counter_space++;}}
                    
                    space_check[counter_space] = (points_check[k] - points_check[k-1] - 1);
                    //for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {std::cout << space_check[n] << " ";} std::cout << std::endl;
                    for (int d = 0; d < counter_space + 1; d++) {
                        for (int q = space_check[counter_space - d - 1]+1; q < space_check[counter_space - d]; q++) {
                            nine << arr9[q];
                        }
                        nine << " ";
                    }
                }
            }
        }
    }
    if (!mfromfile) {
        char symb[10000] = {'0'};
        symb[0] = std::cin.get();
        symb[1] = std::cin.get();
        int i = 2;
        while ((symb[i-2] == '\n' && symb[i-1] == '\n') != 1) {
            symb[i] = std::cin.get();
            i++;
        } //for (int j = 0; j < i-1; j++) {std::cout << symb[j];}
        int points_check[100] = {0};
        int counter_points = 1;
        points_check[0] = -1;
        for (int j = 0; j < i-1; j++) {if (symb[j] == '.') {points_check[counter_points] = j; counter_points++;}} //for (int j = 0; j < 10; j++) {std::cout << points_check[j] << " ";} std::cout << std::endl;
        int counter_len = 0;
        int senten_len[100] = {0};
        int l = 0;
        for (int j = 0; j < i-1; j++) {
            if ((symb[j] != '.') && (symb[j] != '\n') && (symb[j] != ' ')) {
                counter_len++;
            } else if (symb[j] == ' ') {
                if (symb[j-1] != '.') {
                    counter_len++;
                }
            } else if (symb[j] == '.') {
                senten_len[l] = counter_len;
                l++;
                counter_len = 0;
            }
        } //for (int j = 0; j < 10; j++) {std::cout << senten_len[j] << " ";} std::cout << std::endl;
        int positions[100] = {0};
        for (int j = 0; j < l; j++) {
            int index_min = 0;
            for (int k = 0; k < l; k++) {
                if (senten_len[k] < senten_len[index_min]) {index_min = k;}
            }
            positions[j] = index_min+1;
            senten_len[index_min] = 10000;
        } //for (int j = 0; j < 10; j++) {std::cout << positions[j] << " ";} std::cout << std::endl;

        if (mtofile) {
            std::ofstream tofile(tofile_name);
            if (!tofile) {
                std::cout << "Input Error" << std::endl; 
                return -1;
            }
            for(int j = 1; j < l+1; j++) {
                int k = positions[j-1];
                for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        tofile << "";
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        tofile << "";
                    } else {tofile << symb[p];}
                }
                tofile << '.' << std::endl;
                if (j == l) {
                    for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        continue;
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        continue;
                    } else {arr9[count9] = symb[p]; count9++;}}
                    arr9[count9] = ' ';
                    int space_check[100] = {0};
                    int counter_space = 1;
                    space_check[0] = -1;
                    for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {
                        if (arr9[n] == ' ') {space_check[counter_space] = n; counter_space++;}}
                    
                    space_check[counter_space] = (points_check[k] - points_check[k-1] - 1);
                    //for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {std::cout << space_check[n] << " ";} std::cout << std::endl;
                    for (int d = 0; d < counter_space + 1; d++) {
                        for (int q = space_check[counter_space - d - 1]+1; q < space_check[counter_space - d]; q++) {
                            nine << arr9[q];
                        }
                        nine << " ";
                    }
                }
            }
        } else {
            for(int j = 1; j < l+1; j++) {
                int k = positions[j-1];
                for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        std::cout << "";
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        std::cout << "";
                    } else {std::cout << symb[p];}
                }
                std::cout << '.' << std::endl;
                if (j == l) {
                    for (int p = points_check[k-1]+1; p < points_check[k]; p++) {
                    if ((symb[p-1] == '.') && (symb[p] == ' ')) {
                        continue;
                    } else if ((symb[p-1] == '.') && (symb[p] == '\n')) {
                        continue;
                    } else {arr9[count9] = symb[p]; count9++;}}
                    arr9[count9] = ' ';
                    int space_check[100] = {0};
                    int counter_space = 1;
                    space_check[0] = -1;
                    for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {
                        if (arr9[n] == ' ') {space_check[counter_space] = n; counter_space++;}}
                    
                    space_check[counter_space] = (points_check[k] - points_check[k-1] - 1);
                    //for (int n = 0; n < (points_check[k] - (points_check[k-1]+1)); n++) {std::cout << space_check[n] << " ";} std::cout << std::endl;
                    for (int d = 0; d < counter_space + 1; d++) {
                        for (int q = space_check[counter_space - d - 1]+1; q < space_check[counter_space - d]; q++) {
                            nine << arr9[q];
                        }
                        nine << " ";
                    }
                }
            }
        }
    }
}
