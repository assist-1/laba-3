#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char* argv[]) {
    int n, flag;
    if(argc == 1) {
        std::cin >> n;
        flag = 1;
    } else if (argc == 3 && strcmp("--fromfile", argv[1])== 0){
        std::ifstream file (argv[2]);
        file >> n;
        flag = 2;
        file.close();
    } else if (argc == 5 && strcmp("--fromfile", argv[3])== 0 && strcmp("--tofile", argv[1])== 0) {
        std::ifstream file(argv[4]);
        file >> n;
        flag = 3;
        file.close();
    } else if ((argc == 3 && strcmp("--tofile", argv[1])== 0)) {
        std::cin >> n;
        flag = 4;
    } else if (argc == 5 && strcmp("--fromfile", argv[1])== 0 && strcmp("--tofile", argv[3])== 0){
        std::ifstream file (argv[2]);
        file >> n;
        flag = 5;
        file.close();
    } else {
        std::cerr << "Please enter --fromfile or --tofile and the way to them. \nFor example: --fromfile 1.txt --tofile 2.txt" << std::endl;
        exit(0);
    }
    float t1,t2;
    float** a = new float* [n];
    for(int i = 0; i < n; i++)
        a[i] = new float [2];
    for(int i = 0; i < n;i++){
        a[i][0] = 0;
        a[i][1] = 0;
    }
    if(flag == 1 || flag == 4) {
        for (int i = 0; i < n; i++) {
            std::cin >> a[i][0] >> a[i][1];
            if (a[i][0] >= a[i][1]) {
                std::cerr << "Error! Cut off incorrectly" << std::endl;
                exit(0);
            }
        }
    } else if (flag == 2 || flag == 5){
        std::ifstream file (argv[2]);
        file >> n;
        for (int i = 0; i < n; i++) {
            file >> a[i][0] >> a[i][1];
            if (a[i][0] >= a[i][1]) {
                std::cerr << "Error! Cut off incorrectly" << std::endl;
                exit(0);
            }
        }
        file.close();
    } else {
        std::ifstream file(argv[4]);
        file >> n;
        for (int i = 0; i < n; i++) {
            file >> a[i][0] >> a[i][1];
            if (a[i][0] >= a[i][1]) {
                std::cerr << "Error! Cut off incorrectly" << std::endl;
                exit(0);
            }
        }
        file.close();
    }
    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < n - 1; j++){
            if (a[j][0] > a[j+1][0]){
                t1 = a[j][0];
                t2 = a[j][1];
                a[j][0] = a[j+1][0];
                a[j][1] = a[j+1][1];
                a[j+1][0] = t1;
                a[j+1][1] = t2;
            }
        }
    }
    int count = 0, curCount = 0;
    float curBegin = a[0][0], curEnd= a[0][1];
    for(int i = 0; i < n-1; i++){
        if(a[i+1][0] > curEnd){
            a[count][0] = curBegin;
            a[count][1] = curEnd;
            count++;
            curBegin = a[i+1][0];
            curEnd = a[i+1][1];
            if(curCount == 0){
                count--;
            }
            curCount = 0;
        } else {
            curEnd = std::max(curEnd, a[i+1][1]);
            curCount++;
        }
    }
    a[count][0] = curBegin;
    a[count][1] = curEnd;
    count++;
    if(curCount == 0){
        count--;
    }
    if(flag == 1 || flag == 2) {
        std::cout << std::endl;
        if(count == 0){
            std::cout << "NOTHING FOUND" << std::endl;
        } else {
            for (int i = 0; i < count; i++) {
                std::cout << a[i][0] << " " << a[i][1] << std::endl;
            }
        }
    } else if (flag == 3 || flag == 4){
        std::ofstream file(argv[2]);
        if(count == 0){
            file << "NOTHING FOUND" << std::endl;
        } else {
            for (int i = 0; i < count; i++) {
                file << a[i][0] << " " << a[i][1] << std::endl;
            }
        }
        file.close();
    } else {
        std::ofstream file(argv[4]);
        if(count == 0){
            file << "NOTHING FOUND" << std::endl;
        } else {
            for (int i = 0; i < count; i++) {
                file << a[i][0] << " " << a[i][1] << std::endl;
            }
        }
        file.close();
    }
    for (int i = 0; i < n;i++)
        delete [] a[i];
    delete [] a;
    return 0;
}
