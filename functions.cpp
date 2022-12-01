
#include "functions.hpp"
#include <iostream>
#include <fstream>

int count;
double *points;

int read() {
    std::cin >> count;
    if (std::cin.fail() || count <= 0) {
            std::cerr << ">>> Fail:( <<<\n";
            return 1;
        }
    points = new double[count*2];
    
    for(int i = 0; i < count*2; i+=2){
        double k;
        double l;
        std::cin >> k;
        k = 2*k*100;
        std::cin >> l;
        l = 2*l*100 + 1;
        points[i] = k;
        points[i+1] = l;
        if (std::cin.fail()) {
            std::cerr << ">>> Wrong points <<<\n";
            delete[] points;
            return 1;
        }
    }
    return 0;
}

int read(char* file_name) {
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open()) {
        std::cerr << ">>> Where is the file? <<<\n";
        return 1;
    }

    file >> count;
    if (file.fail() || count <= 0) {
        std::cerr << ">>> Fail:( <<<\n";
        return 1;
    }

    points = new double[count*2];

    for (int i = 0; i < count*2; i+=2) {
        file >> points[i];
        points[i] = points[i]*200;
        file >> points[i+1];
        points[i+1] = points[i+1]*200+1;
        if (file.fail()) {
            std::cerr << ">>> Wrong points <<<\n";
            return 1;
        }
    }
    file.close();
    return 0;
}

void sort() {
    int t = count*2;
    while(t--){
        bool swapp = false;
        for(int i = 0; i < t; i++){
            if(points[i] > points[i+1]){
                std::swap(points[i], points[i+1]);
                swapp = true;
                
            }
        }
        if(swapp == false) break;
    }
}


int solve(int file, const char file_name[]){
    sort();
    if(!file){
        int cnt = 0;
        for(int i = 0; i < count*2; ++i){
            int y = cnt;
            if(int(points[i]) % 2 == 0){
                cnt+=1;
            }
            if(int(points[i]) % 2 == 1){
                cnt-=1;
            }
            if(y==0 and cnt==1){
                std::cout << points[i]/200 << " ";
            }
            if(y==1 and cnt==0){
                std::cout << (points[i]-1)/200 << "\n";
            }
        }
    }
    else{
        std::ofstream file;
        file.open(file_name, std::ios_base::app);
        if (!file.is_open()) {
                std::cerr << ">>> Ou, where is our file?:( <<<\n";
                return 1;
        }
        int cnt = 0;
        for(int i = 0; i < count*2; ++i){
            int y = cnt;
            if(int(points[i]) % 2 == 0){
                cnt+=1;
            }
            if(int(points[i]) % 2 == 1){
                cnt-=1;
            }
            if(y==0 and cnt==1){
                file << points[i]/200 << " ";
            }
            if(y==1 and cnt==0){
                file << (points[i]-1)/200 << "\n";
            }
        
        }
        file.close();
    }
    return 0;
    
}


