#include <iostream>
#include <fstream>
int func(int z,int t){
    int i=0;
    char c;
    std::ofstream fout;
    std::ifstream fin;
    fin.open("1.txt");
    fout.open("3.txt");
    while (i!=z-1) {
        c = fin.get();
        fout << c;
        if (c=='\n')
            i++;
    }
    c=0;
    while (c!='\n') {
        c=fin.get();
    }
    i++;
    while (i<=t) {
        char c = fin.get();
        fout << c;
        if (c=='\n')
            i++;
    }
    fin.close();
    fout.close();
    return 0;
}

int sort(int arr[],int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}


int obrabotka(int i,int arr[100]){
    int f,sum;
    sum=0;
    int p =0;
    char c = 0;
    f=0;
    std::ofstream fout;
    fout.open("1.txt");
    while (p!=2) {
        c = getchar();
        if (c=='\n' && p==0)
        {
            if (f==0)
            {
                fout << " ";
                sum++;
            }
            p++;
        }
        else if (c=='\n' && p==1)
        {
            p++;
        }
        else if (c=='.' || c=='!' || c=='?') {
            fout<<c;
            sum++;
            arr[i]=sum;
            i++;
            fout << std::endl;
            f=1;
            sum=0;
        }
        else if (c==' ' && f==1)
            f=0;
        else if(p==1){
            p=0;
            sum++;
            fout << c;
        }
        else {
            sum++;
            fout << c;
        }
    }
    fout.close();
    if (f==0 && c=='\n')
        return -1000000;
    return i;
}

int obrabotka2(int i,int arr[100],char*q){
    int f,sum;
    sum=0;
    int p;
    char c = 0;
    f=0;
    std::ofstream fout;
    std::ifstream fin;
    fout.open("1.txt");
    fin.open(q);
    while (!fin.eof()) {
        c = fin.get();
        if (c=='\n' && p==0)
        {
            if (f==0)
            {
                fout << " ";
                sum++;
            }
            p++;
        }
        else if (c=='\n' && p==1)
        {
            p++;
        }
        else if (c=='.' || c=='!' || c=='?') {
            fout<<c;
            sum++;
            arr[i]=sum;
            i++;
            fout << std::endl;
            f=1;
            sum=0;
        }
        else if (c==' ' && f==1)
            f=0;
        else if(p==1){
            p=0;
            sum++;
            fout << c;
        }
        else {
            sum++;
            fout << c;
        }
    }
    fout.close();
    fin.close();
    if (f==0 && c=='\n')
        return -1000000;
    return i;
}

int obrabotka1(int i,int arr[100],char*q){
    int f,sum;
    sum=0;
    char c = 0;
    f=0;
    int p=0;
    std::ofstream fout;
    std::ifstream fin;
    fout.open("1.txt");
    fin.open(q);
    while (!fin.eof()) {
        c = fin.get();
        if (c=='\n' && p==0)
        {
            if (f==0)
            {
                fout << " ";
                sum++;
            }
            p++;
        }
        else if (c=='\n' && p==1)
        {
            p++;
        }
        else if (c=='.' || c=='!' || c=='?') {
            fout<<c;
            sum++;
            arr[i]=sum;
            i++;
            fout << std::endl;
            f=1;
            sum=0;
        }
        else if (c==' ' && f==1)
            f=0;
        else if(p==1){
            p=0;
            sum++;
            fout << c;
        }
        else {
            sum++;
            fout << c;
        }
    }
    fout.close();
    fin.close();
    if (f==0 && c=='\n')
        return -1000000;
    return i;
}

int rabota(char arr1[],int arr[],int i,char*q) {
    int n=0;
    int j=0;
    int sum=0;
    int l=1;
    std::ifstream fin;
    std::ofstream oout;
    std::ofstream fout;
    fin.open("1.txt");
    fout.open(q);
    int z=0;
    while (n!=i)
    {
        char c=fin.get();
        if (c=='\n') {
            z++;
            if (sum == arr[j]) {
                for (int k = 0; k < sum; k++)
                    fout << arr1[k];
                n++;
                j++;
                fin.close();
                fout << std::endl;
                func(z,i-l);
                l++;
                z=0;
                fin.open("3.txt");
                oout.open("1.txt");
                oout << fin.rdbuf();
                fin.close();
                oout.close();
                fin.open("1.txt");
            }
            sum=0;
        }
        else {
            arr1[sum]=c;
            sum++;
        }
    }
    fin.close();
    fout.close();
    remove("1.txt");
    remove("3.txt");
    return 0;
}

int rabota2(char arr1[],int arr[],int i) {
    int n=0;
    int j=0;
    int sum=0;
    int l=1;
    std::ifstream fin;
    std::ofstream oout;
    std::ofstream fout;
    fin.open("1.txt");
    fout.open("123.txt");
    int z=0;
    while (n!=i)
    {
        char c=fin.get();
        if (c=='\n') {
            z++;
            if (sum == arr[j]) {
                for (int k = 0; k < sum; k++)
                    fout << arr1[k];
                n++;
                j++;
                fin.close();
                fout << std::endl;
                func(z,i-l);
                l++;
                z=0;
                fin.open("3.txt");
                oout.open("1.txt");
                oout << fin.rdbuf();
                fin.close();
                oout.close();
                fin.open("1.txt");
            }
            sum=0;
        }
        else {
            arr1[sum]=c;
            sum++;
        }
    }
    fin.close();
    fout.close();
    remove("1.txt");
    remove("3.txt");
    return 0;
}


int rabota1(char arr1[],int arr[],int i,char*q) {
    int n=0;
    int j=0;
    int sum=0;
    int l=1;
    std::ifstream fin;
    std::ofstream oout;
    std::ofstream fout;
    fin.open("1.txt");
    fout.open(q);
    int z=0;
    while (n!=i)
    {
        char c=fin.get();
        if (c=='\n') {
            z++;
            if (sum == arr[j]) {
                for (int k = 0; k < sum; k++)
                    fout << arr1[k];
                n++;
                j++;
                fin.close();
                fout << std::endl;
                func(z,i-l);
                l++;
                z=0;
                fin.open("3.txt");
                oout.open("1.txt");
                oout << fin.rdbuf();
                fin.close();
                oout.close();
                fin.open("1.txt");
            }
            sum=0;
        }
        else {
            arr1[sum]=c;
            sum++;
        }
    }
    fin.close();
    fout.close();
    remove("1.txt");
    remove("3.txt");
    return 0;
}