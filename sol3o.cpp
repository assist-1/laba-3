#include <iostream>
#include <fstream>
#include "func.h"

using std::cin;
using std::cout;
//using namespace std;

class start{
    private:
        int size = 0;
        float num[10000];
    public:
        start(){}

        void addToEnd(float tmp){
                num[size] = tmp;
                ++size;
            }

        void replaceNum(int i, float tmp){
                num[i] = tmp;
            }

        void insertNum(int i, float numb){
            float tmp1 = num[i];
            float tmp2;
            num[i] = numb;
            for(int j = i; j < size; ++j){
                tmp2 = num[j+1];
                num[j+1] = tmp1;
                tmp1 = tmp2;
                }
            ++size;
            }

        int sizeM(){
            return size;
            }

        float returnNum(int i){
            return num[i];
            }

        void deleteNum(int i){
            --size;
            for(int j = i; j < size; ++j)
                num[j] = num[j+1];
            }
    };

void sol3o(int argc, char *argv[]){
  std::ofstream fout;
  if(argc == 3)
    fout.open(argv[2]);
  else fout.open("output.txt");
  int amogus;
  cin >> amogus;
  if (amogus == 0){
    fout << "Nothing found\n";
  }else{
   start first;
   start second;
   double a, b;
   for(int i = 0; i < amogus; ++i){
       cin >> a >> b;

       if(first.sizeM() == 0){
           first.addToEnd(a);
           second.addToEnd(b);
           //cout << "Done addToEnd first time\n";
       }else
           {
           bool flag = false;
           for(int i = 0; i < first.sizeM(); ++i){
               if (b < first.returnNum(i)){
                       first.insertNum(i, a);
                       second.insertNum(i, b);
                       //cout << "Done insertNum less than first\n";
                       flag = true;
                       break;
                   }else if ((a < first.returnNum(i))&&(b > first.returnNum(i))){
                           first.replaceNum(i,a);
                           //cout << "Done replaceNum begin less\n";
                           if(b > second.returnNum(i)){
                               second.replaceNum(i, b);
                               //cout << "Done replaceNum end bigger\n";
                               }
                           flag = true;
                           break;
                       }
               }
           if (!flag){
               first.addToEnd(a);
               second.addToEnd(b);
               //cout << "Done addToEnd biggest\n";
               }
           flag = false;
           }
       }


   for (int i = 0; i < first.sizeM(); ++i){
       if ((first.returnNum(i) <= first.returnNum(i+1))&&(second.returnNum(i) > first.returnNum(i+1))){
           if(second.returnNum(i) >= second.returnNum(i+1)){
               first.deleteNum(i+1);
               second.deleteNum(i+1);
               //cout << "Done deleteNum next in previous\n";
           }else{
               first.deleteNum(i+1);
               second.replaceNum(i, second.returnNum(i+1));
               second.deleteNum(i+1);
               //cout << "Done deleteNum and replaceNum previous + next\n";
               }
       }
   }

   for(int i = 0; i < first.sizeM(); ++i)
       fout << first.returnNum(i) << " " << second.returnNum(i) << '\n';
   cout << "finished\n";
   fout.close();
 }
}
