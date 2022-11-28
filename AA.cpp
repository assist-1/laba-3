#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;


void ff(std::string txt, char* adr, int flag) {
    int n = 50;
    std::string AT[n];
    int i = 0;
    int j = 0;
    while (i<txt.size()) {
        if (txt[i]=='.')  {
            AT[j] = txt.substr(0, i+1);
            if ( txt[i+1]== ' ') {txt = txt.substr(i+2, txt.size()-i);} //i+2 reason - space
            else {txt = txt.substr(i+1, txt.size()-i);}
            ++j;
            i = 0;
        }
        else if ((txt[i] + txt[i+1] == '\n')) {
            txt[i] = ' ';
            ++i;
        }
        ++i;
    }

    for (int A = 0; A < n - 1; ++A) {
        for (int B = A + 1; B < n; B++) {
            if (AT[B].size() < AT[A].size()) {
                std::string temp = AT[A];
                AT[A] = AT[B];
                AT[B] = temp;
            }
        }
    }
    std::string s[j];
    int k = 0;
    for (int A = 0; A < n; ++A) {
        if (AT[A].size() != 0) {
            s[k] = AT[A];
            ++k; 
        }
    }

    if (flag == 1) {
        for (int z = 0; z < j; ++z) {
            cout << s[z] << endl;
        }
    }
    else if (flag == 2) {
        std::ofstream fout(adr);
        for (int z = 0; z < j; ++z)   fout << s[z]+ "\n";
        fout.close();
    }

    std::ofstream fout("NINE.txt");
    int x = 0;
    int y = 0;
    std::string nine[s[j-1].size()];
    while (x<s[j-1].size()) {
        if ((s[j-1][x]==' ') or (s[j-1][x]=='.'))  {
            nine[y] = s[j-1].substr(0, x);
            s[j-1] = s[j-1].substr(x+1, s[j-1].size()-x);
            ++y;
            x = 0;
        }
        ++x;
    }
    for (int z = y; z > -1; --z)   fout << nine[z]+ " ";
    fout.close();
}


int main (int argc, char** argv) {
    if (argc == 1) {
        cerr << "Nothing was read\n";
        return EXIT_FAILURE;
    }
    else if(argc==4) {
        cerr << "You must write adress to your file\n";
        return EXIT_FAILURE;
    }
    else {
        std::string flag = argv[1];
        std::string txt;

        if ((argc==5) && (flag == "--fromfile") && (std::string(argv[3]) == "--tofile")) {
            std::ifstream f(argv[2]);
            if (f.is_open())
            {
                while (getline(f, txt)) {}
            }
            f.close();
            ff(txt, argv[4], 2);
        }

        else if (argc==3) {
            if (flag == "--fromfile") {
                std::string adr = argv[2];

                std::ifstream f(adr);
                if (f.is_open())
                {
                    while (getline(f, txt)) {}
                }
                else {cerr << "Wrong adress to file\n"; return EXIT_FAILURE;}
                f.close();
                ff(txt, argv[2], 1);
            }

            else if (flag == "--tofile") {
                cout << "WARNING: If you wrote something different from adress to file,\n this something will become the name of your new file.txt. \n It was your decision.\n";
                getline(cin, txt);
                ff(txt, argv[2], 2);
            }

            else if ((argv[1] != "--fromfile") && (argv[1] != "--tofile")) {cerr << "What do you mean by writing that instead of FLAG? 0_o\n"; return EXIT_FAILURE;}
        }
    }
    return EXIT_SUCCESS;
}