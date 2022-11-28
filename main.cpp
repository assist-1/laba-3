#include <iostream>
#include <fstream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
const int STR_MAX_LEN = 1024;
const int STR_MAX_QUANTITY = 100;
char str[STR_MAX_LEN];
char c;
int counter = 0;
char a[STR_MAX_QUANTITY][STR_MAX_LEN];
int mas[STR_MAX_QUANTITY];
int k =0;
int flag =0;
int id[STR_MAX_QUANTITY];
int t1,t2;
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Nothing was entered";
        return 0;
    }
    if( (!strcmp(argv[1],"--tofile") && argc == 2)|| (argc == 4 && !strcmp(argv[1],"--fromfile") && !strcmp(argv[3],"--tofile")))
    {
       cout << "Enter your lines. Declimantion is '/'" << endl; 
       while (c !='/' )
       {
        if (counter == STR_MAX_LEN || k == STR_MAX_QUANTITY)
        {
            cout << "BUFFER OVERFLOW!";
            return -1;
        }
        c = cin.peek();
        if (flag == 1 && c !='\n' && c!=' ' && c!='/'){
            cout << "Error of entry!";
            return -1;
        }
        if (c =='\n')
        {
            if(flag == 0)
            {
                c = ' ';
            }
        }
        if (flag == 0){
        str[counter] = c;}
        else {flag = 0; counter -=1;}
        if (c == '.')
        {
            mas[k] = counter;
            std::copy(str,str + counter+1,a[k]);
            flag = 1;
            k+=1;
            counter = -1;
        }
        counter+=1;
        cin.ignore();
       }
    }
    if((!strcmp(argv[1],"--fromfile") && argc == 3 && strcmp(argv[2],"--tofile")) || (argc == 4 && !strcmp(argv[1],"--fromfile") && !strcmp(argv[3],"--tofile")))
    {
        std::ifstream fin(argv[2]);
        while (!fin.eof())
       {
         if (counter == STR_MAX_LEN || k == STR_MAX_QUANTITY)
        {
            cout << "BUFFER OVERFLOW!";
            return -1;
        }
        c = fin.get();
        if (flag == 1 && c !='\n' && c!=' ' && c!=EOF){
            cout << "Error of entry!";
            return -1;
        }
        if (c =='\n')
        {
            if(flag == 0)
            {
                c = ' ';
            }
        }
        if (flag == 0){
        str[counter] = c;}
        else {flag = 0; counter -=1;}
        if (c == '.')
        {
            mas[k] = counter;
            std::copy(str,str + counter+1,a[k]);
            flag = 1;
            k+=1;
            counter = -1;
        }
        counter+=1;
       }
    }
    if(argc >=2 && k == 0){
        cout << "WRONG!! ENTER";
        return -1;

    }
    for (int i = 0; i < k; i++)
       {
        id[i] = i;
       }
       for(int i = 0; i < k-1; i++)
        for(int j = 0; j < k - i - 1; j++)
        {
        if(mas[j] > mas[j+1])
        {
            
            t1 = mas[j];
            mas[j] = mas[j + 1];
            mas[j + 1] = t1;
            t2 = id[j];
            id[j] = id [j+1];
            id[j+1] = t2;
        }
        }
        std::ofstream fout("out.txt");
        char nine[STR_MAX_QUANTITY][STR_MAX_LEN];
        int sun = 0;
        int j =0;
        int q = 0;
        for (int i = 0; i< k; i++)
        {
            fout<< a[id[i]] << endl;
            if (i == (k-1))
            {
                while(a[id[i]][j]!='.')
                {
                    if(a[id[i]][j] != ' ' && a[id[i]][j] != '.'){
                    nine[sun][q] = a[id[i]][j];
                    q+=1;
                    }
                    else {sun+=1; q=0;}
                    j+=1;
                    
                }

            }
        }
        fout.close();
        std::ofstream out("NINE.txt");
        for (int q=sun; q>=0;q--)
        {
            out << nine[q];
            if (q == 0) out << '.';
            else out << ' ';

        }
        out.close();
    return 0;
}