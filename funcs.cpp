#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


class Segm
{
    public: 
      float beg;
      float end;
      Segm ();
     ~Segm ();
      void print(bool);
      void copy(const Segm&);
      bool get (bool); 
};

Segm Sget, *m;
int ns=0;
std::ifstream fin; 
std::ofstream fout;

Segm::Segm () 
  :beg(1), end(0) {};
Segm::~Segm ()
  {beg=1, end=0;}
void Segm::print(bool to) 
  {
    if (to) fout << beg << " " << end << endl;
    else cout << beg << " " << end << endl;
  }
void Segm::copy(const Segm& obj) 
  {beg=obj.beg; end=obj.end;}
bool Segm::get (bool from) 
  {
    if(from) return ((fin >> Sget.beg)&&(fin >> Sget.end));
    return ((cin >> Sget.beg)&&(cin >> Sget.end));
  }

bool comp (const char *a, const char *b)
{
  for (int i=0; a[i]!='\0'; ++i)
  {
    if (a[i]!=b[i])
    {
      return false;
    }
  }
  return true;
}

bool not_correct(const Segm& a)
{
  if (a.end<a.beg) return 1;
  return 0;
}

int compare(const Segm& a, const Segm& b)
{
  if (not_correct(a)) return 0;
  if ((a.beg<=b.beg)&&(a.end>=b.end)) return -1;
  if ((a.beg<=b.beg)&&(a.end>=b.beg)) return 1;
  if ((a.beg<=b.end)&&(a.end>=b.end)) return 2;
  if ((b.beg<=a.beg)&&(b.end>=a.beg)) return 3;
  return 0;
}

bool connect(Segm& a, Segm& b)
{
  switch (compare (a,b))
  {
    case 0: return false;
    case 1: a.end=b.end; b.beg=a.beg; return true;
    case 2: a.beg=b.beg; return true;
    case 3: a.copy(b); return true;
    default: return true;
  }
}

void put ()
{
  int flag=0; Segm buf1, buf2;
  for (int i=0; i<ns; ++i)
  {
    if (not_correct(m[i])) {flag=1; break;}
    if (flag) 
    {buf2.copy(m[i]); m[i].copy(buf1); buf1.copy(buf2);}
    if ((Sget.beg<m[i].beg)&&!flag) 
    {++flag; buf1.copy(m[i]); m[i].copy(Sget);}
  }
  if (flag) m[ns++].copy(buf1);
  else m[ns++].copy(Sget);
}

void func(bool tf, const char* tdir, bool ff, const char* fdir)
{
  unsigned int n;
  if (ff) 
  {
    fin.open(fdir);
    if (!fin.is_open())
    {
      cerr << "Wrong input file directory.\n";
      exit(EXIT_FAILURE);
    }
    fin >> n;
  }
  else cin >> n;
  if(n==1)
  {
    cerr << "Nothing found.\n";
    exit(EXIT_FAILURE);
  }
  if (n>10000)
  {
    cerr<< "Too much segments.\n";
    exit (EXIT_FAILURE);
  }
  m = new Segm[n];
  for (int i=0; i<n; ++i)
  {
    int flag=0;
    if (!Sget.get(ff))
    {
      cerr<< "Not enough numbers.\n";
      exit(EXIT_FAILURE);
    }
    if (not_correct(Sget))
    {
      cerr << "Wrong segment in " << (i+1) << " line." << endl;
      exit (EXIT_FAILURE);
    }
    for (int j=0; j<ns; ++j)
    {
      if(connect(m[j],Sget)) flag =1;
    }
    if (!flag) put();
  }
  for (int i=1; i<ns; ++i)
  {
    if (m[i-1].beg==m[i].beg) m[i-1].end=m[i-1].beg-1;
  }
  
  if(tf)
  {
    fout.open(tdir,std::ofstream::trunc);
    if (!fout.is_open())
    {
      cerr << "Wrong output file directory!\n";
      exit(EXIT_FAILURE);
    }
  }
  for (int i=0; i<ns; ++i)
  {
    if (!not_correct(m[i]))
    {
      m[i].print(tf);
    }
  }
  delete[] m;
  
  if (ff) fin.close();
  if (tf) fout.close();
}