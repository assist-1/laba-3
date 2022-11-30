#include <iostream>
#include <fstream>
#include "Header.h"
int n;
int func(char **argv) {
    std::ofstream fout;
    std::ifstream fin;
    double arr[n][2];
    if (tofile==true && fromfile==false){
        fout.open(argv[2]);
        std::cout<<"Введите число отрезков"<<std::endl;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            std::cin>>arr[i][0];
            std::cin>>arr[i][1];
        }
    }
    else if (fromfile==true && tofile==false){
        fin.open(argv[2]);
        fin>>n;
        for(int i=0;i<n;i++)
        {
            fin>>arr[i][0];
            fin>>arr[i][1];
        }
    }
    else if (fromfile==true && tofile==true){
        fin.open(argv[2]);
        fin>>n;
        for(int i=0;i<n;i++)
        {
            fin>>arr[i][0];
            fin>>arr[i][1];
        }
        fout.open(argv[4]);
    }
    bool b=true;
    while(b)
    {
        b=false;
        for(int i=1;i<n;i++)
        {
            if (arr[i][0]<arr[i-1][0])
            {
                double p=arr[i][0];
                double p2=arr[i][1];
                arr[i][0]=arr[i-1][0];
                arr[i][1]=arr[i-1][1];
                arr[i-1][0]=p;
                arr[i-1][1]=p2;
                b=true;
            }
        }
    }
    double nach=arr[0][0];
    double kon=arr[0][1];
    bool flag=false; //проверка прыжок
    bool nichego=true; //единичных отрезков
    for(int i=1;i<n;i++){
        if (arr[i][0]<kon)//слияние
            {
                kon=std::max(arr[i][1],kon);
                nichego=false;
                flag=false;
            }
        else  //разрыв
        {
            if (flag!=true && nichego==false){ //если не перепыгнули
                if (tofile==true)
                    fout<<nach<<" "<<kon<<" "<<std::endl; //первый отрезок
                else if (fromfile==true)
                    std::cout<<nach<<" "<<kon<<" "<<std::endl;
                nach=arr[i][0];
                kon=arr[i][1];
            }
            else { //если перепрыгнули
                nach=arr[i][0];
                kon=arr[i][1];
            }
            if (arr[i][1]<arr[i+1][0] && i!=n-1) //проверка на единичные отрезки/разрыв после еще одного разрыва
            {
                i++;
                nach=arr[i][0];
                kon=arr[i][1];
                flag=true;
            }
        }
    }
    if (nichego==true)
    {
        std::cout<<"Nothing was found";
        return 1;
    }
    if (flag==false)
    {
        if (tofile==true)
            fout<<nach<<" "<<kon<<std::endl; //не обрабат последняя строку пишем вручную
        else if (fromfile==true)
            std::cout<<nach<<" "<<kon<<std::endl;
        return 0;
    }
   /* for(int i=0;i<n;i++)
    {
        std::cout<<arr[i][0]<<" ";
        std::cout<<arr[i][1]<<" " << std::endl;
    }*/
    fout.close();
    fin.close();
    return 0;
}
