#include <iostream> 
#include <fstream> 
 
double* start; 
double* end; 
double* data; 
int l; 
 
int read_cin() { 
    std::cin >> l; 
 
    start = new double[l]; 
    end = new double[l]; 
 
    for (int i = 0; i < l; ++i) 
        std::cin >> start[i] >> end[i]; 
 
    data = new double[2 * l]; 
    for (int i = 0; i < l; i++) { 
        data[i] = start[i]; 
    } 
    for (int i = l; i < 2 * l; i++) { 
        data[i] = end[i - l]; 
    } 
    return 0; 
} 
 
int read_file() { 
    std::ifstream file("fromfile.txt"); 
    if (!file.is_open()) { 
        std::cout << "Error" << std::endl; 
        return 1; 
    } 
 
    file >> l; 
 
    start = new double[l]; 
    end = new double[l]; 
 
    for (int i = 0; i < l; ++i) 
        file >> start[i] >> end[i]; 
 
    data = new double[2 * l]; 
    for (int i = 0; i < l; i++) { 
        data[i] = start[i]; 
    } 
    for (int i = l; i < 2 * l; i++) { 
        data[i] = end[i - l]; 
    } 
    return 0; 
} 
 
int poisk(double* M, int r, double zn) 
{ 
    int i; 
    for (i = 0;i < r;i++) 
    { 
        if (M[i] == zn) return i; 
    } 
    return -1; 
} 
 
 
double func(int to_file) { 
    double temp; 
    for (int j = 0; j < 2 * l; j++) { 
        for (int i = 1; i < 2 * l; i++) { 
            if (data[i] < data[i - 1]) { 
                temp = data[i]; 
                data[i] = data[i - 1]; 
                data[i - 1] = temp; 
            } 
        } 
    } 
 
    int counter = 0; 
    double top = -1; 
    double low = 100000; 
    int flag = 0; 
    for (int i = 0; i < 2 * l; i++) { 
        if (poisk(start, l, data[i]) != -1) { 
            flag += 1; 
        } 
        else if ((poisk(end, l, data[i]) != -1)) { 
            flag -= 1; 
        } 
        if (flag == 1) { 
            low = std::min(low, data[i]); 
 
        } 
        if (flag == 0) { 
            top = std::max(top, data[i]); 
            if (to_file == 0) { 
                std::cout << low << " " << top << std::endl; 
            } 
            else { 
                std::ofstream out; 
                out.open("tofile.txt", std::ios_base::app); 
                out << low << " " << top << '\n'; 
                out.close();     
            } 
            counter += 1; 
            low = 10000000; 
            top = -1; 
        } 

    } 
    delete[] start; 
    delete[] end; 
    delete[] data; 
    if (counter == l) { 
        std::cout << "Nothing was found"; 
        return 1; 
    } 
    return 0;
}
