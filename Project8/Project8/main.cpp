#include "So.h"
int main (int argc, char** argv){
    if (argc > 1)
    {
        if ((strcmp(argv[1], "--fromfile") == 0) && (argc == 2)) 
            fromfile();
        
        
        if ((strcmp(argv[1], "--tofile") == 0) && (argc == 2)) 
            tofile();
        

        if (((strcmp(argv[1], "--tofile") == 1)&&(strcmp(argv[1], "--fromfile") == 1)) && (argc == 2))
            std::cerr << "you have entered an unknown flag" << std::endl;


        if ((((strcmp(argv[1], "--fromfile") == 0) && (strcmp(argv[2], "--tofile") == 0)) ||
            ((strcmp(argv[2], "--fromfile") == 0) && (strcmp(argv[1], "--tofile") == 0))) && (argc == 3))
        {
            TofileFromfile();
        }


        if ((((strcmp(argv[1], "--fromfile") == 1) || (strcmp(argv[2], "--tofile") == 1)) ||
            ((strcmp(argv[2], "--fromfile") == 1) || (strcmp(argv[1], "--tofile") == 1))) && (argc == 3))
        {
            std::cerr << "you have entered an unknown flag" << std::endl;
        }
        
        if (argc > 3)
            std::cerr << "You entered too many flags" << std::endl;
    
    }


    else
    {
        std::cout << "The flag is missing" << "\n";
    }
    system("pause");

    return 0;
}