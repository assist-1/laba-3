#include <iostream>
#include "funcs.h"

#define ERR {std::cerr << "\nThere must be only one keys \'--tofile\' or \'--fromfile\'.\n";\
			return EXIT_FAILURE;}

int main (int argc, char **argv)
{
  bool ff=false, tf=false, dff=false, dtf=false;
	char *fdir="./input.txt", *tdir="./output.txt";
	const char *key1 = "--tofile", *key2 = "--fromfile", *key = "--"; 
    
	for (int i=1; i<argc; ++i)
  {
    if (comp(key,argv[i]))
    {
      if (comp(argv[i],key1))
      {
        if (tf) ERR
        tf=true;
        dtf=true; dff=false;
      }
      else if (comp(argv[i],key2))
      {
        if (ff) ERR
        ff=true;
        dff=true; dtf=false;
      }
      else
      {
        std::cerr << "\nWrong keys.\n"; 
        return EXIT_FAILURE;
      }
    }
    else if (dtf!=dff)
    {
      if (dtf)
      {
        tdir = argv[i];
        dtf = false;
      }
      else if (dff)
      {
        fdir = argv[i];
        dff = false;
      }
    }
    else
    {
      std::cerr << "\nWrong keys.\n"; 
      return EXIT_FAILURE;
    }
  }
  func(tf, tdir, ff, fdir);

	return EXIT_SUCCESS;
}