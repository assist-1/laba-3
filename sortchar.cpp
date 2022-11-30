#include <iostream>
#include <cstring>
#include "lb5.h"

using std::cin;
using std::cout;
using std::endl;

void sorting(int arr[], char arr2[], int len){
    int start = 0;
    int finish = 0;
    for (int i = 0; i < len; i++){
        start = 0;
        for (int j = 0; j<strlen(arr2); j++){
            if ((arr2[j] == '.') ||(arr2[j] == '!') || (arr2[j] == '?')){
                finish = j;
                if (finish - start + 1 == arr[i]){
                    for (int l = start; l <= finish; l++){
                        cout << arr2[l];
                    }
                    cout << endl;
                }
                else{
                    start = j + 2;
                }
            }
        }
    }
}
