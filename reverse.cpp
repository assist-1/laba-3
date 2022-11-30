#include <iostream>
#include <cstring>
#include "lb5.h"

using std::cin;
using std::cout;
using std::endl;

void reverse(int arr[], char arr2[], int last){
    cout << "Reversed string:";
    int len = arr[last-1];
    int start = 0;
    int finish = 0;
    int count = 0;
    start = 0;
    for (int j = 0; j<strlen(arr2); j++) {
        if ((arr2[j] == '.') || (arr2[j] == '!') || (arr2[j] == '?')) {
            finish = j;
            if (finish - start + 1 == len) {
                count = finish;
                for (int l = finish; l >= start; l--){
                    if ((arr2[l] == ' ') || (arr2[l] >= 65 && arr2[l] <= 90)){
                        int m = l;
                        for (int y = m; y < count + 1; y++){
                            if ((arr2[y] != ' ') && (arr2[y] != '.') && (arr2[y] != '?') && (arr2[y] != '!') && (arr2[y] != ',')){
                                cout << arr2[y];
                            }
                        }
                        cout << ' ';
                        count = l-1;
                    }
                }
            }
            else{
                start = j + 2;
            }
        }
    }
}
