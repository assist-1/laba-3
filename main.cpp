#include <iostream>
#include <cstring>
#include "functions.h"

int main(int argument, char ** str)
{
    switch (argument)
    {
        case 1:
            if (rd()) exit(1);
            sl(0, "NO");
            break;
        case 3:
            if (!strcmp("--tofile", str[1]))
            {
                if (rd()) exit(1);
                sl(1, str[2]);
            }
            else if (!strcmp("--fromfile", str[1]))
            {
                if (rd_f(str[2])) exit(1);
                sl(0, "NO");
            }
            else
            {
                std::cerr << "<<< INCORRECT FLAGS >>>\n";
                exit(1);
            }
            break;
        case 5:
            if (!strcmp("--fromfile", str[1]) &&
                !strcmp("--tofile", str[3]))
            {
                if (rd_f(str[2])) exit(1);
                sl(1, str[4]);
            }
            else if (!strcmp("--fromfile", str[3]) &&
                     !strcmp("--tofile", str[1]))
            {
                if (rd_f(str[4])) exit(1);
                sl(1, str[2]);
            }
            else {
                std::cerr << "<<< INCORRECT FLAGS >>>\n";
                exit(1);
            }
            break;
        default:
            std::cerr << "<<< INCORRECT FLAGS >>>\n";
            exit(1);
    }
    exit(0);
}